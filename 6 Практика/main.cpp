#include <iostream>
#include "Network.h"

using namespace Network;

void showMenu() {
    std::cout << "\n=========================================\n";
    std::cout << "Меню:\n";
    std::cout << "1. Показать информацию о одноранговой сети (P2P)\n";
    std::cout << "2. Показать информацию о клиент-серверной сети\n";
    std::cout << "3. Показать общее количество сетей\n";
    std::cout << "4. Сравнить минимальные стоимости монтажа\n";
    std::cout << "5. Выход\n";
    std::cout << "=========================================\n";
}

int main() {
    PeerToPeerNetwork p2pNetwork("Домашняя сеть", 5000, 100, 5, true);
    ClientServerNetwork csNetwork("Корпоративная сеть", 15000, 500, 50, true);

    int choice;
    bool exit = true;
    while (exit) {
        showMenu();
        std::cout << "\nВыберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                p2pNetwork.showDetails();
                break;
            case 2:
                csNetwork.showDetails();
                break;
            case 3:
                std::cout << "Общее количество сетей: " << LocalNetwork::getTotalNetworks() << "\n";
                break;
            case 4: {
                double p2pMinCost = p2pNetwork.calculateInstallationCost(0.05);  // Пример применения скидки 5%
                double csMinCost = csNetwork.calculateInstallationCost(0.10);  // Пример применения скидки 10%

                std::cout << "Минимальная стоимость установки P2P: " << p2pMinCost << " руб.\n";
                std::cout << "Минимальная стоимость установки Клиент-серверной сети: " << csMinCost << " руб.\n";

                if (p2pNetwork < csNetwork) {
                    std::cout << "P2P сеть имеет меньшую минимальную стоимость установки.\n";
                } else {
                    std::cout << "Клиент-серверная сеть имеет меньшую минимальную стоимость установки.\n";
                }
                break;
            }
            case 5:
                std::cout << "Выход из программы.\n";
                exit = false;
                break;
            default:
                std::cout << "Неверный выбор. Попробуйте снова.\n";
                break;
        }
    }

    return 0;
}
