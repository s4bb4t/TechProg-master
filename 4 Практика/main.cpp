#include <iostream>
#include <cmath>
using namespace std;

// Задание 1: Класс для представления точки на плоскости
class Point {
private:
    float x, y; // Закрытые переменные для координат

public:
    // Конструктор с параметрами для инициализации координат
    Point(float xCoord, float yCoord) : x(xCoord), y(yCoord) {}

    // Функции доступа к закрытым переменным
    float getX() const { return x; }
    float getY() const { return y; }

    // Деструктор, сообщающий о разрушении объекта
    ~Point() {
        cout << "Точка с координатами (" << x << ", " << y << ") уничтожена." << endl;
    }

    // Статический метод для вычисления расстояния между двумя точками
    static float distance(const Point &p1, const Point &p2) {
        return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    }
};

// Дружественная функция для вычисления площади прямоугольника
float calculateRectangleArea(Point* points) {
    float length = Point::distance(points[0], points[1]);
    float width = Point::distance(points[1], points[2]);
    return length * width; // Площадь = длина * ширина
}

// Задание 2: Класс для представления локальной сети
class LocalNetwork {
private:
    int numberOfDevices; // Количество устройств в сети
    float installationCostPerDevice; // Стоимость установки на одно устройство

public:
    // Конструктор для инициализации количества устройств и стоимости установки
    LocalNetwork(int devices, float cost) : numberOfDevices(devices), installationCostPerDevice(cost) {}

    // Метод для расчета минимальной стоимости установки
    float calculateMinimumInstallationCost() const {
        return numberOfDevices * installationCostPerDevice;
    }

    // Деструктор, сообщающий о разрушении объекта
    ~LocalNetwork() {
        cout << "Объект LocalNetwork уничтожен." << endl;
    }
};

// Функция для выполнения задания 1: вычисление площади прямоугольника
void task1() {
    float a,b;
    cout << "Введите длины сторон:" << endl;

    cout << "Ширина: "; cin >> a;
    cout << "Длина: "; cin >> b;

    // Создание массива из 4 объектов класса Point
    Point* rectangleVertices = new Point[4]{
        Point(0.0, 0.0), // Нижний левый угол
        Point(0.0, a), // Верхний левый угол
        Point(b, a), // Верхний правый угол
        Point(b, 0.0)  // Нижний правый угол
    };

    // Вычисление площади прямоугольника
    float area = calculateRectangleArea(rectangleVertices);
    cout << "Площадь прямоугольника: " << area << endl;

    // Освобождение памяти
    delete[] rectangleVertices;
}

// Функция для выполнения задания 2: расчет стоимости установки
void task2() {
    int devices;
    float costPerDevice;

    // Запрос у пользователя данных для расчета
    cout << "Введите количество устройств в сети: ";
    cin >> devices;
    cout << "Введите стоимость установки на одно устройство: ";
    cin >> costPerDevice;

    // Создание локальной сети
    LocalNetwork network(devices, costPerDevice);
    // Расчет минимальной стоимости установки
    float installationCost = network.calculateMinimumInstallationCost();
    cout << "Минимальная стоимость установки: " << installationCost << endl;
}

int main() {
    int choice;
    do {
        // Меню программы
        cout << "\nМеню:\n";
        cout << "1 - Вычислить площадь прямоугольника (Задание 1)\n";
        cout << "2 - Вычислить стоимость установки сети (Задание 2)\n";
        cout << "0 - Выход\n";
        cout << "Введите ваш выбор: ";
        cin >> choice;

        switch (choice) {
            case 1:
                task1(); // Выполнение задания 1
                break;
            case 2:
                task2(); // Выполнение задания 2
                break;
            case 0:
                cout << "Выход из программы..." << endl;
                break;
            default:
                cout << "Ошибка: неверный выбор. Попробуйте снова." << endl;
                break;
        }
    } while (choice != 0);

    return 0; // Завершение программы
}
