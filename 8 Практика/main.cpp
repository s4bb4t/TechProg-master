#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Network.h"  // Подключение файла с описанием классов

// Функция для отображения меню
void displayMenu() {
    std::cout << "\nМеню:\n";
    std::cout << "1. Создать вектор из 1000 объектов\n";
    std::cout << "2. Развернуть вектор\n";
    std::cout << "3. Добавить 500 элементов в середину\n";
    std::cout << "4. Очистить вектор и проверить, что он пуст\n";
    std::cout << "5. Выйти\n";
}

// Функция для вывода первых и последних элементов вектора
void printNetworkDetails(const std::vector<Network::LocalNetwork*>& networks) {
    if (networks.empty()) {
        std::cout << "Вектор пуст.\n";
        return;
    }

    // Показать первые 5 элементов
    std::cout << "\nПервые 5 элементов:\n";
    size_t limit = std::min(size_t(5), networks.size());
    for (size_t i = 0; i < limit; ++i) {
        std::cout << "Элемент " << i + 1 << ": ";
        networks[i]->showDetails();
    }

    // Показать последние 5 элементов
    std::cout << "\nПоследние 5 элементов:\n";
    size_t startIndex = networks.size() > 5 ? networks.size() - 5 : 0;
    for (size_t i = startIndex; i < networks.size(); ++i) {
        std::cout << "Элемент " << i + 1 << ": ";
        networks[i]->showDetails();
    }

    // Общее количество элементов
    std::cout << "\nОбщее количество элементов в векторе: " << networks.size() << "\n";
}

// Главная функция
int main() {
    std::vector<Network::LocalNetwork*> networkVector;
    bool running = true;

    // Инициализация генератора случайных чисел
    std::srand(std::time(0));

    while (running) {
        displayMenu();
        int choice;
        std::cin >> choice;

        switch (choice) {
        case 1: {
            // Создание вектора из 1000 объектов (разных типов)
            networkVector.clear();
            for (int i = 0; i < 1000; ++i) {
                if (i % 2 == 0) {
                    networkVector.push_back(new Network::PeerToPeerNetwork(
                        "P2P Network " + std::to_string(i),
                        rand() % 1000 + 500, rand() % 1000 + 100,
                        rand() % 100 + 1, rand() % 2 == 0));
                } else {
                    networkVector.push_back(new Network::ClientServerNetwork(
                        "CS Network " + std::to_string(i),
                        rand() % 1000 + 500, rand() % 1000 + 100,
                        rand() % 50 + 1, rand() % 2 == 0));
                }
            }
            std::cout << "Создано 1000 объектов.\n";
            printNetworkDetails(networkVector);
            break;
        }
        case 2: {
            // Создание второго вектора с объектами в обратном порядке
            std::vector<Network::LocalNetwork*> reversedVector(networkVector.rbegin(), networkVector.rend());
            std::cout << "Вектор развернут.\n";
            printNetworkDetails(reversedVector);
            break;
        }
        case 3: {
            // Добавление 500 элементов в середину вектора
            std::vector<Network::LocalNetwork*> additionalNetworks;
            for (int i = 0; i < 500; ++i) {
                if (i % 2 == 0) {
                    additionalNetworks.push_back(new Network::PeerToPeerNetwork(
                        "P2P Network Mid " + std::to_string(i),
                        rand() % 1000 + 500, rand() % 1000 + 100,
                        rand() % 100 + 1, rand() % 2 == 0));
                } else {
                    additionalNetworks.push_back(new Network::ClientServerNetwork(
                        "CS Network Mid " + std::to_string(i),
                        rand() % 1000 + 500, rand() % 1000 + 100,
                        rand() % 50 + 1, rand() % 2 == 0));
                }
            }

            // Добавление элементов в середину
            networkVector.insert(networkVector.begin() + networkVector.size() / 2, additionalNetworks.begin(), additionalNetworks.end());

            // Информируем пользователя
            std::cout << "500 новых элементов добавлено в середину вектора.\n";
            std::cout << "Вот несколько примеров новых элементов:\n";

            // Показать первые 5 добавленных элементов
            for (size_t i = networkVector.size() / 2; i < std::min(networkVector.size() / 2 + 5, networkVector.size()); ++i) {
                std::cout << "Элемент " << i + 1 << ": ";
                networkVector[i]->showDetails();
            }

            printNetworkDetails(networkVector);
            break;
        }
        case 4: {
            // Очистка вектора
            networkVector.clear();
            std::cout << "Вектор очищен.\n";
            break;
        }
        case 5: {
            // Выход из программы
            running = false;
            std::cout << "Выход из программы.\n";
            break;
        }
        default:
            std::cout << "Неверный выбор, попробуйте снова.\n";
        }
    }

    // Очистка памяти
    for (auto& network : networkVector) {
        delete network;
    }

    return 0;
}
