#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "../customer/Customer.h"

using namespace std;

class Order {
private:
    int order_number;             // Номер заказа
    string order_date;            // Дата заказа
    Customer* customer;           // Ссылка на клиента
    float order_total;            // Общая сумма заказа

    string getCurrentDateTime() const;  // Получить текущую дату и время

public:
    Order(int order_number, Customer* customer); // Конструктор

    void applyDiscount(float discount_percentage); // Применить скидку
    void displayOrderSummary() const;           // Показать информацию о заказе
};

#endif // ORDER_H