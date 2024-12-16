#ifndef MENU_H
#define MENU_H

#include "network.h"
#include <vector>

// Функция для отображения меню
void showMenu() {
    cout << "\n--- Меню ---" << endl;
    cout << "1. Показать список всех услуг." << endl;
    cout << "2. Показать информацию об услуге." << endl;
    cout << "3. Рассчитать стоимость услуги для заданного количества узлов." << endl;
    cout << "4. Выйти из программы." << endl;
    cout << "Выберите опцию: ";
}

// Функция для выбора услуги из списка
template <typename T>
int selectService(const vector<NetworkService<T>>& services) {
    cout << "\nДоступные услуги:" << endl;
    for (size_t i = 0; i < services.size(); ++i) {
        cout << i + 1 << ". " << services[i].getServiceName() << endl;
    }
    cout << "Введите номер услуги: ";
    int choice;
    cin >> choice;

    if (choice < 1 || choice > static_cast<int>(services.size())) {
        throw out_of_range("Неверный выбор услуги.");
    }

    return choice - 1; // Индексация с 0
}

#endif // MENU_H
