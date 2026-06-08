#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <iomanip>
# include "Contact.hpp"

class PhoneBook
{
private:
    Contact _contacts[8];
    int     _count;
    int     _oldest;

public:
    PhoneBook();
    void addContact();
    void searchContact() const;

private:
    void printColumn(std::string str) const;
};

#endif