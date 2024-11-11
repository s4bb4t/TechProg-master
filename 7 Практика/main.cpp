#include <iostream>
#include "network.h"

using namespace std;

int main() {
    // Создаем объект локальной сети
    LocalNetwork<double> installationCosts({150.5, 200.75, 100.0, 250.25, 120.0});
    LocalNetwork<int> computersInNetwork({1, 2, 3, 4, 5});

    // Выводим минимальную стоимость установки
    double minCost = installationCosts.calculateMinCost();
    cout << "Минимальная стоимость монтажа: " << minCost << " рублей" << endl;

    // Выводим количество компьютеров в сети
    int computerCount = computersInNetwork.getNetworkSize();
    cout << "Количество компьютеров в сети: " << computerCount << endl;

    return 0; // Завершение программы
}
