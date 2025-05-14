#pragma once
#include <iostream>
using namespace std;

class Pizza
{
private:
    string dough;
    string sauce;
    string cheese;
    string toppings;
    string spices;
    string size;
public:
    void SetDough(string d);
    void SetSauce(string s);
    void SetCheese(string c);
    void SetToppings(string t);
    void SetSpices(string sp);
    void SetSize(string sz);

    string ToString();
};

class PizzaBuilder
{
public:
    void CreateNewPizza();
    Pizza *GetThisPizza();
    ~PizzaBuilder();

    virtual void SetDough() = 0;
    virtual void SetSauce() = 0;
    virtual void SetCheese() = 0;
    virtual void SetToppings() = 0;
    virtual void SetSpices() = 0;
    virtual void SetSize() = 0;

protected:
    Pizza *pizza;
};

class Peperoni : public PizzaBuilder {
public:
    void SetDough() override;
    void SetSauce() override;
    void SetCheese() override;
    void SetToppings() override;
    void SetSpices() override;
    void SetSize() override;
};
class Hawaiian : public PizzaBuilder {
public:
    void SetDough() override;
    void SetSauce() override;
    void SetCheese() override;
    void SetToppings() override;
    void SetSpices() override;
    void SetSize() override;
};
class BBQChicken : public PizzaBuilder {
public:
    void SetDough() override;
    void SetSauce() override;
    void SetCheese() override;
    void SetToppings() override;
    void SetSpices() override;
    void SetSize() override;
};

class BuyPizza
{
private:
    PizzaBuilder *_pizzaBuilder;

public:
    void SetPizzaBuilder(PizzaBuilder *pBuilder);
    Pizza *GetPizza();
    void ConstructPizza();
};
