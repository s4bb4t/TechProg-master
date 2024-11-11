#ifndef LOCALNETWORK_H // Защита от повторного включения
#define LOCALNETWORK_H

#include <iostream>
#include <string>

using namespace std;

// Базовый класс для локальных сетей
class LocalNetwork {
protected:
    string networkName; // Название сети
    double installationCost; // Стоимость установки

public:
    LocalNetwork(string name, double cost); // Конструктор
    virtual void showDetails(); // Метод для отображения деталей сети
    virtual double calculateInstallationCost() = 0; // Чисто виртуальный метод для расчета стоимости установки
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

#endif // LOCALNETWORK_H
