#include <iostream>
#include "Builder.h"
using namespace std;

int main()
{
    Peperoni *p = new Peperoni();
    Hawaiian *h = new Hawaiian();
    BBQChicken *b = new BBQChicken();
    BuyPizza *buy = new BuyPizza();
    int choice;
    char cont;

    do
    {
        cout << "\nЯку піцу бажаєте замовити? \n\n1. Пепероні\n2. Гавайська\n3. BBQ з куркою\n\n";
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 1)
        {
            buy->SetPizzaBuilder(p);
            buy->ConstructPizza();
            Pizza *pizza = buy->GetPizza();
            cout << pizza->ToString();
        }
        else if (choice == 2)
        {
            buy->SetPizzaBuilder(h);
            buy->ConstructPizza();
            Pizza *pizza = buy->GetPizza();
            cout << pizza->ToString();
        }
        else if (choice == 3)
        {
            buy->SetPizzaBuilder(b);
            buy->ConstructPizza();
            Pizza *pizza = buy->GetPizza();
            cout << pizza->ToString();
        }
        else
        {
            cout << "\nНеправильний ввід!\n";
            break;
        }

        cout << "Хочете продовжити? (y/n): ";
        cin >> cont;
    }
    while (cont == 'y' || cont == 'Y')
        ;

    cout << "\nПрограма завершена!\n\n";
    return 0;
}
