#include "Contact.hpp"
#include <iostream>

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

void	Contact::setNickName(std::string nickName)
{
	m_nickName = nickName;
}

bool	Contact::isComplete()
{
	if (m_firstName.empty() || m_lastName.empty() || \
		m_phoneNumber.empty() || m_darkestSecret.empty())
		return (false);
	return (true);
}

void Contact::formatField(std::string field)
{
	if (field.length() > 10)
		std::cout << field.substr(0, 9) << ".";
	else
		std::cout << field;
	if (field.length() < 10)
	{
		for (int i = 0; i < 10 - (int)field.length(); i++)
			std::cout << " ";
	}
}

void	Contact::displayContact(int index)
{
	std::cout << index;
	for (int i = 0; i < 9; i++)
		std::cout << " ";
	std::cout << "|";
	this->formatField(this->m_firstName);
	std::cout << "|";
	this->formatField(this->m_lastName);
	std::cout << "|";
	this->formatField(this->m_nickName);
	std::cout << std::endl;
}