#include "Pizza.h"

// Конструктор
Pizza::Pizza(Size s, Crust c) : size(s), crust(c) {
    if (size == Size::Small) base_price = 5.0f;
    else if (size == Size::Medium) base_price = 7.0f;
    else base_price = 9.0f;

    if (crust == Crust::Thick) base_price += 2.0f;
    else if (crust == Crust::Stuffed) base_price += 3.0f;

    final_price = base_price;
}

// Пересчитать финальную цену
void Pizza::calculatePrice() {
    final_price = base_price + toppings.size() * 1.1f;
}

// Добавить топпинг
void Pizza::addTopping(const string& topping) {
    toppings.push_back(topping);
    calculatePrice();
}

// Удалить топпинг
void Pizza::removeTopping(const string& topping) {
    for (auto it = toppings.begin(); it != toppings.end(); ++it) {
        if (*it == topping) {
            toppings.erase(it);
            calculatePrice();
            break;
        }
    }
}

// Показать детали пиццы
void Pizza::showPizzaDetails() const {
    cout << "Pizza Details:\n";
    cout << "Size: " << (size == Size::Small ? "Small" : size == Size::Medium ? "Medium" : "Large") << "\n";
    cout << "Crust: " << (crust == Crust::Thin ? "Thin" : crust == Crust::Thick ? "Thick" : "Stuffed") << "\n";
    cout << "Toppings: ";
    if (toppings.empty()) cout << "None";
    else for (const auto& topping : toppings) cout << topping << " ";
    cout << "\n";
    cout << fixed << setprecision(2) << "Final Price: $" << final_price << endl;
}

// Получить финальную цену
float Pizza::getFinalPrice() const {
    return final_price;
}
