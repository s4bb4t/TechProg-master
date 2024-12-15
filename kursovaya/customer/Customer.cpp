#include "Customer.h"

// Конструктор
Customer::Customer(const string& name, const string& address, const string& phone_number)
    : name(name), address(address), phone_number(phone_number) {}

// Добавить заказ
void Customer::addOrder(const Pizza& order) {
    orders.push_back(order);
}

const std::vector<Pizza>& Customer::getOrders() const {
    return orders;  // Возвращаем ссылку на вектор заказов
}

// Показать все заказы
void Customer::viewOrders() const {
    if (orders.empty()) {
        cout << "Нет заказов.\n";
        return;
    }
    float total_price = 0;
    cout << "Список заказов:\n";
    for (size_t i = 0; i < orders.size(); ++i) {
        cout << "Заказ #" << i + 1 << ":\n";
        orders[i].showPizzaDetails();
        total_price += orders[i].getFinalPrice();
        cout << endl;
    }
    
    
    cout << "Общая стоимость заказов: " << total_price << endl;
    cout << endl;
}

// Удалить определенный заказ
void Customer::removeOrder(int orderIndex) {
    if (orderIndex < 0 || orderIndex >= static_cast<int>(orders.size())) {
        cout << "Неверный номер заказа.\n";
        return;
    }
    orders.erase(orders.begin() + orderIndex);
    cout << "Заказ #" << orderIndex + 1 << " удален.\n";
}

// Очистить все заказы
void Customer::clearOrders() {
    orders.clear();
    cout << "Все заказы удалены.\n";
}

// Показать информацию о клиенте и список заказов
void Customer::displayCustomerDetails() const {
    cout << "Информация о клиенте:\n";
    cout << "Имя: " << name << "\n";
    cout << "Адрес: " << address << "\n";
    cout << "Номер телефона: " << phone_number << "\n";
    cout << endl;

    if (orders.empty()) {
        cout << "Нет заказов.\n";
    } else {
        viewOrders();
    }
}
