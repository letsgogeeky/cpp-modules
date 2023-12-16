/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:02:15 by ramoussa          #+#    #+#             */
/*   Updated: 2023/12/16 16:07:22 by ramoussa         ###   ########.fr       */
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
		void addContact(const Contact &contact);
		const Contact searchContact(int idx);
	
	private:
		int	m_count;
		int	m_currentIndex;
		Contact	m_contacts[maxContacts];
};

#endif