//
// Created by seik on 2019-04-26.
//

#include "Account.h"

Account::Account(const String accountNumber, const String name, const int &money) :balance(money) {

    this->accountNumber = accountNumber;
    this->name = name;
}


bool Account::deposit(const int &money) {

    if (money <= 0)
        throw LowerMoneyException(money);
    balance += money;

    return true;
}

bool Account::withdraw(const int &money) {

    if(money<=0)
        throw LowerMoneyException(money);
    if(money > balance)
        throw WithdrawException(balance);
    balance -= money;
    return true;
}

void Account::showAccInfo() const {

    cout << "["<< name << "]"<< endl;
    cout <<"계좌번호 : "<< accountNumber<< endl;
    cout << "잔    액 : "<<balance<<"원"<<endl;
}

String Account::getName() const {

    return name;
}