#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int pin = 9876, entered_pin, option, count = 0, amount = 1;
    float balance = 8765;
    int continue_transaction = 1;

    std::time_t now = std::time(0);
    std::cout << "\n\t\t\t\t\t       " << std::ctime(&now);
    std::cout << "\n\t\t\t******************WELCOME TO ATM MANAGEMENT SYSTEM*******************";

    while (pin != entered_pin) {
        std::cout << "\nPlease enter your pin :";
        std::cin >> entered_pin;

        if (entered_pin != pin) {
            std::cout << "Invalid pin!!!\n";
            count++;

            if (count == 3 && pin != entered_pin) {
                exit(0);
            }
        }
    }

    while (continue_transaction != 0) {
        std::cout << "\n\t\t\t*************Available Transaction************";
        std::cout << "\n\n\t\t1.Withdrawal";
        std::cout << "\n\t\t2.Deposit";
        std::cout << "\n\t\t3.Check Balance";
        std::cout << "\n\n\t4.Please select the option :";
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "\n\t\tEnter the amount : ";
                std::cin >> amount;

                if (balance < amount) {
                    std::cout << "\n\t Sorry insufficient balance\n";
                    amount = 1;
                } else {
                    balance -= amount;
                    std::cout << "\n\t\tYou have withdrawn Rs." << amount << ". Your new balance is " << balance;
                    amount = 1;
                }
                break;

            case 2:
                std::cout << "\n\t\t Please enter the amount : ";
                std::cin >> amount;
                balance += amount;
                std::cout << "\n\t\tYou have deposited Rs." << amount << ". Your new balance is " << balance;
                std::cout << "\n\t\t****************** Thank you for banking with Code with Curious******************";
                amount = 1;
                break;

            case 3:
                std::cout << "\n\t\t Your balance is Rs." << balance;
                break;

            default:
                std::cout << "\n\t\tInvalid Option!!! Please select a valid option.";
                break;
        }

        std::cout << "\n\t\tDo you wish to perform another transaction? Press 1 [Yes], 0 [No]";
        std::cin >> continue_transaction;
    }

    return 0;
}
