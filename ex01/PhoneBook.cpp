#include "PhoneBook.h"

#include <iomanip>
#include <iostream>
#include <string>
#include "colors.h"


PhoneBook::PhoneBook(): contacts_count(0) {
    for (auto &contact: this->contacts)
        contact = Contact();
}

void PhoneBook::addContact(const Contact &contact) {
    this->contacts[this->contacts_count] = contact;

    this->contacts_count++;
    if (this->contacts_count == MAX_CONTACTS)
        this->contacts_count = 0;
}

void PhoneBook::print_contacts() const {
    if (!this->contacts[0].hasName()) {
        std::cout << "No contacts to display." << std::endl;
        return;
    }

    std::string headers[] = {"Index", "First Name", "Last Name", "Nickname"};

    for (const std::string &header: headers) {
        std::cout << std::setw(10) << std::right << header;
        if (&header == &headers[3])
            std::cout << std::endl;
        else
            std::cout << "|";
    }

    std::cout << std::string(50, '-') << std::endl;

    for (int i = 0; i < this->contacts_count; i++)
        this->contacts[i].printAsColumn(i);
}

void PhoneBook::search_contact(const std::string &search) const {
    const int index = std::stoi(search);
    this->contacts[index].printFull();
}

