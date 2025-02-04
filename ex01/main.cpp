#include <iostream>
#include "PhoneBook.h"
#include "colors.h"

static void getInput(std::string &input, const char *message) {
    std::cout << message;
    std::getline(std::cin, input);
    if (std::cin.eof())
        exit(0);
}

static const auto alphaValid = [](const std::string &nickname) {
    const bool valid = std::all_of(nickname.begin(), nickname.end(), isalpha);
    if (!valid)
        std::cout << RED << "The input should be only alphabetic characters." << RESET << std::endl;
    return valid;
};

static const auto nicknameValid = [](const std::string &nickname) {
    const bool valid = std::all_of(nickname.begin(), nickname.end(), isalnum);
    if (!valid)
        std::cout << RED << "The input should be only alphanumeric characters." << RESET << std::endl;
    return valid;
};

static const auto phoneValid = [](const std::string &phone) {
    const bool valid = std::all_of(phone.begin(), phone.end(), isdigit);
    if (!valid)
        std::cout << RED << "The input should be only numeric characters." << RESET << std::endl;
    return valid;
};

static void getNonEmptyInput(std::string &input, const char *message, bool (*is_valid)(const std::string &)) {
    while(true) {
        getInput(input, message);
        if(input.empty()) {
            std::cout << RED << "Input cannot be empty." << RESET << std::endl;
            continue;
        }
        if (!is_valid || is_valid(input))
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

        getNonEmptyInput(first_name, "Enter first name: ", alphaValid);
        getNonEmptyInput(last_name, "Enter last name: ", alphaValid);
        getNonEmptyInput(nickname, "Enter nickname: ", nicknameValid);
        getNonEmptyInput(phone_number, "Enter phone number: ", phoneValid);
        getNonEmptyInput(secret, "Enter secret: ", nullptr);

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
