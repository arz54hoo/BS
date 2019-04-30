//
// Created by seik on 2019-04-26.
//

#ifndef BS_NORMALACCOUNT_H
#define BS_NORMALACCOUNT_H

#include "Account.h"

class NormalAccount : public Account {

    int interRate;

public:
    NormalAccount(const String accountNumber, const String name, int money, int interRate);
    ~NormalAccount();
    virtual bool deposit(const int &money);
    virtual void showAccInfo() const;
};


#endif //BS_NORMALACCOUNT_H
