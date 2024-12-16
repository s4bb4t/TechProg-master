#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <vector>
#include <memory> // Для std::unique_ptr
#include <string>

using namespace std;

// Абстрактный базовый класс
class INetworkService {
public:
    virtual void printServiceInfo() const = 0;           // Метод для вывода информации об услуге
    virtual double calculateCostForNodes(int nodeCount) const = 0; // Метод для расчета стоимости
    virtual ~INetworkService() = default;                // Виртуальный деструктор
};

// Шаблонный класс для управления товарами и услугами сети
template <typename ValueType>
class NetworkService : public INetworkService {
private:
    string serviceName;  // Название услуги
    ValueType minCost;   // Минимальная стоимость монтажа
    int minNodes;        // Минимальное количество узлов
    bool hasFirewall;    // Есть ли поддержка firewall
    bool hasBackupPower; // Есть ли резервное питание

public:
    // Конструктор
    NetworkService(const string& name, ValueType cost, int nodes, bool firewall, bool backup)
        : serviceName(name), minCost(cost), minNodes(nodes), hasFirewall(firewall), hasBackupPower(backup) {}

    // Вывод информации об услуге
    void printServiceInfo() const override {
        cout << endl;
        cout << "----------------------------" << endl;
        cout << "Услуга: " << serviceName << endl << endl;
        cout << "Минимальная стоимость: " << minCost << " руб." << endl;
        cout << "Минимальное количество узлов: " << minNodes << endl;
        cout << "Firewall: " << (hasFirewall ? "Да" : "Нет") << endl;
        cout << "Резервное питание: " << (hasBackupPower ? "Да" : "Нет") << endl;
        cout << "----------------------------" << endl;
        cout << endl;
    }

    // Расчет стоимости для заданного количества узлов
    double calculateCostForNodes(int nodeCount) const override {
        if (nodeCount < minNodes) {
            cout << "Ошибка: количество узлов меньше минимального!" << endl;
            return 0.0;
        }
        return static_cast<double>(minCost) * (static_cast<double>(nodeCount) / minNodes);
    }
};

#endif // NETWORK_H
