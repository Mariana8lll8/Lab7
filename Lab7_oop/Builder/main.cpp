#include <iostream>
#include "Builder.h"
using namespace std;

int main()
{
    UserRM *rm = new UserRM();
    UserAF *af = new UserAF();
    UserLP *lp = new UserLP();
    UserRegistration *ur = new UserRegistration();
    int choice;
    char cont;

    bool registeredRM = false;
    bool registeredAF = false;
    bool registeredLP = false;

    do
    {
        if (registeredRM && registeredAF && registeredLP)
        {
            cout << "\nAll users are already registered!\n";
            break;
        }

        cout << "\n1. Mariana Roman \n2. Anastasiia Fradkova\n3. Pavlo Levush\n\n";
        cout << "Select user to register: ";
        cin >> choice;

        if (choice == 1)
        {
            if (registeredRM)
            {
                cout << "\nUser  Mariana Roman is already registered.\n\n";
            }
            else
            {
                ur->SetUserBuilder(rm);
                ur->ConstructUser();
                User *user = ur->GetUser();
                cout << user->ToString();
                registeredRM = true;
            }
        }
        else if (choice == 2)
        {
            if (registeredAF)
            {
                cout << "\nUser Anastasiia Fradkova is already registered.\n\n";
            }
            else
            {
                ur->SetUserBuilder(af);
                ur->ConstructUser();
                User *user = ur->GetUser();
                cout << user->ToString();
                registeredAF = true;
            }
        }
        else if (choice == 3)
        {
            if (registeredLP)
            {
                cout << "\nUser Pavlo Levush is already registered.\n\n";
            }
            else
            {
                ur->SetUserBuilder(lp);
                ur->ConstructUser();
                User *user = ur->GetUser();
                cout << user->ToString();
                registeredLP = true;
            }
        }
        else
        {
            cout << "\nInvalid choice!\n";
            break;
        }

        if (registeredRM && registeredAF && registeredLP)
        {
            cout << "\nAll users are already registered!\n";
            break;
        }

        cout << "Do you want to continue? (y/n): ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    cout << "\nProgram completed!\n\n";
    return 0;
}
