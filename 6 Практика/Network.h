#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <string>

namespace Network {

// Базовый класс для всех типов сетей
class LocalNetwork {
protected:
    std::string networkName;   // Название сети
    double installationCost;   // Стоимость установки
    int networkSpeed;          // Скорость сети (Мбит/с)
    static int totalNetworks;  // Статический член для общего количества объектов

public:
    LocalNetwork(std::string name, double cost, int speed);  // Конструктор
    virtual ~LocalNetwork();  // Деструктор
    virtual void showDetails() const = 0;  // Виртуальный метод для вывода характеристик
    virtual double calculateInstallationCost() const = 0;   // Чисто виртуальный метод для расчета стоимости установки
    static int getTotalNetworks();  // Статический метод для получения общего количества объектов
    std::string getNetworkName() const;  // Метод для получения названия сети
};

// Класс для одноранговых сетей
class PeerToPeerNetwork : private LocalNetwork {
private:
    int numberOfNodes;   // Количество узлов
    bool isEncrypted;    // Шифрование данных

public:
    PeerToPeerNetwork(std::string name, double cost, int speed, int nodes, bool encrypted);  // Конструктор
    void showDetails() const override;  // Переопределенный метод для отображения характеристик
    double calculateInstallationCost() const override;  // Переопределенный метод для расчета стоимости установки
    double getMinimumCost() const;  // Минимальная стоимость установки
};

// Класс для сетей типа клиент-сервер
class ClientServerNetwork : private LocalNetwork {
private:
    int numberOfClients;  // Количество клиентов
    bool hasFirewall;     // Наличие фаервола

public:
    ClientServerNetwork(std::string name, double cost, int speed, int clients, bool firewall);  // Конструктор
    void showDetails() const override;  // Переопределенный метод для отображения характеристик
    double calculateInstallationCost() const override;  // Переопределенный метод для расчета стоимости установки
    double getMinimumCost() const;  // Минимальная стоимость установки
};

}

#endif
