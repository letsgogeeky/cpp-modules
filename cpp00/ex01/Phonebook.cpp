/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:02:13 by ramoussa          #+#    #+#             */
/*   Updated: 2024/04/05 16:58:21 by ramoussa         ###   ########.fr       */
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

void PhoneBook::contactForm()
{
	Contact contact;
	std::string input;
	std::cout << "Enter first name: ";
	std::cin >> input;
	contact.setFirstName(input);
	std::cout << "Enter last name: ";
	std::cin >> input;
	contact.setLastName(input);
	std::cout << "Enter nickname: ";
	std::cin >> input;
	contact.setNickName(input);
	std::cout << "Enter phone number: ";
	std::cin >> input;
	contact.setPhoneNumber(input);
	std::cout << "Enter darkest secret: ";
	std::cin >> input;
	contact.setDarkestSecret(input);
	addContact(contact);
	std::cout << "---------------------------------------------\n";
	std::cout << "Contact added successfully!\n";
	std::cout << "There are " << m_count << " contacts in the phonebook.\n";
	std::cout << "---------------------------------------------\n";
}

const Contact PhoneBook::searchContact(int idx)
{
	if (idx >= maxContacts || idx < 0 || idx >= m_count)
	{
		std::cerr << "List index out of range!" << std::endl;
		std::cerr << "There are " << m_count << " contacts to search in." << std::endl;
	}
	if (idx > m_currentIndex)
	{
		std::cerr << "List index out of range!";
		std::cerr << "There are " << m_count << " contacts to search in.";
	}
	return m_contacts[idx];
}

void PhoneBook::showInstructions()
{
	std::cout << "Instructions:\n";
	std::cout << "ADD: Add a new contact\n";
	std::cout << "SEARCH: Search for a contact\n";
	std::cout << "EXIT: Exit the phonebook\n";
}
