#include <iostream>
#include "PhoneBook.h"
#include "colors.h"

static void getInput(std::string &input, const char *message) {
    std::cout << message;
    std::getline(std::cin, input);
    if (std::cin.eof())
        exit(0);
}

static void getNonEmptyInput(std::string &input, const char *message, bool (*is_valid)(const std::string &)) {
    while(true) {
        getInput(input, message);
        if(input.empty()) {
            std::cout << RED << "Input cannot be empty." << RESET << std::endl;
            continue;
        }
        if (is_valid(input))
            return;
    }
}

static void executeCommand(const std::string &command, PhoneBook &phoneBook) {
    if (command == "ADD") {
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string secret;

        auto alpha_valid = [](const std::string &nickname) {
            const bool valid = std::all_of(nickname.begin(), nickname.end(), isalpha);
            if (!valid)
                std::cout << RED << "The input should be only alphabetic characters." << RESET << std::endl;
            return valid;
        };

        auto nickname_valid = [](const std::string &nickname) {
            const bool valid = std::all_of(nickname.begin(), nickname.end(), isalnum);
            if (!valid)
                std::cout << RED << "The input should be only alphanumeric characters." << RESET << std::endl;
            return valid;
        };

        auto phone_valid = [](const std::string &phone) {
            const bool valid = std::all_of(phone.begin(), phone.end(), isdigit);
            if (!valid)
                std::cout << RED << "The input should be only numeric characters." << RESET << std::endl;
            return valid;
        };

        auto empty_valid = [](const std::string &input) {
            (void) input;
            return true;
        };

        getNonEmptyInput(first_name, "Enter first name: ", alpha_valid);
        getNonEmptyInput(last_name, "Enter last name: ", alpha_valid);
        getNonEmptyInput(nickname, "Enter nickname: ", nickname_valid);
        getNonEmptyInput(phone_number, "Enter phone number: ", phone_valid);
        getNonEmptyInput(secret, "Enter secret: ", empty_valid);

        phoneBook.addContact(Contact(first_name, last_name, nickname, phone_number, secret));
        std::cout << GREEN << "Contact added successfully." << RESET << std::endl;
        return;
    }

    if (command == "PRINT") {
        phoneBook.print_contacts();
        return;
    }

    if (command == "EXIT")
        exit(0);

    std::cout << RED << "Invalid command." << RESET << std::endl;
}

int main() {
    PhoneBook phoneBook;
    while (true) {
        std::string command;
        getInput(command, "Enter command: ");

        executeCommand(command, phoneBook);
    }
}
