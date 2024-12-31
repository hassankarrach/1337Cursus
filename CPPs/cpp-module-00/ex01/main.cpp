/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:38:49 by hkarrach          #+#    #+#             */
/*   Updated: 2024/12/25 15:38:50 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

static void getInput(const std::string& prompt, std::string& field, const std::string& errorMessage) {
    std::cout << prompt;
    while (!std::cin.eof()) {
        std::getline(std::cin, field);
        if (!field.empty())
            break;
        std::cout << RED << errorMessage << RESET << std::endl;
        std::cout << prompt;
    }
}

int main()
{
	PhoneBook phoneBook;
	std::string command;

	while (1 && !std::cin.eof())
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT) : ";
		std::getline(std::cin, command);
		if (command == "EXIT")
			break;
		if (command == "ADD")
		{
			Contact contact;
			std::string firstName;
			std::string lastName;
			std::string nickname;
			std::string phoneNumber;
			std::string darkestSecret;

			getInput("Enter the first name: ", firstName, "First name cannot be empty.");
			contact.setFirstName(firstName);

			getInput("Enter the last name: ", lastName, "Last name cannot be empty.");
			contact.setLastName(lastName);

			getInput("Enter the nickname: ", nickname, "Nickname cannot be empty.");
			contact.setNickname(nickname);

			getInput("Enter the phone number: ", phoneNumber, "Phone number cannot be empty.");
			contact.setPhoneNumber(phoneNumber);

			getInput("Enter the darkest secret: ", darkestSecret, "Darkest secret cannot be empty.");
			contact.setDarkestSecret(darkestSecret);

			phoneBook.addContact(contact);
		}
		else if (command == "SEARCH")
			phoneBook.searchContact();
		else
			std::cout << RED << "Invalid command." << RESET << std::endl;
	}
}