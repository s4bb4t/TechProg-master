#include <iostream>
#include "LocalNetwork.h" // Подключаем заголовочный файл с определением классов

using namespace std;

int main() {
    // Создание динамических массивов объектов производных классов
    const int arraySize = 5;
    PeerToPeerNetwork* peerToPeerNetworks = new PeerToPeerNetwork[arraySize];
    ClientServerNetwork* clientServerNetworks = new ClientServerNetwork[arraySize];

    // Заполнение массивов случайными значениями
    for (int i = 0; i < arraySize; ++i) {
        peerToPeerNetworks[i] = PeerToPeerNetwork("Peer Network " + to_string(i+1), rand() % 5000 + 1000, rand() % 20 + 1);
        clientServerNetworks[i] = ClientServerNetwork("Client-Server Network " + to_string(i+1), rand() % 5000 + 1000, rand() % 10 + 1);
    }

    // Вывод информации и расчет итоговой стоимости монтажа
    for (int i = 0; i < arraySize; ++i) {
        cout << "Детали одноранговой сети #" << (i+1) << ":" << endl;
        peerToPeerNetworks[i].showDetails();
        cout << "Итоговая стоимость монтажа: " << peerToPeerNetworks[i].calculateInstallationCost() << " рублей" << endl << endl;

        cout << "Детали сети типа клиент-сервер #" << (i+1) << ":" << endl;
        clientServerNetworks[i].showDetails();
        cout << "Итоговая стоимость монтажа: " << clientServerNetworks[i].calculateInstallationCost() << " рублей" << endl << endl;
    }

    // Освобождение памяти
    delete[] peerToPeerNetworks;
    delete[] clientServerNetworks;

    return 0; // Завершение программы
}