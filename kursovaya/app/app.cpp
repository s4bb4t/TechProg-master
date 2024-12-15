#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>
#include "../pizza/Pizza.h"
#include "../customer/Customer.h"
#include "../order/Order.h"

using namespace std;

// Глобальные переменные и мьютексы для синхронизации
vector<Customer> customers;
vector<Order> orders;
mutex customer_mutex;
mutex order_mutex;
int order_counter = 1;

// Функции для работы с клиентами
void createCustomer() {
    string name, address, phone_number;
    cout << "\nВведите имя клиента: ";
    cin.ignore();
    getline(cin, name);
    cout << "Введите адрес клиента: ";
    getline(cin, address);
    cout << "Введите номер телефона клиента: ";
    getline(cin, phone_number);

    lock_guard<mutex> lock(customer_mutex);
    customers.emplace_back(name, address, phone_number);
    cout << "\nКлиент успешно создан.\n";
}

void viewCustomers() {
    lock_guard<mutex> lock(customer_mutex);
    if (customers.empty()) {
        cout << "\nНет зарегистрированных клиентов.\n";
        return;
    }

    cout << "\nСписок клиентов:\n";
    for (size_t i = 0; i < customers.size(); ++i) {
        cout << "\nКлиент #" << i + 1 << ":\n";
        customers[i].displayCustomerDetails();
    }
}

void placeOrder() {
    int customer_index;
    {
        lock_guard<mutex> lock(customer_mutex);
        if (customers.empty()) {
            cout << "\nНет зарегистрированных клиентов. Сначала создайте клиента.\n";
            return;
        }
        cout << "\nВыберите клиента по индексу:\n";
        for (size_t i = 0; i < customers.size(); ++i) {
            customers[i].displayCustomerDetails();
        }
    }

    cin >> customer_index;
    if (customer_index < 1 || customer_index > static_cast<int>(customers.size())) {
        cout << "\nНеверный индекс клиента.\n";
        return;
    }

    Customer& customer = customers[customer_index - 1];
    // Выбор размера пиццы
    int size_choice;
    cout << "Выберите размер пиццы (0 - Small, 1 - Medium, 2 - Large): ";
    cin >> size_choice;
    Size size = static_cast<Size>(size_choice);

    // Выбор типа корки
    int crust_choice;
    cout << "Выберите тип корки (0 - Thin, 1 - Thick, 2 - Stuffed): ";
    cin >> crust_choice;
    Crust crust = static_cast<Crust>(crust_choice);

    Pizza pizza(size, crust);


    while (true) {
        string topping;
        cout << "\nДобавьте топпинг (или 'done' для завершения): ";
        cin >> topping;
        if (topping == "done") break;
        pizza.addTopping(topping);
    }

    {
        lock_guard<mutex> lock(customer_mutex);
        customer.addOrder(pizza);
    }

    {
        lock_guard<mutex> lock(order_mutex);
        orders.emplace_back(order_counter++, &customer);
    }

    cout << "\nЗаказ успешно создан.\n";
}

// Функции для работы с заказами
void viewOrders() {
    lock_guard<mutex> lock(order_mutex);
    if (orders.empty()) {
        cout << "\nНет заказов.\n";
        return;
    }

    cout << "\nСписок заказов:\n";
    for (const auto& order : orders) {
        order.displayOrderSummary();
    }
}

void cancelOrder() {
    int order_index;
    {
        lock_guard<mutex> lock(order_mutex);
        if (orders.empty()) {
            cout << "\nНет заказов для отмены.\n";
            return;
        }

        cout << "\nВыберите номер заказа для отмены:\n";
        for (size_t i = 0; i < orders.size(); ++i) {
            cout << i + 1 << ". Заказ #" << i + 1 << "\n";
        }
    }

    cin >> order_index;
    if (order_index < 1 || order_index > static_cast<int>(orders.size())) {
        cout << "\nНеверный номер заказа.\n";
        return;
    }

    {
        lock_guard<mutex> lock(order_mutex);
        orders.erase(orders.begin() + order_index - 1);
    }

    cout << "\nЗаказ успешно отменен.\n";
    // Обновляем заказы клиентов
    for (auto& customer : customers) {
        customer.removeOrder(order_index - 1);
    }
}

// Главное меню
void menu() {
    while (true) {
        cout << "\n-------------------------\n";
        cout << "         Пиццерия Меню    \n";
        cout << "-------------------------\n";
        cout << "1. Создать клиента\n";
        cout << "2. Разместить заказ\n";
        cout << "3. Просмотреть клиентов\n";
        cout << "4. Просмотреть заказы\n";
        cout << "5. Отменить заказ\n";
        cout << "6. Выход\n";
        cout << "-------------------------\n";
        cout << "Выберите опцию: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                createCustomer();
                break;
            case 2:
                placeOrder();
                break;
            case 3:
                viewCustomers();
                break;
            case 4:
                viewOrders();
                break;
            case 5:
                cancelOrder();
                break;
            case 6:
                cout << "\nЗавершение работы программы...\n";
                return;
            default:
                cout << "\nНеверный выбор. Попробуйте снова.\n";
        }
    }
}

void startApplication() {
    thread menu_thread(menu); // Запуск меню в отдельном потоке

    // Ожидание завершения работы меню
    menu_thread.join();
}

int main() {
    // Запуск приложения
    startApplication();

    return 0;
}