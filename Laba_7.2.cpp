#include <iostream>
#include <cmath>
#include <stdarg.h>
#include <stdio.h>

using namespace std;

double sideLength(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2)); // нахождение длины стороны по координатам его точек
}

double square(int x1, int y1, int x2, int y2, int x3, int y3) {
    double a = sideLength(x1, y1, x2, y2);
    double b = sideLength(x2, y2, x3, y3);
    double c = sideLength(x3, y3, x1, y1);

    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c)); // вычисление площади по формуле Герона
}

double square1(int n, ...) {
    // Получение параметров с помощью переменного числа аргументов
    va_list arguments;
    va_start(arguments, n);

    // Инициализация переменных для хранения данных о диагонали с наибольшей длиной и площади
    double maxDiagonalDistance = 0;
    double maxDiagonalArea = 0;


    int a[100];
    for (int i = 0; i < n * 2; ++i)
    {
        a[i] = va_arg(arguments, int);
    }
    // Перебор вершин для нахождения диагонали с наибольшей длиной и её площади
    for (int i = 0; i < n * 2 - 3; i = i + 2) { // Перебор координат первой точки
        int x1 = a[i];                  // для нахождения наибольшей диагонали
        int y1 = a[i + 1];
        for (int j = i + 2; j < n * 2 - 1; j = j + 2) // Перебор координат второй точки
        {
            int x2 = a[j]; // Координаты второй точки
            int y2 = a[j + 1];
            if (sideLength(x1, y1, x2, y2) > maxDiagonalDistance) // Если длина новой найденой диаонали больше предыдущей
            {
                maxDiagonalArea = 0; // Значение максимальной площади обнуляется, для нахождения площади треугольника с нужной диагональю
                maxDiagonalDistance = sideLength(x1, y1, x2, y2); // Значение диагонали обновляется
                for (int p = 0; p < n * 2 - 2; p = p + 2) // Находится наибольшая площадь для треугольника с нужной диагональю
                {
                    int x3 = a[p]; // Перебор третьей точки для нахождения площади
                    int y3 = a[p + 1];
                    {
                        if (maxDiagonalArea < square(x1, y1, x2, y2, x3, y3))
                            maxDiagonalArea = square(x1, y1, x2, y2, x3, y3);
                    }
                }
            }


        }
    }
    va_end(arguments);
    return maxDiagonalArea;
}
        

int main() {
    setlocale(LC_ALL, "Ru");
    cout << "Длина стороны: " << sideLength(1, 1, 4, 5) << endl;
    cout << "Площадь треугольника: " << square(0, 0, 0, 5, 5, 0) << endl;
    int n;
    cout << "Введите количество вершин у многоугольника: ";
    cin >> n;
    cout << "Площадь треугольника, содержащего диагональ наибольшей длины выпуклого многоугольника: " << square1(n, 0, 0, 0, 4, 3, 0, 5, 5) << endl;

    return 0;
}
