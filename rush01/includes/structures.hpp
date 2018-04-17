#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP
#include <string>
#include <vector>

typedef struct
{
	std::string	type;
	std::string	release;
	std::string	ICantComeUpWithAnAppropriateName;
}osInfo;

typedef struct
{
	std::string					name;
	std::string					valDesc;
	bool						drawGraph;
	int							curVal;
	std::vector<std::string>	text;

}dataModule;

#endif


