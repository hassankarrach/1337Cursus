/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 15:38:58 by hkarrach          #+#    #+#             */
/*   Updated: 2024/12/25 15:38:59 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include "Contact.hpp"
#include <iomanip>

class PhoneBook
{
private:
	Contact contacts[8];
	int nbContacts;

public:
	PhoneBook();
	~PhoneBook();
	void addContact(const Contact &contact);
	void searchContact();
	void printContacts();
};

#endif