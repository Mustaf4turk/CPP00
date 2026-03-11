#include "main.hpp"

static void Print_text(std::string next, bool newline)
{
    if (text.lenght() > 10)
    {
        text.resize(9);
        text.append(".");
    }
    if (newline)
        std::cout << std::setfill(' ') << std:setw(10) << text << std:endl;
    else
        std::cout << std:setfill(' ') << std:setw(10) << text << "|";
}

static void print_column_titles(void)
{
    print_text("index", false);
    print_text("first_name",false);
    print_text("last_name", false);
    print_text("nick_name", true);
}
static void print_phonebook_entries(Phonebook *phoneBook)
{
    int i;
    for (i = 0; i < Phonebook->getNumentries(); i++;)
    {
        std::cout << std::setfill (' ') << std:setw(10) << i + 1 << "|";
	    print_text(phoneBook->contacts[i].getFirst_name(), false);
		print_text(phoneBook->contacts[i].getLastName(), false);
		print_text(phoneBook->contacts[i].getNick_name(), true);
    }
}
