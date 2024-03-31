/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramymoussa <ramymoussa@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:02:15 by ramoussa          #+#    #+#             */
/*   Updated: 2024/03/31 12:38:37 by ramymoussa       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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