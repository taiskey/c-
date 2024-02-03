#include <iostream>
#include <string>
#include <vector>

// Структура, представляющая аккаунт пользователя
struct UserAccount {
    std::string username;
    std::string password;
    std::string email;
};

// Вектор для хранения всех аккаунтов
std::vector<UserAccount> accounts;

// Функция для добавления нового аккаунта
void addAccount() {
    UserAccount newAccount;

    std::cout << "Введите имя пользователя: ";
    std::cin >> newAccount.username;

    std::cout << "Введите пароль: ";
    std::cin >> newAccount.password;

    std::cout << "Введите email: ";
    std::cin >> newAccount.email;

    accounts.push_back(newAccount);
}

// Функция для удаления существующего аккаунта
void deleteAccount() {
    std::string usernameToDelete;
    std::cout << "Введите имя пользователя для удаления: ";
    std::cin >> usernameToDelete;

    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->username == usernameToDelete) {
            accounts.erase(it);
            std::cout << "Аккаунт успешно удален\n";
            return;
        }
    }

    std::cout << "Аккаунт не найден\n";
}

// Функция для обновления информации об аккаунте
void updateAccount() {
    std::string usernameToUpdate;
    std::cout << "Введите имя пользователя для обновления: ";
    std::cin >> usernameToUpdate;

    for (auto& account : accounts) {
        if (account.username == usernameToUpdate) {
            std::cout << "Введите новый пароль: ";
            std::cin >> account.password;

            std::cout << "Введите новый email: ";
            std::cin >> account.email;

            std::cout << "Информация об аккаунте успешно обновлена\n";
            return;
        }
    }

    std::cout << "Аккаунт не найден\n";
}

// Функция для вывода информации обо всех аккаунтах
void displayAccounts() {
    for (const auto& account : accounts) {
        std::cout << "Имя пользователя: " << account.username << std::endl;
        std::cout << "Пароль: " << account.password << std::endl;
        std::cout << "Email: " << account.email << std::endl;
        std::cout << std::endl;
    }
}

int main2() {
    int choice;

    while (true) {
        std::cout << "Выберите действие:\n";
        std::cout << "1. Добавить новый аккаунт\n";
        std::cout << "2. Удалить существующий аккаунт\n";
        std::cout << "3. Обновить информацию об аккаунте\n";
        std::cout << "4. Вывести информацию обо всех аккаунтах\n";
        std::cout << "5. Выход\n";
        std::cout << "Введите номер действия: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            addAccount();
            break;
        case 2:
            deleteAccount();
            break;
        case 3:
            updateAccount();
            break;
        case 4:
            displayAccounts();
            break;
        case 5:
            std::cout << "Программа завершена\n";
            return 0;
        default:
            std::cout << "Неверный выбор\n";
            break;
        }
    }
    return 0;
}