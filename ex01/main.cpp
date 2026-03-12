#include "Contact.hpp"
#include "phonebook.hpp"
#include "main.hpp"
#include <cctype>
#include <csignal>

volatile sig_atomic_t g_stop = 0;

static void sigint_handler(int)
{
	g_stop = 1;
}

static bool hasNonWhitespace(const std::string &text)
{
	for (size_t i = 0; i < text.length(); i++)
	{
		if (!isspace(static_cast<unsigned char>(text[i])))
			return true;
	}
	return false;
}

std::string getUserInput(std::string message)
{
	std::string user_input = "";

	while (!g_stop)
	{
		std::cout << message;
		if (!std::getline(std::cin, user_input))
		{
			if (g_stop)
				return "";
			return "";
		}
		if (hasNonWhitespace(user_input))
			return (user_input);
	}
	return ("");
}

static bool isValidPhoneNumber(const std::string &phone)
{
	for (size_t i = 0; i < phone.length(); i++)
	{
		if (!isdigit(static_cast<unsigned char>(phone[i])) &&
			phone[i] != '+' && phone[i] != '-' && phone[i] != ' ')
			return false;
	}
	return true;
}

void add_contact(PhoneBook *phoneBook)
{
	std::string first_name;
	std::string last_name;
	std::string nick_name;
	std::string phone_number;
	std::string darkest_secret;

	first_name = getUserInput("Enter first name: ");
	if (first_name.length() == 0)
		return;
	last_name = getUserInput("Enter last name: ");
	if (last_name.length() == 0)
		return;
	nick_name = getUserInput("Enter nick name: ");
	if (nick_name.length() == 0)
		return;
	do
	{
		phone_number = getUserInput("Enter phone number: ");
		if (phone_number.length() == 0)
			return;
		if (!isValidPhoneNumber(phone_number))
			std::cout << "Phone number can only contain digits, +, - and spaces." << std::endl;
	} while (!isValidPhoneNumber(phone_number));
	darkest_secret = getUserInput("Enter darkest secret: ");
	if (darkest_secret.length() == 0)
		return;
	phoneBook->addContact(first_name , last_name, nick_name, phone_number, darkest_secret);
}

int main(void)
{
	std::string command;
	PhoneBook phoneBook;
	struct sigaction sa;

	sa.sa_handler = sigint_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	if (sigaction(SIGINT, &sa, NULL) == -1)
		return (1);
	while (!g_stop)
	{
		std::cout << std::endl << "Type ADD to save a new contact, SEARCH to search for a contact or EXIT to exit the program" << std::endl;
		std::cout << "Enter command: ";
		if (!(std::getline(std::cin, command)))
		{
			if (g_stop)
				break;
			return (1);
		}
		if (g_stop)
			break;
		if (command.compare("ADD") == 0)
			add_contact(&phoneBook);
		else if (command.compare("SEARCH") == 0)
			search_contact(&phoneBook);
		else if(command.compare("EXIT") == 0)
			break;
	}
	if (g_stop)
		std::cout << std::endl << "Exiting..." << std::endl;
	return (0);
}
