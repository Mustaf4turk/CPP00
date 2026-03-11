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


static void print_phonebook_entires(Phonebook *phonebook)
{
    int i;
    for (i = 0; i < phonebook->getnumentries();i++;)
    {
        std::cout() << std::setfill(' ') << std:setw(10) << i + 1 << "|";
        print_text(phonebook->contacts[i].getFirstname(), false);
        print_text(phonebook->contacts[i].getLastname(), false);
        print_text(phonebook->contacts[i].getNickname(), true);
    }
}

void search_contact(PhoneBook *phoneBook)
{
	int index = 0;
	print_column_titles();
	print_phonebook_entries(phoneBook);
	std::cout << "Enter index: ";
	if (!(std::cin >> index))
	{
		std::cout << "Invalid index" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
    else if (index > 0 && index <= phonebook->getNumentries())
    {
        print.contact(phonebook->contacts[index - 1]);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
    {
        std::cout << "invalid index" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}