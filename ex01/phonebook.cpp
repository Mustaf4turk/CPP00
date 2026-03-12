#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	_num_entries = 0;
	_next_index = 0;
}

PhoneBook::~PhoneBook()
{
	
}

 void PhoneBook::addContact(std::string first_name, std::string last_name, std::string nick_name,
			std::string phone_number, std::string darkest_secret)
{
	contacts[_next_index] = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);
	if (_num_entries < MAX_CONTACTS)
		_num_entries++;
	_next_index = (_next_index + 1) % MAX_CONTACTS;
}

int PhoneBook::getNumEntries()
{
	return (this->_num_entries);
}
