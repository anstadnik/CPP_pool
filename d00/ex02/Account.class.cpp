#include "Account.class.hpp"
#include <time.h>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	/* std::locale::global(std::locale("ja_JP.utf8")); */
    std::time_t t = std::time(nullptr);
    char mbstr[100];
    if (std::strftime(mbstr, sizeof(mbstr), "[%Y%m%d_%H%M%S]", std::localtime(&t))) {
        std::cout << mbstr;
    }
}

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

int		Account::checkAmount( void ) const
{
	static int	_checkAmounts_amount;
	_checkAmounts_amount++;
	return (this->_amount);
}

void	Account::displayAccountsInfos( void )
{
	//found
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" <<
		getTotalAmount() << ";deposits:" << getNbDeposits() <<
		";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account( int initial_deposit ):_accountIndex(getNbAccounts()), _amount(initial_deposit)
{
	//found
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" <<
		checkAmount();
	std::cout << ";created" << std::endl;
}

Account::~Account( void )
{
	//found
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" <<
		checkAmount();
	std::cout << ";closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	//found
	this->_nbDeposits++;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << 
		checkAmount() << ";deposit:" << deposit << ";amount:" << 
		checkAmount() + deposit << ";nb_deposits:" << this->_nbDeposits << std::endl;
	this->_amount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	//found
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << 
		checkAmount() << ";withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused" << std::endl;
		return (false);
	}
	else
	{
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;
		std::cout << withdrawal << ";amount:" << this->_amount <<
			";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
		return (true);
	}
}

void	Account::displayStatus( void ) const
{
	//found
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" <<
		checkAmount() << ";deposits:" << this->_nbDeposits <<
		";withdrawals:" << this->_nbWithdrawals << std::endl;
}
