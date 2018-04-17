#include "GetData.hpp"
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/time.h>
#include <sstream>
#include <vector>
#include <iostream>

#include <array>

GetData::GetData(void) {}

GetData::~GetData(void) {}

GetData &GetData::getData(void)
{
	static GetData	getData;

	return (getData);
}

void	GetData::update(void)
{
	char	buf[256];
	size_t	len = sizeof(buf);

	gethostname(buf, 256);
	hostname = buf;
	username = getlogin();

	{
		int	arr[] = {CTL_HW, HW_MACHINE};
		sysctl(arr, 2, &buf, &len, NULL, 0);
		os.ICantComeUpWithAnAppropriateName = buf;
	}

	{
		int arr[2] = {CTL_KERN, KERN_OSRELEASE};
		sysctl(arr, 2, buf, &len, NULL, 0);
		os.release = buf;
	}

	{
		int	arr[] = {CTL_KERN, KERN_OSTYPE};
		sysctl(arr, 2, buf, &len, NULL, 0);
		os.type = buf;
	}

	{
		time_t	tm = std::time(NULL);
		time = asctime(localtime(&tm));
	}
}

void	GetData::updateTop(void)
{
	std::vector<std::string>	top = getTop();
	{
		LOAD.name = "LOAD";
		double tmp = std::stod(top[2].substr(top[2].find_first_of("1234567890")));

		int	arr1[] = {CTL_HW, HW_MEMSIZE};
		int	max;
		size_t	len = sizeof(int);
		sysctl(arr1, 2, &max, &len, NULL, 0);

		LOAD.valDesc = std::to_string(tmp);

		int	arr3[] = {CTL_HW, HW_NCPU};
		int	cores;
		len = sizeof(int);
		sysctl(arr3, 2, &cores, &len, NULL, 0);

		LOAD.drawGraph = true;
		LOAD.curVal = 100 * static_cast<double>(tmp) / cores;
		LOAD.text = std::vector<std::string>();
		LOAD.text.push_back(top[2]);
	}

	{
		CPU.name = "CPU";
		CPU.curVal = std::stoi(top[3].substr(top[3].find_first_of("1234567890")));
		CPU.valDesc = std::to_string(CPU.curVal) + "%";
		CPU.drawGraph = true;
		CPU.text = std::vector<std::string>();
		CPU.text.push_back(top[3]);
	}

	{
		RAM.name = "RAM used";
		int	arr[] = {CTL_HW, HW_MEMSIZE};
		long	int	max;
		size_t	len = sizeof(long int);
		sysctl(arr, 2, &max, &len, NULL, 0);
		max /= 1024 * 1024;
		RAM.curVal = 100 * std::stod(top[6].substr(top[6].find_first_of("1264567890"))) / max;
		RAM.valDesc = std::to_string(std::stoi(top[6].substr(top[6].find_first_of("1264567890")))) + "/" + std::to_string(max);
		RAM.drawGraph = true;
		RAM.text = std::vector<std::string>();
		RAM.text.push_back(top[6]);
	}

	otherInfo.clear();
	otherInfo.push_back(top[0]);
	otherInfo.push_back(top[4]);
	otherInfo.push_back(top[5]);
	otherInfo.push_back(top[7]);
	otherInfo.push_back(top[8]);
}

std::vector<std::string>	GetData::getTop(void) const
{
	std::array<char, 128> buffer;
	std::string result;
	std::shared_ptr<FILE> pipe(popen("top", "r"), pclose);
	if (!pipe) throw std::runtime_error("popen() failed!");
	while (!feof(pipe.get())) {
		if (fgets(buffer.data(), 128, pipe.get()) != nullptr)
			result += buffer.data();
		if (result.find("Disks") != std::string::npos)
			break;
	}
	result = result.substr(0, result.find('\n', result.find("Disks")));
	std::vector<std::string>	ret;
	for (size_t	i = 0; ;)
	{
		size_t	end = result.find('\n', i);
		if (end == std::string::npos)
			break;
		ret.push_back(result.substr(i, end - i));
		i = end + 1;
	}
	return (ret);
}

const std::string	&GetData::getHostname(void) const
{
	return (hostname);
}

const std::string	&GetData::getUsername(void) const
{
	return (username);
}

const osInfo		&GetData::getOsInfo(void) const
{
	return (os);
}

const std::string	&GetData::getTime(void) const
{
	return (time);
}

const dataModule	&GetData::getRAM(void) const
{
	return (RAM);
}

const dataModule	&GetData::getLOAD(void) const
{
	return (LOAD);
}

const dataModule	&GetData::getCPU(void) const
{
	return (CPU);
}

const std::vector<std::string>		&GetData::getOtherInfo(void) const
{
	return (otherInfo);
}
