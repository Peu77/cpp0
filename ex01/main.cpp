#include <iostream>
#include "PhoneBook.h"
#include "colors.h"

PhoneBook phoneBook;

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

static void executeCommand(const std::string &command) {
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

    if (command == "SEARCH") {
        if (!phoneBook.hasContacts()) {
            std::cout << RED << "No contacts to display." << RESET << std::endl;
            return;
        }
        phoneBook.print_contacts();

        const auto isValidContactIndex = [](const std::string &index) {
            if(!std::all_of(index.begin(), index.end(), isdigit)) {
                std::cout << RED << "The input should be only numeric characters." << RESET << std::endl;
                return false;
            }

            const int i = std::stoi(index);
            if(i < 0 || i >= phoneBook.getContactsCount() || index.length() > 1) {
                std::cout << RED << "The index should be in the range of 0 to " << phoneBook.getContactsCount() - 1 << "." << RESET << std::endl;
                return false;
            }
            return true;
        };

        std::string search;
        getNonEmptyInput(search, "Enter index: ", isValidContactIndex);
        phoneBook.search_contact(search);
        return;
    }

    if (command == "EXIT")
        exit(0);

    std::cout << RED << "Invalid command." << RESET << std::endl;
}

int main() {
    while (true) {
        std::string command;
        getInput(command, "Enter command: ");

        executeCommand(command);
    }
}
