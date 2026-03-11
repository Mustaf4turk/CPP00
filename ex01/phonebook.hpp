#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

#include "Contact.hpp"

#define MAX_CONTACS 8


class phonebook 
{
    private:
    int     num_entries:

    public:
    contact contacts[MAX_CONTACS];

    Phonebook();
    ~Phonebook();

    void addContact(stdd::string firstname,stdd::string lastname, stdd:string Darkest_secret, stdd::string nick_name
                    stdd:string phone_number);
    int getNumEntries();
};

int search_oldiest_entrie(contac contacts[MAX_CONTACS]);

#endif