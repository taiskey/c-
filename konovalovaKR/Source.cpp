
#include <iostream>
#include <cstdlib>
#include <ctime>

// ���������� ���������� ������������� ������� ���������� �������
void fillArray(int** array, int rows, int cols) {
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = rand() % 70 + 1; //  ��������� ����� �� 1 �� 70
        }
    }
}

// ����� ���������� ������������� ������� �� �����
void printArray(int** array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// ������� ��� ���������� ����� ��������� �� �������� ���������
int calculateSecondaryDiagonalSum(int** array, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        sum += array[i][cols - i - 1];
    }
    return sum;
}

int main() {
    int rows, cols;
    
    // ���� ���������� ����� � ��������
    std::cout << "Enter the number of rows and columns: ";
    std::cin >> rows >> cols;
    
    // ��������� ������ ��� ��������� ������
    int** array = new int*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new int[cols];
    }
    
    // ���������� � ����� �������
    fillArray(array, rows, cols);
    std::cout << "The Array: " << std::endl;
    printArray(array, rows, cols);
    
    // ���������� � ����� ����� ��������� �� �������
    int diagonalSum = calculateSecondaryDiagonalSum(array, rows, cols);
    std::cout << "The sum of the elements on the side diagonal:" << diagonalSum << std::endl;
    
   
    for (int i = 0; i < rows; i++) {
        delete[] array[i];
    }
    delete[] array;
    
    return 0;
}