#include "Account.hpp"
#include <iostream>
#include <vector>

int main()
{
    typedef std::vector<Account::t> AccountVector;
    typedef std::vector<int> TransactionVector;

    int const inits[] = {42, 54, 957, 432, 1234, 0, 754, 16576};
    size_t const size = sizeof(inits) / sizeof(inits[0]);
    AccountVector   accounts(inits, inits + size);

    int const deposits[] = { 5, 765, 564, 2, 87, 23, 9, 20 };
    TransactionVector depositsVector(deposits, deposits + size);

    int const withdrawals[] = { 321, 34, 657, 4, 76, 275, 657, 7654 };
    TransactionVector withdrawalsVector(withdrawals, withdrawals + size);

    Account::displayAccountsInfos();
    for (size_t i = 0; i < size; i++)
        accounts[i].displayStatus();
    for (size_t i = 0; i < size; i++)
        accounts[i].makeDeposit(depositsVector[i]);
    Account::displayAccountsInfos();
    for (size_t i = 0; i < size; i++)
        accounts[i].makeWithdrawal(withdrawalsVector[i]);
    Account::displayAccountsInfos();
    for (size_t i = 0; i < size; i++)
        accounts[i].displayStatus();

    return 0;
}