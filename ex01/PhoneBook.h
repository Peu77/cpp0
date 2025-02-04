

#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#define MAX_CONTACTS 8

#include "Contact.h"

class PhoneBook {
public:
    PhoneBook();

    void addContact(const Contact &contact);
    void search_contact(const std::string &search);
    void print_contacts() const;

private:
    Contact contacts[MAX_CONTACTS];
    int contacts_count;
};



#endif //PHONEBOOK_H
