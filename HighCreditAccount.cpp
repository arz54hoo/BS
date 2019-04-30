//
// Created by seik on 2019-04-26.
//

#include "HighCreditAccount.h"
#include "BankingCommonDecl.h"

HighCreditAccount::HighCreditAccount(const String accountNumber, const String name, int money, int interRate,
                                     int specialRate)
                                     :NormalAccount(accountNumber, name, money, interRate)
                                     {
                                        switch (specialRate)
                                        {
                                            case A:
                                                this->specialRate = 7;
                                                break;
                                            case B:
                                                this->specialRate = 4;
                                                break;
                                            case C:
                                                this->specialRate = 2;
                                                break;
                                            default:
                                                this->specialRate = 0;
                                                break;
                                        }
                                     }

HighCreditAccount::~HighCreditAccount() {}

bool HighCreditAccount::deposit(const int &money) {

    if (!NormalAccount::deposit(money))
        return false;
    if (!Account::deposit((int)(money * (specialRate/100.0f))))
        return false;

    return true;
}

void HighCreditAccount::showAccInfo() const {

    NormalAccount::showAccInfo();

    char grade = specialRate == 7? 'A': specialRate==4 ? 'B':'C';
    cout<< "등    급 : "<< grade<< endl;
}