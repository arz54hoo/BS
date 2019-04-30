#include "BankingCommonDecl.h"
#include "BankingSystem.h"

int main(){
    BankingSystem bsHandler;
    int choice;

    while(true)
    {
        bsHandler.showMenu();
        cin >> choice;
        if(cin.fail()){
            cout<<"오류"<<endl;
            cin.clear();
            cin.ignore(256,'\n');
        }
        cout << endl;

        switch (choice)
        {
            case BankingSystem::MAKE:
                bsHandler.makeAccount();
                break;
            case BankingSystem::DEPOSIT:
                bsHandler.deposit();
                break;
            case BankingSystem::WITHDRAW:
                bsHandler.withdraw();
                break;
            case BankingSystem::SHOW:
                bsHandler.showAllAccInfo();
                break;
            case BankingSystem::FINISH:
                bsHandler.finish();
                break;
            default:
                continue;
        }
        getch();
    }

    return 0;
}
