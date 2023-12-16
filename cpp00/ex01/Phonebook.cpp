/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:02:13 by ramoussa          #+#    #+#             */
/*   Updated: 2023/12/16 16:11:40 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include "iostream"

PhoneBook::PhoneBook()
{
	m_count = 0;
	m_currentIndex = 0;
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::addContact(const Contact &contact)
{
	m_contacts[m_currentIndex] = contact;
	m_currentIndex = (m_currentIndex + 1) % maxContacts;
	if (m_count < maxContacts)
		m_count++;
}

const Contact PhoneBook::searchContact(int idx)
{
	if (idx >= maxContacts || idx < 0)
		std::cerr << "List index out of range!";
	if (idx > m_currentIndex)
		std::cerr << "List index out of range!";
		std::cerr << "There are " << m_count << " contacts to search in.";
	return m_contacts[idx];
}
