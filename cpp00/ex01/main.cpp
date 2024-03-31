/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ramymoussa <ramymoussa@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:09:53 by ramoussa          #+#    #+#             */
/*   Updated: 2024/03/30 23:28:56 by ramymoussa       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>

int main(int argc, char **argv)
{
    (void)argv;
    if (argc > 1)
    {
        std::cerr << "Usage: ./phonebook\n";
        return (1);
    }
    PhoneBook phonebook;
    std::string command;
    phonebook.showInstructions();
    while (1)
    {
        std::cout << "Enter a command: ";
        std::cin >> command;
        if (command == "ADD")
        {
            phonebook.contactForm();
        }
        else if (command == "SEARCH")
        {
            int idx;
            std::cout << "Enter index: ";
            std::cin >> idx;
            Contact result = phonebook.searchContact(idx);
            result.displayContact(idx);
        }
        else if (command == "EXIT")
            break;
        else
            std::cerr << "Invalid command!\n";
    }
    return (0);
}