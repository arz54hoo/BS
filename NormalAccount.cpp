//
// Created by seik on 2019-04-26.
//

#include "NormalAccount.h"
#include "BankingCommonDecl.h"

NormalAccount::NormalAccount(const String accountNumber, const String name, int money, int interRate)
:Account(accountNumber,name,money), interRate(interRate)
{}

NormalAccount::~NormalAccount() {}

bool NormalAccount::deposit(const int &money) {

    if(!Account::deposit(money))
        return false;
    if(!Account::deposit((int)(money * (interRate/100.0f))))
        return false;

    return true;
}

void NormalAccount::showAccInfo() const {

    Account::showAccInfo();
    cout << "이    율 : "<<interRate<<"%"<<endl;
}