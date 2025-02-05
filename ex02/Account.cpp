#include "Account.hpp"

#include <iomanip>
#include <iostream>

int		Account::_nbAccounts = 0;

int		Account::_totalAmount = 0;

int		Account::_totalNbDeposits = 0;

int		Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) : _accountIndex( _nbAccounts ), _amount( initial_deposit ), _nbDeposits( 0 ), _nbWithdrawals( 0 ) {

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;

    _nbAccounts++;
    _totalAmount += _amount;
}

Account::~Account( void ) {

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;

    _nbAccounts--;
    _totalAmount -= _amount;
}

void	Account::makeDeposit( int deposit ) {

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit;

    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;

    std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal;

    if ( withdrawal > _amount ) {

        std::cout << ";refused" << std::endl;
        return false;
    }

    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;

    std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;

    return true;
}

int		Account::checkAmount( void ) const {

    return _amount;
}

void	Account::displayStatus( void ) const {

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::displayAccountsInfos( void ) {

    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void   Account::_displayTimestamp( void ) {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);
    std::cout << "[" << (now->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << (now->tm_mon + 1)
              << std::setw(2) << std::setfill('0') << now->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << now->tm_hour
              << std::setw(2) << std::setfill('0') << now->tm_min
              << std::setw(2) << std::setfill('0') << now->tm_sec << "] ";
}
