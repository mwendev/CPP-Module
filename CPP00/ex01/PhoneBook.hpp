#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# include <cstdlib>

class PhoneBook {
public:
	PhoneBook(void);
	~PhoneBook(void);

private:
	int		nb_contact;
	Contact contacts[8];

	void	print_landingpage(void);
	void	listen_input(void);
	void	add_contact(void);
	void	search_contact(void);
	void	display_preview(void);
};

#endif