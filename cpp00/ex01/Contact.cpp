/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:02:10 by ramoussa          #+#    #+#             */
/*   Updated: 2023/12/16 15:40:50 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {
	m_firstName = "";
	m_lastName = "";
	m_phoneNumber = "";
	m_darkestSecret = "";
}

Contact::~Contact() {}

void	Contact::setFirstName(std::string firstName)
{
	m_firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	m_lastName = lastName;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	m_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	m_darkestSecret = darkestSecret;
}

bool	Contact::isComplete()
{
	if (m_firstName.empty() || m_lastName.empty() || \
		m_phoneNumber.empty() || m_darkestSecret.empty())
		return (false);
	return (true);
}