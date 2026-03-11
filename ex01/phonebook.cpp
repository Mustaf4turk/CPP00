#include "phonebook.hpp"

int search_oldest_entry(Contact contacts[MAX_CONTACTS])
{
	int oldest;
	oldest = 0;
	for(int i = 0; i < MAX_CONTACTS; i++)
	{
		if(contacts[i].getCreated() < contacts[oldest].getCreated())
			oldest = i;
	}
	return (oldest);
}

PhoneBook::PhoneBook()
{
	_num_entries = 0;
}

PhoneBook::~PhoneBook()
{
	
}

 void PhoneBook::addContact(std::string first_name, std::string last_name, std::string nick_name,
			std::string phone_number, std::string darkest_secret)
{
	if(_num_entries < MAX_CONTACTS)
	{
		contacts[_num_entries] = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);
		_num_entries++;
	}
	else
		contacts[search_oldest_entry(contacts)] = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);
}

int PhoneBook::getNumEntries()
{
	return (this->_num_entries);
}