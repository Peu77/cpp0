#include "PhoneBook.h"

#include <iomanip>
#include <iostream>
#include <string>
#include "colors.h"


PhoneBook::PhoneBook(): contacts_index(0) {
    for (auto &contact: this->contacts)
        contact = Contact();
}

void PhoneBook::addContact(const Contact &contact) {
    this->contacts[this->contacts_index] = contact;

    this->contacts_index++;
    if (this->contacts_index == MAX_CONTACTS)
        this->contacts_index = 0;
    if(this->contacs_count < MAX_CONTACTS)
        this->contacs_count++;
}

void PhoneBook::print_contacts() const {
    std::string headers[] = {"Index", "First Name", "Last Name", "Nickname"};

    for (const std::string &header: headers) {
        std::cout << std::setw(10) << std::right << header;
        if (&header == &headers[3])
            std::cout << std::endl;
        else
            std::cout << "|";
    }

    std::cout << std::string(50, '-') << std::endl;

    for (int i = 0; i < this->contacs_count; i++)
        this->contacts[i].printAsColumn(i);
}

void PhoneBook::search_contact(const std::string &search) const {
    const int index = std::stoi(search);
    this->contacts[index].printFull();
}

bool PhoneBook::hasContacts() const {
    return this->contacts[0].hasName();
}

int PhoneBook::getContactsCount() const {
    return this->contacs_count;
}


