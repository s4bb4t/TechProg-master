#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

// Функция для вывода матрицы
void printMatrix(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // выводим звёздочки в соответствии с заданием
            if (j <= i) {
                cout << "* ";
            } else {
                cout << "  "; 
            }
        }
        cout << endl; // переход на новую строку
    }
}

// Функция для обмена слов "Zero" и "Null"
char* swapWords(const char* input) {
    size_t length = strlen(input); // определяем длину строки
    char* output = new char[length + 1]; // создаём новый массив
    strcpy(output, input); // копируем исходную строку

    // находим позиции слов "Zero" и "Null"
    char* zeroPos = strstr(output, "Zero");
    char* nullPos = strstr(output, "Null");

    // если оба слова найдены, меняем их местами
    if (zeroPos && nullPos) {
        char temp[5]; // временный массив для хранения слова
        strncpy(temp, zeroPos, 4); // копируем "Zero" во временный массив
        temp[4] = '\0'; // добавляем нулевой символ в конец

        strncpy(zeroPos, nullPos, 4); // заменяем "Zero" на "Null"
        strncpy(nullPos, temp, 4); // заменяем "Null" на "Zero"
    }

    return output; // возвращаем преобразованную строку
}

// Структура для описания предмета
struct Item {
    string name; // имя предмета
    double price; // цена предмета
};

// Функция для работы с массивом структур и записи в файл
void saveItemsToFile() {
    Item items[5] = {
        {"Предмет 1", 100.0},
        {"Предмет 2", 200.5},
        {"Предмет 3", 300.75},
        {"Предмет 4", 150.25},
        {"Предмет 5", 400.0}
    };

    // Запись в файл
    ofstream outFile("items.txt"); // открываем файл для записи
    if (outFile.is_open()) { // проверяем, открылся ли файл
        for (const auto& item : items) {
            outFile << "Имя: " << item.name << ", Цена: " << item.price << endl;
        }
        outFile.close(); // закрываем файл
        cout << "Данные о предметах записаны в файл items.txt." << endl;
    }
}

// Функция для чтения данных из файла
void readItemsFromFile() {
    ifstream inFile("items.txt"); // открываем файл для чтения
    if (!inFile) {
        cout << "Ошибка: не удалось открыть файл." << endl;
        return;
    }

    string line;
    while (getline(inFile, line)) { // считываем строки из файла
        cout << line << endl;
    }
    inFile.close(); // закрываем файл
}

// Основная функция
int main() {
    char choice;
    int task, size;

    do {
        // Меню для выбора задания
        cout << "Выберите задание:\n1 - Задание 1 (матрица)\n2 - Задание 2 (строка)\n3 - Задание 3 (предметы)\n4 - Чтение из файла\n0 - Выход\n";
        cin >> task;

        switch (task) {
            case 1:
                cout << "Введите размер матрицы: ";
                cin >> size;
                printMatrix(size); // выводим матрицу заданного размера
                break;
            case 2: {
                const char* original = "Zero Two Null"; // исходная строка
                char* transformed = swapWords(original); // вызываем функцию для преобразования
                cout << "Исходная строка: " << original << endl; // выводим исходную строку
                cout << "Преобразованная строка: " << transformed << endl; // выводим преобразованную строку
                delete[] transformed; // освобождаем память
                break;
            }
            case 3:
                saveItemsToFile(); // вызываем функцию для записи предметов в файл
                break;
            case 4:
                readItemsFromFile(); // читаем данные из файла
                break;
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Ошибка: неверный выбор задания!" << endl;
                break;
        }
    } while (task != 0);

    return 0; // завершение программы
}
