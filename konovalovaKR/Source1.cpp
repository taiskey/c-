#include <iostream>
#include <cstdlib>

// ������� ��� ���������� ���������� ������������� ������� ���������� ������� �� 1 �� 70
void fillArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 70 + 1;
        }
    }
}

// ������� ��� ������ ���������� ������������� �������
void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// ������� ��� ���������� ����� ��������� �� �������� ���������
int sumDiagonal(int** arr, int rows, int cols) {
    int sum = 0;
    for (int i = 0; i < rows; ++i) {
        sum += arr[i][cols - i - 1];
    }
    return sum;
}

int main() {
    int rows, cols;
    std::cout << "������� ���������� �����: ";
    std::cin >> rows;
    std::cout << "������� ���������� ��������: ";
    std::cin >> cols;

    // ��������� ������ ��� ��������� ������������ ������
    int** array = new int* [rows];
    for (int i = 0; i < rows; ++i) {
        array[i] = new int[cols];
    }

    fillArray(array, rows, cols);
    std::cout << "��������� ������:" << std::endl;
    printArray(array, rows, cols);

    int diagonalSum = sumDiagonal(array, rows, cols);
    std::cout << "����� ��������� �� �������� ���������: " << diagonalSum << std::endl;

    // ������������ ������
    for (int i = 0; i < rows; ++i) {
        delete[] array[i];
    }
    delete[] array;

    return 0;
}