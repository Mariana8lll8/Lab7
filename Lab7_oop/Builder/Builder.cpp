#include <iostream>
#include "Builder.h"
using namespace std;

string Pizza::ToString() { return string("\n--- PIZZA ---\nDough: " + dough + "\nSauce: " + sauce + "\nCheese: " + cheese + "\nToppings: " + toppings + "\nSpices: " + spices + "\nSize: " + size + "\n\n"); }

void PizzaBuilder::CreateNewPizza() { pizza = new Pizza(); }
Pizza* PizzaBuilder::GetThisPizza() { return pizza; }
PizzaBuilder::~PizzaBuilder() { delete pizza; }

void Pizza::SetDough(string d) { dough = d; }
void Pizza::SetSauce(string s) { sauce = s; }
void Pizza::SetCheese(string c) { cheese = c; }
void Pizza::SetToppings(string t) { toppings = t; }
void Pizza::SetSpices(string sp) { spices = sp; }
void Pizza::SetSize(string sz) { size = sz; }

void Peperoni::SetDough() { pizza->SetDough("тонке тісто"); }
void Peperoni::SetSauce() { pizza->SetSauce("томатний соус"); }
void Peperoni::SetCheese() { pizza->SetCheese("моцарела"); }
void Peperoni::SetToppings() { pizza->SetToppings("пепероні"); }
void Peperoni::SetSpices() { pizza->SetSpices("орегано"); }
void Peperoni::SetSize() { pizza->SetSize("велика"); }

void Hawaiian::SetDough() { pizza->SetDough("пухке тісто"); }
void Hawaiian::SetSauce() { pizza->SetSauce("солодкий соус"); }
void Hawaiian::SetCheese() { pizza->SetCheese("чеддер"); }
void Hawaiian::SetToppings() { pizza->SetToppings("ананас, шинка"); }
void Hawaiian::SetSpices() { pizza->SetSpices("базилік"); }
void Hawaiian::SetSize() { pizza->SetSize("середня"); }

void BBQChicken::SetDough() { pizza->SetDough("гриль тісто"); }
void BBQChicken::SetSauce() { pizza->SetSauce("BBQ соус"); }
void BBQChicken::SetCheese() { pizza->SetCheese("моцарела, пармезан"); }
void BBQChicken::SetToppings() { pizza->SetToppings("курка, цибуля"); }
void BBQChicken::SetSpices() { pizza->SetSpices("перець"); }
void BBQChicken::SetSize() { pizza->SetSize("велика"); }

void BuyPizza::SetPizzaBuilder(PizzaBuilder* pBuilder) { _pizzaBuilder = pBuilder; }
Pizza* BuyPizza::GetPizza() { return _pizzaBuilder->GetThisPizza(); }
void BuyPizza::ConstructPizza() 
{
    _pizzaBuilder->CreateNewPizza();
    _pizzaBuilder->SetDough();
    _pizzaBuilder->SetSauce();
    _pizzaBuilder->SetCheese();
    _pizzaBuilder->SetToppings();
    _pizzaBuilder->SetSpices();
    _pizzaBuilder->SetSize();
}
