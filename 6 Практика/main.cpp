#include <iostream>
#include "operations.h"

using namespace std;

int main() {
    const int arraySize = 5; // Размер массивов
    LocalNetwork* networks[arraySize]; // Массив указателей на базовый класс

    // Создание объектов производных классов
    for (int i = 0; i < arraySize; ++i) {
        if (i % 2 == 0) {
            networks[i] = new PeerToPeerNetwork("Сеть P2P " + to_string(i + 1), 2000 + i * 100, rand() % 10 + 1);
        } else {
            networks[i] = new ClientServerNetwork("Сеть C/S " + to_string(i + 1), 3000 + i * 150, rand() % 5 + 1);
        }
    }

    // Меню для демонстрации содержимого проекта
    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Показать характеристики сетей\n";
        cout << "2. Расчитать стоимость установки сетей\n";
        cout << "0. Выход\n";
        cout << "Выберите опцию: ";
        cin >> choice;

        switch (choice) {
            case 1:
                for (int i = 0; i < arraySize; ++i) {
                    networks[i]->showDetails();
                }
                break;
            case 2:
                for (int i = 0; i < arraySize; ++i) {
                    cout << "Итоговая стоимость монтажа для " << networks[i]->getNetworkName() << ": "
                         << networks[i]->calculateInstallationCost() << " рублей" << endl;
                }
                break;
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор. Пожалуйста, попробуйте снова." << endl;
        }
    } while (choice != 0);

    // Освобождение памяти
    for (int i = 0; i < arraySize; ++i) {
        delete networks[i];
    }

    return 0; // Завершение программы
}
