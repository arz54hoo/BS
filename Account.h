//
// Created by seik on 2019-04-26.
//

#ifndef BS_ACCOUNT_H
#define BS_ACCOUNT_H

#include "String.h"
class Account {
private:
    String accountNumber;
    String name;
    int balance;


public:
    Account(const String accountNumber, const String name, const int &money);
    virtual bool deposit(const int &money);
    bool withdraw(const int &money);
    virtual void showAccInfo() const;
    String getName() const;
};



#endif //BS_ACCOUNT_H
