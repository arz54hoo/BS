//
// Created by seik on 2019-04-26.
//

#include "BankingSystem.h"
#include "BankingCommonDecl.h"
#include "HighCreditAccount.h"

BankingSystem::BankingSystem() : accnum(0)//, accountList(100),
{}

void BankingSystem::showMenu() {

    //system("cls");

    cout<< "========== Banking System =========="<< endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입    금"<<endl;
    cout<<"3. 출    금"<<endl;
    cout<<"4. 전체고객 잔액조회"<<endl;
    cout<<"5. 프로그램 종료"<<endl;
    cout << ">> ";
}

void BankingSystem::makeAccount() {

    int choice;

    cout<<endl<<"1. 보통예금계좌"<<endl;
    cout<<"2. 신용신뢰계좌"<<endl;
    cout << "개설하실 계좌를 선택하세요 : ";
    cin>>choice;
    cout <<endl;

    switch (choice)
    {
        case BankingSystem::NORMAL:
            makeNormalAccount();
            break;
        case BankingSystem::HIGH:
            makeHighAccount();
            break;
        default:
            break;
    }
}

void BankingSystem::makeNormalAccount() {

    char accountNumber[50];
    String name;
    int money;
    int interRate;

    cout << "[보통예금계좌]" << endl;
    cout << "계 좌 번 호 : ";   cin >> accountNumber;
    cout << "고   객   명 : ";  cin >> name;
    cout << "입금하실금액 : ";  cin >> money;
    cout << "이       율 : ";  cin >> interRate;
    accountList[accnum++] = new NormalAccount(accountNumber, name, money,interRate);
    cout << "계좌 개설을 성공했습니다."<<endl;

}

void BankingSystem::makeHighAccount(){

    char accountNumber[50];
    String name;
    int money;
    int interRate;
    int specialRate;

    cout << "[신용신뢰계좌]" << endl;
    cout << "계 좌 번 호 : ";   cin >> accountNumber;
    cout << "고   객   명 : ";  cin >> name;
    cout << "입금하실금액 : ";  cin >> money;
    cout << "이       율 : ";  cin >> interRate;
    cout << "고 객 등 급 (1toA, 2toB, 3toC) : "; cin>> specialRate;
    accountList[accnum++] = new HighCreditAccount(accountNumber, name, money,interRate,specialRate);
    cout << "계좌 개설을 성공했습니다."<<endl;

}

void BankingSystem::deposit() {

    cout<<endl;
    if (accnum ==0)
    {
        cout << "개설된 계좌가 없습니다." << endl;
        return;
    }

    String name;
    int money = 0;
    cout << "입금하실 계좌 정보를 입력하세요."<<endl;
    cout << "고객명 : "; cin >> name;
    while(true)
    {
        cout<< "금  액 : "; cin >> money;
        try
        {
            for(int i=0;i<accnum;++i)
            {
                if (name == accountList[i]->getName())
                {
                    if (accountList[i]->deposit(money))
                    {
                        cout<< money <<"원 입금을 성공했습니다."<< endl;
                        return;
                    }
                    else
                    {
                        cout << "입금에 실패했습니다. 금액을 올바르게 입력해주세요."<< endl;
                        return;
                    }

                }

            }
            cout <<"고객명을 올바르게 입력해주세요."<< endl;
            return;
        }
        catch (BankingExeption &expn)
        {
            expn.showExceptionLog();
        }
    }
}

void BankingSystem::withdraw() {

    cout << endl;

    if(accnum==0)
    {
        cout <<"개설된 계좌가 없습니다."<<endl;
        return;
    }

    String name;
    int money;
    cout <<"출금하실 계좌 정보를 입력해주세요."<< endl;
    cout <<"고객명 : "; cin>> name;

    while(true)
    {
        cout <<"금  액 : "; cin>>money;
        try
        {
            for (int i=0;i<accnum;++i)
            {
                if(name==accountList[i]->getName())
                {
                    if (accountList[i]->withdraw(money))
                    {
                        cout << money<<"원 출금을 성공했습니다."<< endl;
                        return;
                    }

                    else
                    {
                        cout <<"출금을 실패했습니다. 금액을 올바르게 입력해주세요."<< endl;
                        return;
                    }
                }
            }
            cout << "고객명을 올바르게 입력해주세요."<<endl;
            return;
        }
        catch (BankingExeption &expn){

            expn.showExceptionLog();
        }
    }
}


void BankingSystem::showAllAccInfo() {

    cout<< endl;
    if(accnum ==0)
    {
        cout<<"개설된 계좌가 없습니다."<<endl;
        return;
    }

    for (int i=0;i<accnum;++i)
        accountList[i]->showAccInfo();
    cout<<endl<<"총 "<< accnum << "건이 조회됐습니다."<<endl;
}

void BankingSystem::finish() {

    for (int i=0;i<accnum;++i)
        delete accountList[i];
    exit(0);
}