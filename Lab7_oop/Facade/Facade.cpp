#include <iostream>
#include "Facade.h"
using namespace std;

bool InventoryService::checkAvailability(const string &productId) { return stock[productId] > 0; }
void InventoryService::reduceStock(const string &productId)
{
    if (stock[productId] > 0)
        stock[productId]--;
}
bool PaymentService::processPayment(const string &userId, double amount)
{
    cout << "[Payment] Користувач " << userId << " оплатив " << amount << " грн\n";
    return true;
}
void DeliveryService::scheduleDelivery(const string &productId, const string &userId) { cout << "[Delivery] Доставка товару " << productId << " оформлена для користувача " << userId << endl; }
void NotificationService::sendConfirmation(const string &userId) { cout << "[Notification] Підтвердження замовлення надіслано користувачу " << userId << endl; }
void OrderRepository::saveOrder(const string &productId, const string &userId, double amount)
{
    cout << "[Repository] Замовлення користувача " << userId << " на товар " << productId
         << " (сума: " << amount << " грн) збережено у базі даних.\n";
}
bool OrderFacade::placeOrder(const string &productId, const string &userId, double amount)
{
    cout << "\n[Order] Обробка замовлення для " << userId << " на " << productId << "...\n";

    if (!inventory->checkAvailability(productId))
    {
        cout << "[Order] Товар відсутній на складі.\n\n";
        return false;
    }

    if (!payment->processPayment(userId, amount))
    {
        cout << "[Order] Платіж не пройшов.\n";
        return false;
    }

    inventory->reduceStock(productId);
    delivery->scheduleDelivery(productId, userId);
    repository->saveOrder(productId, userId, amount);
    notification->sendConfirmation(userId);

    cout << "[Order] Замовлення успішно оформлено!\n\n";
    return true;
}

OrderFacade::OrderFacade()
{
    inventory = new InventoryService();
    payment = new PaymentService();
    delivery = new DeliveryService();
    notification = new NotificationService();
    repository = new OrderRepository();
}

OrderFacade::~OrderFacade()
{
    delete inventory;
    delete payment;
    delete delivery;
    delete notification;
    delete repository;
}