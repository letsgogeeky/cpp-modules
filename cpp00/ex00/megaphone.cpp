/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramoussa <ramoussa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:40:33 by ramoussa          #+#    #+#             */
/*   Updated: 2023/12/14 19:51:18 by ramoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace phone
{
char	toupper(unsigned char c)
{
	return (static_cast<char>(std::toupper(c)));
}
}

int	main(int argc, const char **argv)
{
	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j];j++)
			{
				std::cout << phone::toupper(static_cast<unsigned char>(argv[i][j]));
			}
		}
	}
	std::cout << std::endl;
}
