#include <iostream>
#include <cstdlib>

// Функция для заполнения двумерного динамического массива случайными числами от 1 до 70
void fillArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 70 + 1;
        }
    }
}

// Функция для печати двумерного динамического массива
void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Функция для вычисления суммы элементов на побочной диагонали
int sumDiagonal(int** arr, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        sum += arr[i][cols - i - 1];
    }
    return sum;
}

int main() {
    int rows, cols;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    // Выделение памяти под двумерный динамический массив
    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    fillArray(array, rows, cols);
    std::cout << "Двумерный массив:" << std::endl;
    printArray(array, rows, cols);

    int diagonalSum = sumDiagonal(array, rows, cols);
    std::cout << "Сумма элементов на побочной диагонали: " << diagonalSum << std::endl;

    // Освобождение памяти
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}