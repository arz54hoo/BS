//
// Created by seik on 2019-04-26.
//

#ifndef BS_BANKINGCOMMONDECL_H
#define BS_BANKINGCOMMONDECL_H

#include <iostream>
#include <cstring>
#include <conio.h>
using namespace std;
const int ARRMAXLEN = 10;

class BankingExeption
{
private:
    int data;

public:
    virtual void showExceptionLog() const = 0;

};

class WithdrawException : public BankingExeption
{
private:
    int data;

public:
    WithdrawException(int data): data(data){}
    virtual void showExceptionLog(void) const {

        cout << "예금된 금액보다 적은 금액을 출금요청해주세요."<< endl;
        cout << "현재 잔액 : "<<data<<endl;

    }
};

class LowerMoneyException : public BankingExeption{

private:
    int data;

public:
    LowerMoneyException(int data):data(data){ }
    virtual void showExceptionLog() const{

        cout << data<<"원을 요청하셨습니다. 최소 0보다 큰 금액을 입력해주세요."<<endl;
    }

};

#endif //BS_BANKINGCOMMONDECL_H
