#ifndef LOCALNETWORK_H
#define LOCALNETWORK_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Базовый класс для локальных сетей
class LocalNetwork {
protected:
    string networkName;   // Имя сети
    double installationCost;   // Стоимость установки

public:
    LocalNetwork(string name, double cost) : networkName(name), installationCost(cost) {}

    virtual double calculateInstallationCost() const = 0;
};

// Класс для одноранговой сети
class PeerToPeerNetwork : public LocalNetwork {
private:
    int numberOfNodes; // Количество узлов

public:
    PeerToPeerNetwork(string name, double cost, int nodes)
        : LocalNetwork(name, cost), numberOfNodes(nodes) {}

    double calculateInstallationCost() const override {
        return installationCost + (numberOfNodes * 500);
    }
};

#endif
