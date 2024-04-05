#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor
Account::Account(int initialDeposit) {
    // Initialize account balance with initial deposit
    this->_amount = initialDeposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;
    this->_accountIndex = _nbAccounts;

    // Update the total amount of accounts
    _totalAmount += this->_amount;
    _displayTimestamp();
    std::cout << "index:" << _nbAccounts << ";amount:" << this->_amount << ";created" << std::endl;
    _nbAccounts++;
}

// Destructor
Account::~Account() {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
    _nbAccounts--;
    _totalAmount -= this->_amount;
}

// Private member function to display the current timestamp
void Account::_displayTimestamp() {
    time_t now = time(0);
    struct tm* timeinfo = localtime(&now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeinfo);
    std::cout << buffer;
}

// Public member function to get the total amount of all accounts
int Account::getTotalAmount() {
    return Account::_totalAmount;
}

// Public member function to get the number of accounts
int Account::getNbAccounts() {
    return Account::_nbAccounts;
}

// Public member function to get the number of deposits
int Account::getNbDeposits() {
    return Account::_totalNbDeposits;
}

// Public member function to get the number of withdrawals
int Account::getNbWithdrawals() {
    return Account::_totalNbWithdrawals;
}

// Public member function to make a deposit
void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit;
    this->_amount += deposit;
    _totalAmount += deposit;
    this->_nbDeposits++;
    _totalNbDeposits++;
    std::cout << ";amount:" << this->_amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

// Public member function to make a withdrawal
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:";
    if (this->_amount >= withdrawal) {
        this->_amount -= withdrawal;
        _totalAmount -= withdrawal;
        this->_nbWithdrawals++;
        _totalNbWithdrawals++;
        std::cout << withdrawal << ";amount:" << this->_amount << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
        return true;
    } else {
        std::cout << "withdrawal:refused" << std::endl;
        return false;
    }
}

int Account::checkAmount() const {
    return this->_amount;
}

// Public member function to display the status of the account
void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex << ";";
    std::cout << "amount:" << this->_amount << ";";
    std::cout << "deposits:" << this->_nbDeposits << ";";
    std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

// Public member function to display the status of all accounts
void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts() << ";";
    std::cout << "total:" << getTotalAmount() << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}