//
// Created by seik on 2019-04-26.
//

#ifndef BS_HIGHCREDITACCOUNT_H
#define BS_HIGHCREDITACCOUNT_H

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {

    int specialRate;

public:
    enum{A=1, B, C};
    HighCreditAccount(const String accountNumber, const String name, int money, int interRate, int specialRate);
    ~HighCreditAccount();
    virtual bool deposit(const int &money);
    virtual void showAccInfo() const;

};


#endif //BS_HIGHCREDITACCOUNT_H
