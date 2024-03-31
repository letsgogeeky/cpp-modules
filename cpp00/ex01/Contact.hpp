/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramymoussa <ramymoussa@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 15:02:03 by ramoussa          #+#    #+#             */
/*   Updated: 2024/03/31 12:38:51 by ramymoussa       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <string>
# include <istream>
# include <ostream>

class Contact
{

private:
	std::string	m_firstName;
	std::string	m_lastName;
	std::string	m_nickName;
	std::string	m_phoneNumber;
	std::string	m_darkestSecret;


public:
	Contact();
	~Contact();
	
	void	setFirstName(std::string firstName);
	void	setLastName(std::string lastName);
	void	setNickName(std::string nickName);
	void	setPhoneNumber(std::string phoneNumber);
	void	setDarkestSecret(std::string darkestSecret);
	bool	isComplete();
	void	displayContact(int index);

private:
	void	formatField(std::string field);

};

#endif