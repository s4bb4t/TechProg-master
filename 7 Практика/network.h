#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <vector>

using namespace std;

// Шаблонный класс для локальной сети
template <typename T>
class LocalNetwork {
private:
    vector<T> data; // Данные, представляющие либо стоимость монтажа, либо количество компьютеров

public:
    // Конструктор, принимающий вектор данных
    LocalNetwork(const vector<T>& inputData) : data(inputData) {}

    // Метод для вычисления минимальной стоимости монтажа
    T calculateMinCost() {
        T minCost = data[0]; // Инициализируем минимальное значение первым элементом
        for (const T& cost : data) {
            if (cost < minCost) {
                minCost = cost; // Обновляем минимальную стоимость
            }
        }
        return minCost; // Возвращаем минимальную стоимость
    }

    // Метод для получения размера сети (количество элементов)
    int getNetworkSize() const {
        return data.size(); // Возвращаем количество элементов в векторе
    }
};

#endif // NETWORK_H
