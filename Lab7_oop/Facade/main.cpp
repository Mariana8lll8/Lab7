#include <iostream>
#include "Facade.h"
using namespace std;

int main() {
    OrderFacade* shop = new OrderFacade();

    int qOrder;
    double budget;
    string product, user;
    char cont;
    do
    {
        cout << "\n--- Наявність товару ---\n";
        cout << "\n1. Ferrari 488 (5 штук) | Ціна: 1000000.99 грн\n2. MacBookc AIR pro 2025 (2 штуки) | Ціна: 60999.99 грн\n3. IPhone 17 (10 штук) | Ціна: 70999.99 грн\n\n(Вихід з програми '0')\n";
    
        cout << "\nДобрий день! Скільки замовлень плануєте зробити? ";
        cin >> qOrder;
        if (qOrder == 100) 
        { 
            cout << "Неможливо замовити таку к-сть!"; 
            break;
        }
        else if (qOrder == 0) exit(0);
        cout << "\nЯкий у вас бюджет? ";
        cin >> budget;

        cout << "\nВведіть ім'я користувача: ";
        cin >> user;
        cout << "\n";
        
        for (int i = 0; i < qOrder; i++) {
            if (budget <= 0.0 || budget < 70000) 
            {
                cout << "У вас недостатньо коштів для купівлі будь-чого, ДО ПОБАЧЕННЯ!!!\n";
                cout << "Залишок: " << budget << " грн\n";
                break;
            }
            cout << "Який товар ви хочете замовити? (номер): ";
            cin >> product;
            if (product == "1") 
            { 
                shop->placeOrder("Ferrari 488", user, 1000000.99);
                budget -= 1000000.99;
            }
            else if (product == "2") 
            { 
                shop->placeOrder("MacBook AIR pro 2025", user, 60999.99);
                budget -= 60999.99;
            }
            else if (product == "3") 
            { 
                shop->placeOrder("IPhone 17", user, 70999.99); 
                budget -= 70999.99;
            }
            else if (product == "4") exit(0);
            else break;

        }

        cout << "\nХочете продовжити? (y/n): ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    delete shop;
    return 0;
}
