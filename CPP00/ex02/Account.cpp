#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _accountIndex = _nbAccounts - 1;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
    std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";closed" << std::endl;
}

int Account::getNbAccounts(void) 
{
    return _nbAccounts;
}

int Account::getTotalAmount(void) 
{
    return _totalAmount;
}

int Account::getNbDeposits(void) 
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals(void) 
{
    return _totalNbWithdrawals;
}

void Account::makeDeposit(int deposit)
{
    std::cout << "index:" << _accountIndex
            << ";p_amount:" << _amount
            << ";deposit:" << deposit;
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount
            << ";nb_deposits:" << _nbDeposits << std::endl;

}

bool Account::makeWithdrawal(int withdrawal)
{
    std::cout << "index:" << _accountIndex
            << ";p_amount:" << _amount;
    if (withdrawal > _amount)
            std::cout << ";withdrawal:refused" << std::endl;
    else
    {
        _amount -= withdrawal;
        _totalAmount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << ";amount:" << _amount
                << ";nb_deposits:" << _nbDeposits << std::endl;
    }
    return true;
}

int Account::checkAmount(void) const
{
    return 0;
}

void Account::displayStatus(void) const
{
    std::cout << "index:" << _accountIndex
            << ";amount:" << _amount
            << ";deposits:" << _nbDeposits
            << ";withdrawals:" << _nbWithdrawals << std::endl;
    return ;
}

void Account::displayAccountsInfos(void)
{
    std::cout << "accounts:" << getNbAccounts()
            << ";total:" << getTotalAmount()
            << ";deposits:" << getNbDeposits()
            << ";witdrawals:" << getNbWithdrawals() << std::endl;
}

void Account::_displayTimestamp(void)
{
        
    std::time_t t = std::time(0);
    std::cout << "[" << t << "] ";
}