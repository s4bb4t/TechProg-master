#include "LocalNetwork.h"

// LocalNetwork
LocalNetwork::LocalNetwork(string name, double cost) : networkName(name), installationCost(cost) {}
LocalNetwork::~LocalNetwork() {}

// PeerToPeerNetwork
PeerToPeerNetwork::PeerToPeerNetwork(string name, double cost, int nodes)
    : LocalNetwork(name, cost), numberOfNodes(nodes) {}

void PeerToPeerNetwork::showDetails() const {
    cout << "Сеть: " << networkName << "\nТип: Одноранговая сеть\nКоличество узлов: " << numberOfNodes << "\nСтоимость: " << installationCost << endl;
}

double PeerToPeerNetwork::calculateInstallationCost() const {
    return installationCost + numberOfNodes * 500;
}

double computeIndicator(const PeerToPeerNetwork& network) {
    return network.calculateInstallationCost() * 1.1;
}

// ClientServerNetwork
ClientServerNetwork::ClientServerNetwork(string name, double cost, int clients)
    : LocalNetwork(name, cost), numberOfClients(clients) {}

void ClientServerNetwork::showDetails() const {
    cout << "Сеть: " << networkName << "\nТип: Сеть клиент-сервер\nКоличество клиентов: " << numberOfClients << "\nСтоимость: " << installationCost << endl;
}

double ClientServerNetwork::calculateInstallationCost() const {
    return installationCost + numberOfClients * 1000;
}

double computeIndicator(const ClientServerNetwork& network) {
    return network.calculateInstallationCost() * 1.2;
}
