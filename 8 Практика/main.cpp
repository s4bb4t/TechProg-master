#include <iostream>
#include <vector>
#include "LocalNetwork.h"

using namespace std;

// Функция для демонстрации меню программы
void showMenu() {
    cout << "Меню программы:\n";
    cout << "1. Создать вектор из 1000 объектов\n";
    cout << "2. Добавить 500 элементов в середину вектора\n";
    cout << "3. Очистить вектор\n";
    cout << "4. Выйти\n";
}

int main() {
    vector<PeerToPeerNetwork> networks(1000, PeerToPeerNetwork("Network", 10000, 10));

    vector<PeerToPeerNetwork> reversedNetworks(networks.rbegin(), networks.rend());

    cout << "Вычисляемый показатель (суммарная стоимость установки в обратном векторе): " 
         << reversedNetworks[0].calculateInstallationCost() * reversedNetworks.size() << " рублей" << endl;

    networks.insert(networks.begin() + networks.size() / 2, 500, PeerToPeerNetwork("Inserted Network", 5000, 5));
    
    cout << "Вычисляемый показатель после добавления 500 элементов: " 
         << networks[0].calculateInstallationCost() * networks.size() << " рублей" << endl;

    networks.clear();
    
    if (networks.empty()) {
        cout << "Вектор очищен и пуст." << endl;
    }

    return 0;
}
