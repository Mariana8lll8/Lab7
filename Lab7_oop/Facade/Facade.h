#pragma once
#include <iostream>
using namespace std;

class InventoryService
{
private:
    unordered_map<string, int> stock = {
        {"Ferrari 488", 5},
        {"MacBook AIR pro 2025", 2},
        {"IPhone 17", 10}};

public:
    bool checkAvailability(const string &productId);
    void reduceStock(const string &productId);
};

class PaymentService
{
public:
    bool processPayment(const string &userId, double amount);
};

class DeliveryService
{
public:
    void scheduleDelivery(const string &productId, const string &userId);
};

class NotificationService
{
public:
    void sendConfirmation(const string &userId);
};

class OrderRepository
{
public:
    void saveOrder(const string &productId, const string &userId, double amount);
};

class OrderFacade
{
private:
    InventoryService *inventory;
    PaymentService *payment;
    DeliveryService *delivery;
    NotificationService *notification;
    OrderRepository *repository;

public:
    OrderFacade();
    ~OrderFacade();
    bool placeOrder(const string &productId, const string &userId, double amount);
};