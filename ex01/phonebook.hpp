#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <string>
# include <iomanip>

# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
	private:
		int _num_entries;
		int _next_index;

	public:
		Contact contacts[MAX_CONTACTS];

		PhoneBook();
		~PhoneBook();

		void addContact(std::string first_name, std::string last_name, std::string nick_name,
						std::string phone_number, std::string darkest_secret);
		int getNumEntries();
};

#endif
