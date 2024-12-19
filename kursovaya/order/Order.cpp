#include "Order.h"

// Конструктор
Order::Order(int order_number, Customer* customer)
    : order_number(order_number), customer(customer), order_total(0.0f) {
    order_date = getCurrentDateTime();
}

// Получить текущую дату и время
string Order::getCurrentDateTime() const {
    time_t now = time(0);
    char buffer[20];
    strftime(buffer, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));
    return string(buffer);
}

// Применить скидку
void Order::applyDiscount(float discount_percentage) {
    if (order_total > 0) {
        order_total -= order_total * (discount_percentage / 100.0f);
    }
}

// Показать информацию о заказе
void Order::displayOrderSummary() const {
    cout << "Заказ #" << order_number << " (" << order_date << ")\n";
    customer->viewOrders();
}
