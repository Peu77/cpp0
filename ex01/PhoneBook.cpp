#include "PhoneBook.h"

#include <iomanip>
#include <iostream>
#include <string>
#include "colors.h"



PhoneBook::PhoneBook(): contacts_count(0) {
    for(auto & contact : this->contacts)
        contact = Contact();
}

void PhoneBook::addContact(const Contact &contact) {
    this->contacts[this->contacts_count] = contact;

    if (this->contacts_count < 8)
        this->contacts_count++;
}

void PhoneBook::print_contacts() const {
    if(this->contacts_count == 0) {
        std::cout << "No contacts to display." << std::endl;
        return;
    }

    std::string headers[] = {"Index", "First Name", "Last Name", "Nickname"};

    for(const std::string& header : headers) {
        std::cout << std::setw(10) << std::right << header;
        if(&header == &headers[3])
            std::cout << std::endl;
        else
            std::cout << "|";
    }

    std::cout << std::string(50, '-') << std::endl;

    for (int i = 0; i < this->contacts_count; i++)
        this->contacts[i].printInfo(i);
}
