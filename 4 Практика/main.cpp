#include <iostream>
#include <cmath>
using namespace std;

// Задание 1: Класс для представления точки на плоскости
class Point {
private:
    float x, y; // Закрытые переменные для координат

public:
    // Конструкторы
    Point() : x(0), y(0) {} // Конструктор по умолчанию
    Point(float xCoord, float yCoord) : x(xCoord), y(yCoord) {}

    // Деструктор
    ~Point() {
        cout << "Точка с координатами (" << x << ", " << y << ") уничтожена." << endl;
    }

    friend float getX(const Point& p);
    friend float getY(const Point& p);

    friend float distance(const Point& p1, const Point& p2);
    friend float calculateRectangleArea(Point* points);
    friend void calculateSidesAndHypotenuse(Point* points);
};

// Дружественная функция для получения координаты X
float getX(const Point& p) {
    return p.x;
}

// Дружественная функция для получения координаты Y
float getY(const Point& p) {
    return p.y;
}

// Дружественная функция для вычисления расстояния между двумя точками
float distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

// Дружественная функция для вычисления площади прямоугольника
float calculateRectangleArea(Point* points) {
    float length = distance(points[0], points[1]);
    float width = distance(points[1], points[2]);
    return length * width; // Площадь = длина * ширина
}

// Дружественная функция для расчета длины сторон и гипотенузы
void calculateSidesAndHypotenuse(Point* points) {
    float length = distance(points[0], points[1]);
    float width = distance(points[1], points[2]);
    float hypotenuse = sqrt(pow(length, 2) + pow(width, 2));

    cout << "Длина: " << length << endl;
    cout << "Ширина: " << width << endl;
    cout << "Гипотенуза: " << hypotenuse << endl;
    cout << endl;
}

// Задание 2: Класс для представления локальной сети
class LocalNetwork {
private:
    int numberOfDevices; // Количество устройств в сети
    float installationCostPerDevice; // Стоимость установки на одно устройство

public:
    // Конструктор
    LocalNetwork(int devices, float cost) : numberOfDevices(devices), installationCostPerDevice(cost) {}

    // Метод для расчета минимальной стоимости установки
    float calculateMinimumInstallationCost() const {
        return numberOfDevices * installationCostPerDevice;
    }

    // Метод для вычисляемого показателя: стоимость на устройство
    float calculateCostPerDevice() const {
        return installationCostPerDevice;
    }

    // Деструктор
    ~LocalNetwork() {
        cout << "Объект LocalNetwork уничтожен." << endl;
    }
};

// Функция для выполнения задания 1
void task1() {
    float a, b;
    cout << "Введите длины сторон прямоугольника:\n";
    cout << "Ширина: "; cin >> a;
    cout << "Длина: "; cin >> b;

    // Создание массива из 4 объектов класса Point
    Point* rectangleVertices = new Point[4]{
        Point(0.0, 0.0),
        Point(0.0, a),
        Point(b, a),
        Point(b, 0.0)
    };

    // Вычисление площади прямоугольника
    float area = calculateRectangleArea(rectangleVertices);
    cout << "Площадь прямоугольника: " << area << endl;
    cout << endl;

    // Вычисление сторон и гипотенузы
    calculateSidesAndHypotenuse(rectangleVertices);

    // Освобождение памяти
    delete[] rectangleVertices;
}

// Функция для выполнения задания 2
void task2() {
    const int NETWORK_COUNT = 6;
    int devices;
    float costPerDevice;
    LocalNetwork* networks[NETWORK_COUNT];

    cout << "Количество устройств: ";
    cin >> devices;
    cout << "Стоимость установки на устройство: ";
    cin >> costPerDevice;

    for (int i = 0; i < NETWORK_COUNT; ++i) {
        networks[i] = new LocalNetwork(devices, costPerDevice);
    }

    // Расчет минимальной стоимости установки и вычисляемого показателя
    for (int i = 0; i < NETWORK_COUNT; ++i) {
        cout << "\nСеть " << i + 1 << ":\n";
        cout << "Минимальная стоимость установки: " << networks[i]->calculateMinimumInstallationCost() << endl;
        cout << "Стоимость на одно устройство: " << networks[i]->calculateCostPerDevice() << endl;

        // Уничтожение объекта
        delete networks[i];
    }
}

int main() {
    int choice;
    do {
        // Меню программы
        cout << "\nМеню:\n";
        cout << "1 - Прямоугольник\n";
        cout << "2 - Локальная сеть\n";
        cout << "0 - Выход\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 0:
                cout << "Выход из программы..." << endl;
                break;
            default:
                cout << "Ошибка: неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);

    return 0;
}
