
#include <iostream>
#include <cstdlib>
#include <ctime>

// заполнение двумерного динамического массива случайными числами
void fillArray(int** array, int rows, int cols) {
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = rand() % 70 + 1; //  случайное число от 1 до 70
        }
    }
}

// вывод двумерного динамического массива на экран
void printArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Функция для вычисления суммы элементов на побочной диагонали
int calculateSecondaryDiagonalSum(int** array, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += array[i][cols - i - 1];
    }
    return sum;
}

int main() {
    int rows, cols;
    
    // Ввод количества строк и столбцов
    std::cout << "Enter the number of rows and columns: ";
    std::cin >> rows >> cols;
    
    // Выделение памяти под двумерный массив
    int** array = new int*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }
    
    // Заполнение и вывод массива
    fillArray(array, rows, cols);
    std::cout << "The Array: " << std::endl;
    printArray(array, rows, cols);
    
    // Вычисление и вывод суммы элементов на побочке
    int diagonalSum = calculateSecondaryDiagonalSum(array, rows, cols);
    std::cout << "The sum of the elements on the side diagonal:" << diagonalSum << std::endl;
    
   
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
    
    return 0;
}