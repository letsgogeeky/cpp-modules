#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "ostream"
# include "Contact.hpp"

class PhoneBook
{
	public:
		static const int maxContacts = 8;
		PhoneBook();
		~PhoneBook();
		const Contact searchContact(int idx);
		void showInstructions();
		void contactForm();

	private:
		int	m_count;
		int	m_currentIndex;
		Contact	m_contacts[maxContacts];
		void addContact(const Contact &contact);
};

#endif