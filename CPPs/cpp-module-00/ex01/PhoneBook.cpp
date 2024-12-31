/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:38:54 by hkarrach          #+#    #+#             */
/*   Updated: 2024/12/25 15:38:55 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->nbContacts = 0;
	std::cout << BLUE << "=== Welcome to your phone book! ===" << RESET << std::endl;
}

PhoneBook::~PhoneBook()
{
	std::cout << RED << "=== Goodbye! ===" << RESET << std::endl;
}

void PhoneBook::addContact(const Contact &contact)
{
	if (this->nbContacts < 8)
	{
		this->contacts[this->nbContacts] = contact;
		std::cout << GREEN << "Contact added successfully." << RESET << std::endl;
	}
	else
	{
		this->contacts[this->nbContacts % 8] = contact;
		std::cout << YELLOW << "Note : The phone book is full. The oldest contact has been replaced." << RESET << std::endl;
	}
	this->nbContacts++;
}

void PhoneBook::searchContact()
{
	int i = 0;
	std::string index;

	if (this->nbContacts == 0)
	{
		std::cout << YELLOW << "No contacts to search for." << RESET << std::endl;
		return;
	}

	this->printContacts();
	std::cout << "Enter the index of the contact you want to see: ";
	std::getline(std::cin, index);
	if (index.length() != 1 || index[0] < '0' || index[0] > '7')
	{
		std::cout << RED << "Invalid index." << RESET << std::endl;
		return;
	}
	if (index[0] - '0' >= this->nbContacts)
	{
		std::cout << RED << "No contact at this index." << RESET << std::endl;
		return;
	}
	i = index[0] - '0';
	this->contacts[i].printContact();
}

void PhoneBook::printContacts()
{
	std::string firstName;
	std::string lastName;
	std::string nickname;

	std::cout << BLUE << "     index|first name| last name|  nickname" << RESET << std::endl;
	for (int i = 0; i < std::min(this->nbContacts, 8); i++)
	{
		firstName = this->contacts[i].getFirstName();
		lastName = this->contacts[i].getLastName();
		nickname = this->contacts[i].getNickname();
		if (firstName.length() > 10)
			firstName = firstName.substr(0, 9) + ".";
		if (lastName.length() > 10)
			lastName = lastName.substr(0, 9) + ".";
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << i << BLUE << "|" << RESET;
		std::cout << std::setw(10) << firstName << BLUE << "|" << RESET;
		std::cout << std::setw(10) << lastName << BLUE << "|" << RESET;
		std::cout << std::setw(10) << nickname << std::endl;
	}
}
