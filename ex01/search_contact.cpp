#include <sstream>
#include "main.hpp"

static void print_text(std::string text, bool newline)
{
	if (text.length() > 10)
	{
		text.resize(9);
		text.append(".");
	}
	if (newline)
		std::cout << std::setfill(' ') << std::setw(10) << text << std::endl;
	else
		std::cout << std::setfill(' ') << std::setw(10) << text << "|";
}

static void print_column_titles(void)
{
	print_text("index", false);
	print_text("first_name", false);
	print_text("last_name", false);
	print_text("nick_name", true);
}

static void print_contact(Contact contact)
{
	std::cout << "First name: " << contact.getFirst_name() << std::endl;
	std::cout << "Last name: " << contact.getLastName() << std::endl;
	std::cout << "Nick name: " << contact.getNick_name() << std::endl;
	std::cout << "Phone number: " << contact.getPhone_number() << std::endl;
	std::cout << "Darkest secret: " << contact.getDarkest_secret() << std::endl;
}

static void print_phonebook_entries(PhoneBook *phoneBook)
{
	int i;
	for (i = 0; i < phoneBook->getNumEntries(); i++)
	{
		std::cout << std::setfill(' ') << std::setw(10) << i + 1 << "|";
		print_text(phoneBook->contacts[i].getFirst_name(), false);
		print_text(phoneBook->contacts[i].getLastName(), false);
		print_text(phoneBook->contacts[i].getNick_name(), true);
	}
}

void search_contact(PhoneBook *phoneBook)
{
	std::string	line;
	if (phoneBook->getNumEntries() == 0)
	{
		std::cout << "Phonebook is empty." << std::endl;
		return;
	}
	int index = 0;
	print_column_titles();
	print_phonebook_entries(phoneBook);
	std::cout << "Enter index: ";
	if (!std::getline(std::cin, line))
	{
		std::cin.clear();
		if (g_stop)
			return;
		std::cout << "Invalid index" << std::endl;
	}
	else
	{
		std::istringstream iss(line);
		if (!(iss >> index) || (iss >> std::ws, !iss.eof()))
			std::cout << "Invalid index" << std::endl;
		else if (index > 0 && index <= phoneBook->getNumEntries())
			print_contact(phoneBook->contacts[index - 1]);
		else
			std::cout << "Invalid index" << std::endl;
	}
}
