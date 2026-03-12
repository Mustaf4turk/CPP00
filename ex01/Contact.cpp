#include "Contact.hpp"

Contact::Contact()
{
	_First_name = "";
	_Last_name = "";
	_Created = time(&_Created);
}

Contact::Contact(std::string first_name, std::string last_name, std::string nick_name,
		std::string phone_number, std::string darkest_secret)
{
	_First_name = first_name;
	_Last_name = last_name;
	_Nick_name = nick_name;
	_Phone_number = phone_number;
	_Darkest_secret = darkest_secret;
	time(&_Created);
}

Contact::~Contact()
{
	
}

std::string	Contact::getLastName() const
{
	return (_Last_name);
}

std::string	Contact::getFirst_name() const
{
	return (_First_name);
}

std::string	Contact::getNick_name() const
{
	return (_Nick_name);
}

std::string	Contact::getPhone_number() const
{
	return (_Phone_number);
}

std::string	Contact::getDarkest_secret() const
{
	return (_Darkest_secret);
}

time_t		Contact::getCreated() const
{
	return (_Created);
}
