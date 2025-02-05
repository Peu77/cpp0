

#include "Contact.h"

#include <iomanip>
#include <iostream>
#include "colors.h"

Contact::Contact()
{
}

Contact::Contact(const std::string &first_name,
                 const std::string &last_name,
                 const std::string &nickname,
                 const std::string &phone_number,
                 const std::string &secret): first_name(first_name),
                                             last_name(last_name),
                                             nickname(nickname),
                                             phone_number(phone_number),
                                             secret(secret)
{
}

void Contact::printAsColumn(const int id) const {
    auto formatField = [](const std::string &field) {
        if (field.length() > 9)
            return field.substr(0, 9) + ".";
        return field;
    };

    std::string columns[] = {std::to_string(id), first_name, last_name, nickname};

    for(const std::string& column : columns) {
        std::cout << std::setw(10) << std::right << formatField(column);
        if(&column == &columns[3])
            std::cout << std::endl;
        else
            std::cout << "|";
    }
}

void Contact::printFull() const {
    std::cout << std::string(50, '-') << std::endl;
    std::cout << "First Name: " << GREEN << first_name << RESET << std::endl;
    std::cout << "Last Name: " << GREEN << last_name << RESET << std::endl;
    std::cout << "Nickname: " << GREEN << nickname << RESET << std::endl;
    std::cout << "Phone Number: " << GREEN << phone_number << RESET << std::endl;
    std::cout << "Secret: " << GREEN << secret << RESET << std::endl;
    std::cout << std::string(50, '-') << std::endl;
}

bool Contact::hasName() const {
    return !first_name.empty();
}



