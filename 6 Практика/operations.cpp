#include "operations.h"

using namespace std;

namespace Network {

// Инициализация статического члена
int LocalNetwork::totalNetworks = 0;

// Конструктор для базового класса LocalNetwork
LocalNetwork::LocalNetwork(string name, double cost)
    : networkName(name), installationCost(cost) {
    totalNetworks++; // Увеличиваем общее количество объектов
}

// Метод для отображения деталей сети
void LocalNetwork::showDetails() {
    cout << "Сеть: " << networkName << endl;
    cout << "Стоимость монтажа: " << installationCost << " рублей" << endl;
}

// Метод для получения названия сети
string LocalNetwork::getNetworkName() const {
    return networkName;
}

// Статический метод для получения общего количества объектов
int LocalNetwork::getTotalNetworks() {
    return totalNetworks;
}

// Конструктор для класса PeerToPeerNetwork
PeerToPeerNetwork::PeerToPeerNetwork(string name, double cost, int nodes)
    : LocalNetwork(name, cost), numberOfNodes(nodes) {}

// Переопределённый метод для отображения деталей одноранговой сети
void PeerToPeerNetwork::showDetails() {
    LocalNetwork::showDetails(); // Вызов метода базового класса
    cout << "Тип сети: Одноранговая сеть" << endl;
    cout << "Количество узлов: " << numberOfNodes << endl;
}

// Метод для расчета стоимости установки для одноранговой сети
double PeerToPeerNetwork::calculateInstallationCost() {
    return installationCost + numberOfNodes * 500; // Стоимость монтажа + дополнительная стоимость за узлы
}

// Конструктор для класса ClientServerNetwork
ClientServerNetwork::ClientServerNetwork(string name, double cost, int clients)
    : LocalNetwork(name, cost), numberOfClients(clients) {}

// Переопределённый метод для отображения деталей сети типа клиент-сервер
void ClientServerNetwork::showDetails() {
    LocalNetwork::showDetails(); // Вызов метода базового класса
    cout << "Тип сети: Сеть типа клиент-сервер" << endl;
    cout << "Количество клиентов: " << numberOfClients << endl;
}

// Метод для расчета стоимости установки для сети типа клиент-сервер
double ClientServerNetwork::calculateInstallationCost() {
    return installationCost + numberOfClients * 1000; // Стоимость монтажа + дополнительная стоимость за клиентов
}

} 
