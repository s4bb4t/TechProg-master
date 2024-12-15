#include <iostream>
#include <string>
#include <iomanip>
#include "Network.h"

using namespace std;
using namespace Network;

void displayHeader(const string& title, const string columns[], int columnCount) {
    cout << "\n" << title << "\n";
    cout << string(columnCount * 20, '=') << "\n";
    for (int i = 0; i < columnCount; ++i) {
        cout << setw(17) << left << columns[i];
    }
    cout << "\n" << string(columnCount * 20, '=') << "\n";
}

int main() {
    setlocale(LC_ALL, "");

    PeerToPeerNetwork p2pNetworks[3] = {
        {"HomeNet", 100, 100, 10, true},
        {"OfficeNet", 200, 200, 20, false},
        {"ClubNet", 300, 150, 15, true}
    };

    ClientServerNetwork csNetworks[3] = {
        {"DataNet", 500, 300, 25, true},
        {"WebNet", 400, 250, 30, false},
        {"CloudNets", 700, 400, 40, true}
    };

    char option;
    do {
        cout << "\nМеню:\n"
             << "1. Показать сети Peer-to-Peer\n"
             << "2. Показать сети Client-Server\n"
             << "3. Общая статистика\n"
             << "4. Сравнить две сети Peer-to-Peer\n"
             << "5. Демонстрация перегрузки функции\n"
             << "Q. Выход\n"
             << "Выберите опцию: ";
        cin >> option;

        if (option == '1') {
            const string columns[] = {"Name", "Cost", "Speed", "Nodes", "Encryption"};
            displayHeader("Сети Peer-to-Peer", columns, 5);
            for (const auto& network : p2pNetworks) {
                network.showDetails();
            }
        } else if (option == '2') {
            const string columns[] = {"Name", "Cost", "Speed", "Clients", "Firewall"};
            displayHeader("Сети Client-Server", columns, 5);
            for (const auto& network : csNetworks) {
                network.showDetails();
            }
        } else if (option == '3') {
            cout << "\nОбщая статистика:\n";
            cout << string(40, '-') << "\n";
            cout << "Общее количество сетей: " << LocalNetwork::getTotalNetworks() << "\n";
            cout << "Типы сетей: "
                 << PeerToPeerNetwork::getNetworkType() << ", "
                 << ClientServerNetwork::getNetworkType() << "\n";
            cout << string(40, '-') << "\n";
        } else if (option == '4') {
            int first, second;
            cout << "Введите индексы двух P2P-сетей для сравнения (0-2): ";
            cin >> first >> second;
            if (first >= 0 && first < 3 && second >= 0 && second < 3) {
                double costFirst = p2pNetworks[first].calculateInstallationCost();
                double costSecond = p2pNetworks[second].calculateInstallationCost();
                cout << "\nСтоимость настройки первой сети (" << p2pNetworks[first].getNetworkName() << "): " << costFirst << "\n";
                cout << "Стоимость настройки второй сети (" << p2pNetworks[second].getNetworkName() << "): " << costSecond << "\n";
                if (p2pNetworks[first] < p2pNetworks[second]) {
                    cout << p2pNetworks[first].getNetworkName() << " имеет меньшую стоимость настройки.\n";
                } else {
                    cout << p2pNetworks[second].getNetworkName() << " имеет меньшую стоимость настройки.\n";
                }
            } else {
                cout << "Неверные индексы!\n";
            }
        } else if (option == '5') {
            int index;
            double discount;
            cout << "Введите индекс P2P-сети (0-2): ";
            cin >> index;
            cout << "Введите скидку (0-1): ";
            cin >> discount;
            if (index >= 0 && index < 3 && discount >= 0.0 && discount <= 1.0) {
                double originalCost = p2pNetworks[index].calculateInstallationCost();
                double discountedCost = p2pNetworks[index].calculateInstallationCost(discount);
                cout << "\nИзначальная стоимость настройки: " << originalCost << "\n";
                cout << "Стоимость настройки с учётом скидки: " << discountedCost << "\n";
            } else {
                cout << "Некорректный ввод!\n";
            }
        } else if (option == 'Q' || option == 'q') {
            cout << "Выход из программы. До свидания!\n";
            break;
        } else {
            cout << "Неверный выбор. Попробуйте снова.\n";
        }
    } while (true);

    return 0;
}
