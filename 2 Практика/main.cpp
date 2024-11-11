#include <iostream>
#include <limits>

using namespace std;

unsigned char globalChar;
float globalFloat;
double globalArray[5];
double globalPositiveSum = 0;
int globalSum = 0;

void sumGlobalValues() {
    cout << "Введите значение для unsigned char (0-255): ";
    int input;
    cin >> input;
    if (cin.fail() || input < 0 || input > 255) {
        cout << "Ошибка: введите значение в диапазоне от 0 до 255." << endl;
        return;
    }
    globalChar = static_cast<unsigned char>(input);

    cout << "Введите значение для float: ";
    cin >> globalFloat;

    globalSum = static_cast<int>(globalChar + globalFloat);
}

void calculateGlobalPositiveSum() {
    globalPositiveSum = 0;
    cout << "Введите 5 элементов массива типа double:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> globalArray[i];
        if (globalArray[i] > 0) {
            globalPositiveSum += globalArray[i];
        }
    }
}

int calculateLocalSum(unsigned char a, float b) {
    return static_cast<int>(a + b);
}

double calculateLocalPositiveSum(double arr[]) {
    double positiveSum = 0;
    for (int i = 0; i < 5; i++) {
        if (arr[i] > 0) {
            positiveSum += arr[i];
        }
    }
    return positiveSum;
}

int main() {
    int task, version;
    bool end = false;

    do {
        cout << "Выберите задание:\n1 - Задание 1\n2 - Задание 2\n0 - Выход\n";
        cin >> task;

        if (task == 0) {
            end = true;
            break;
        }

        if (task != 1 && task != 2) {
            cout << "Ошибка: неверный выбор задания!" << endl;
            continue;
        }

        cout << "Выберите версию:\n1 - Локальные переменные\n2 - Глобальные переменные\n";
        cin >> version;

        switch (task) {
            case 1:
                if (version == 1) {
                    unsigned char a;
                    float b;
                    cout << "Введите значение для unsigned char (0-255): ";
                    int input;
                    cin >> input;
                    if (cin.fail() || input < 0 || input > 255) {
                        cout << "Ошибка: введите значение в диапазоне от 0 до 255." << endl;
                        break;
                    }
                    a = static_cast<unsigned char>(input);

                    cout << "Введите значение для float: ";
                    cin >> b;

                    int localSum = calculateLocalSum(a, b);
                    cout << "Сумма (int): " << localSum << endl;
                } else if (version == 2) {
                    sumGlobalValues();
                    cout << "Сумма (int): " << globalSum << endl;
                } else {
                    cout << "Ошибка: неверный выбор версии!" << endl;
                }
                break;

            case 2:
                if (version == 1) {
                    double localArray[5];
                    cout << "Введите 5 элементов массива типа double:" << endl;
                    for (int i = 0; i < 5; i++) {
                        cin >> localArray[i];
                    }
                    double localPositiveSum = calculateLocalPositiveSum(localArray);
                    cout << "Сумма положительных элементов массива: " << localPositiveSum << endl;
                } else if (version == 2) {
                    calculateGlobalPositiveSum();
                    cout << "Сумма положительных элементов массива: " << globalPositiveSum << endl;
                } else {
                    cout << "Ошибка: неверный выбор версии!" << endl;
                }
                break;
        }

    } while (!end);

    return 0;
}
