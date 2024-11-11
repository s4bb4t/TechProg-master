#include "LocalNetwork.h"

// Конструктор для базового класса LocalNetwork
LocalNetwork::LocalNetwork(string name, double cost)
    : networkName(name), installationCost(cost) {}

// Метод для отображения деталей сети
void LocalNetwork::showDetails() {
    cout << "Сеть: " << networkName << endl;
    cout << "Стоимость монтажа: " << installationCost << " рублей" << endl;
}

// Конструктор для класса PeerToPeerNetwork
PeerToPeerNetwork::PeerToPeerNetwork(string name, double cost, int nodes)
    : LocalNetwork(name, cost), numberOfNodes(nodes) {}

// Переопределённый метод для отображения деталей одноранговой сети
void PeerToPeerNetwork::showDetails() {
    LocalNetwork::showDetails(); // Вызов метода базового класса
    cout << "Тип сети: Одноранговая сеть: все узлы равны и могут выступать как клиент и сервер." << endl;
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
    cout << "Тип сети: Сеть типа клиент-сервер: один сервер обслуживает несколько клиентов." << endl;
    cout << "Количество клиентов: " << numberOfClients << endl;
}

// Метод для расчета стоимости установки для сети типа клиент-сервер
double ClientServerNetwork::calculateInstallationCost() {
    return installationCost + numberOfClients * 1000; // Стоимость монтажа + дополнительная стоимость за клиентов
}