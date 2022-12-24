#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "./Contact.hpp"
# include <iomanip>
# include <iostream>

class PhoneBook {
	private:
		Contact contact[8];
		bool 	full;
		int 	idx;
		void	setContactField(int field_num);
		int		printPhoneBook(void);
	public:
		void add(void);
		void search(void);
		PhoneBook();
};

#endif
