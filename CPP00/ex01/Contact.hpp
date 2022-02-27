#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>
# include <iomanip>

class Contact {
public:
	Contact(void);
	~Contact(void);

	int		create_contact(int index);
	int		error_create(int empty, int not_digit);
	void	print_preview();
	int		print_contact(int index);

private:
	int			index;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string number;
	std::string secret;

	std::string	format(std::string str);
};

#endif