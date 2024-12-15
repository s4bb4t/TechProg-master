#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>
#include <iostream>
#include "../pizza/Pizza.h"

using namespace std;

class Customer {
private:
    string name;                // Имя клиента
    string address;             // Адрес клиента
    string phone_number;        // Номер телефона
    vector<Pizza> orders;       // Список заказов

public:
    Customer(const string& name, const string& address, const string& phone_number); // Конструктор

    void addOrder(const Pizza& order);      // Добавить заказ
    void viewOrders() const;               // Посмотреть заказы
    void removeOrder(int orderIndex);      // Удалить заказ
    void clearOrders();                    // Очистить заказы
    void displayCustomerDetails() const;  // Показать информацию о клиенте
    const vector<Pizza>& getOrders() const; // Получить список заказов
};

#endif // CUSTOMER_H
