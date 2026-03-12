#ifndef MAIN_H
# define MAIN_H

# include <csignal>
# include "phonebook.hpp"

extern volatile sig_atomic_t g_stop;

void	search_contact(PhoneBook *phoneBook);

#endif
