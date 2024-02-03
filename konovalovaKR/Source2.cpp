#include <iostream>
#include <string>
#include <vector>

// ���������, �������������� ������� ������������
struct UserAccount {
    std::string username;
    std::string password;
    std::string email;
};

// ������ ��� �������� ���� ���������
std::vector<UserAccount> accounts;

// ������� ��� ���������� ������ ��������
void addAccount() {
    UserAccount newAccount;

    std::cout << "������� ��� ������������: ";
    std::cin >> newAccount.username;

    std::cout << "������� ������: ";
    std::cin >> newAccount.password;

    std::cout << "������� email: ";
    std::cin >> newAccount.email;

    accounts.push_back(newAccount);
}

// ������� ��� �������� ������������� ��������
void deleteAccount() {
    std::string usernameToDelete;
    std::cout << "������� ��� ������������ ��� ��������: ";
    std::cin >> usernameToDelete;

    for (auto it = accounts.begin(); it != accounts.end(); ++it) {
        if (it->username == usernameToDelete) {
            accounts.erase(it);
            std::cout << "������� ������� ������\n";
            return;
        }
    }

    std::cout << "������� �� ������\n";
}

// ������� ��� ���������� ���������� �� ��������
void updateAccount() {
    std::string usernameToUpdate;
    std::cout << "������� ��� ������������ ��� ����������: ";
    std::cin >> usernameToUpdate;

    for (auto& account : accounts) {
        if (account.username == usernameToUpdate) {
            std::cout << "������� ����� ������: ";
            std::cin >> account.password;

            std::cout << "������� ����� email: ";
            std::cin >> account.email;

            std::cout << "���������� �� �������� ������� ���������\n";
            return;
        }
    }

    std::cout << "������� �� ������\n";
}

// ������� ��� ������ ���������� ��� ���� ���������
void displayAccounts() {
    for (const auto& account : accounts) {
        std::cout << "��� ������������: " << account.username << std::endl;
        std::cout << "������: " << account.password << std::endl;
        std::cout << "Email: " << account.email << std::endl;
        std::cout << std::endl;
    }
}

int main2() {
    int choice;

    while (true) {
        std::cout << "�������� ��������:\n";
        std::cout << "1. �������� ����� �������\n";
        std::cout << "2. ������� ������������ �������\n";
        std::cout << "3. �������� ���������� �� ��������\n";
        std::cout << "4. ������� ���������� ��� ���� ���������\n";
        std::cout << "5. �����\n";
        std::cout << "������� ����� ��������: ";
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
            std::cout << "��������� ���������\n";
            return 0;
        default:
            std::cout << "�������� �����\n";
            break;
        }
    }
    return 0;
}