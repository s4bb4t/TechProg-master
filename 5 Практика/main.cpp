#include "LocalNetwork.h"
#include <cstdlib>
#include <ctime>

int main() {
    const int arraySize = 5;
    int price, cnt;
    srand(static_cast<unsigned>(time(nullptr)));

    cout << "Введите цену для установки устройств" << endl;
    cin >> price;
    cout << "Введите количество устройств" << endl;
    cin >> cnt;
    
    // Создаем массивы сетей
    PeerToPeerNetwork* peerNetworks = new PeerToPeerNetwork[arraySize]{
        PeerToPeerNetwork("PeerNet1", price, cnt),
        PeerToPeerNetwork("PeerNet2", price, cnt),
        PeerToPeerNetwork("PeerNet3", price, cnt),
        PeerToPeerNetwork("PeerNet4", price, cnt),
        PeerToPeerNetwork("PeerNet5", price, cnt)
    };

    ClientServerNetwork* clientNetworks = new ClientServerNetwork[arraySize]{
        ClientServerNetwork("ClientNet1", 5000, 10),
        ClientServerNetwork("ClientNet2", 6000, 15),
        ClientServerNetwork("ClientNet3", 4500, 12),
        ClientServerNetwork("ClientNet4", 5200, 20),
        ClientServerNetwork("ClientNet5", 5600, 18)
    };

    // Выводим информацию о сетях
    for (int i = 0; i < arraySize; ++i) {
        cout << "Одноранговая сеть #" << (i + 1) << ":\n";
        peerNetworks[i].showDetails();
        cout << "Итоговая стоимость монтажа: " << peerNetworks[i].calculateInstallationCost() << endl;
        cout << "Индикатор: " << computeIndicator(peerNetworks[i]) << endl << endl;

        cout << "Сеть клиент-сервер #" << (i + 1) << ":\n";
        clientNetworks[i].showDetails();
        cout << "Итоговая стоимость монтажа: " << clientNetworks[i].calculateInstallationCost() << endl;
        cout << "Индикатор: " << computeIndicator(clientNetworks[i]) << endl << endl;
    }

    delete[] peerNetworks;
    delete[] clientNetworks;

    return 0;
}
