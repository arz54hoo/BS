//
// Created by seik on 2019-04-26.
//

#ifndef BS_BANKINGSYSTEM_H
#define BS_BANKINGSYSTEM_H

#include "Account.h"
class BankingSystem {

    Account * accountList[100];
    int accnum;

public:
    enum {MAKE = 1, DEPOSIT, WITHDRAW, SHOW, FINISH};
    enum {NORMAL = 1, HIGH};

    BankingSystem();
    void showMenu();
    void makeAccount();
    void deposit();
    void withdraw();
    void showAllAccInfo();
    void finish();

protected:
    void makeNormalAccount();
    void makeHighAccount();
};


#endif //BS_BANKINGSYSTEM_H
