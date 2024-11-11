#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <iostream>
#include <string>

using namespace std;

namespace Network {

class LocalNetwork {
protected:
    string networkName; // Название сети
    double installationCost; // Стоимость установки
    static int totalNetworks; // Общее количество объектов этого класса

public:
    LocalNetwork(string name, double cost); // Конструктор
    virtual void showDetails(); // Метод для отображения деталей сети
    virtual double calculateInstallationCost() = 0; // Чисто виртуальный метод для расчета стоимости установки
    string getNetworkName() const; // Метод для получения названия сети
    static int getTotalNetworks(); // Статический метод для получения общего количества объектов
};

// Класс для одноранговых сетей
class PeerToPeerNetwork : private LocalNetwork {
private:
    int numberOfNodes; // Количество узлов

public:
    PeerToPeerNetwork(string name, double cost, int nodes); // Конструктор
    void showDetails(); // Метод для отображения деталей сети
    double calculateInstallationCost(); // Метод для расчета стоимости установки
};

// Класс для сетей типа клиент-сервер
class ClientServerNetwork : private LocalNetwork {
private:
    int numberOfClients; // Количество клиентов

public:
    ClientServerNetwork(string name, double cost, int clients); // Конструктор
    void showDetails(); // Метод для отображения деталей сети
    double calculateInstallationCost(); // Метод для расчета стоимости установки
};

} // namespace Network

#endif // LOCAL_NETWORK_H
