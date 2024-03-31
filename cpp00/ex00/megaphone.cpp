/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramymoussa <ramymoussa@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:40:33 by ramoussa          #+#    #+#             */
/*   Updated: 2024/03/30 22:48:11 by ramymoussa       ###   ########.fr       */
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
				if (std::isalpha(argv[i][j]))
					std::cout << phone::toupper(static_cast<unsigned char>(argv[i][j]));
				else
					std::cout << argv[i][j];
			}
		}
	}
	std::cout << std::endl;
}
