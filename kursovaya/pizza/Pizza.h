#ifndef PIZZA_H
#define PIZZA_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

enum class Size { Small, Medium, Large };  // Размеры пиццы
enum class Crust { Thin, Thick, Stuffed }; // Типы корки

class Pizza {
private:
    Size size;                  // Размер пиццы
    Crust crust;                // Тип корки
    vector<string> toppings;    // Список топпингов
    float base_price;           // Базовая цена
    float final_price;          // Финальная цена

    void calculatePrice();      // Пересчитать финальную цену

public:
    Pizza(Size s, Crust c);     // Конструктор

    void addTopping(const string& topping);     // Добавить топпинг
    void removeTopping(const string& topping);  // Удалить топпинг
    void showPizzaDetails() const;             // Показать детали пиццы

    float getFinalPrice() const;               // Получить финальную цену
};

#endif // PIZZA_H
