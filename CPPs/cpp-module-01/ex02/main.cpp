/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:08:49 by hkarrach          #+#    #+#             */
/*   Updated: 2024/12/27 15:08:50 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iostream"

int main()
{
	std::string str = "HI THIS IS BRAIN";

	// Pointer to string
	std::string *stringPTR = &str;
	// Reference to string
	std::string &stringREF = str;

	// ===================== Display =====================
	std::cout << "Address of string   : " << &str << std::endl;
	std::cout << "Address of stringPTR: " << stringPTR << std::endl;
	std::cout << "Address of stringREF: " << &stringREF << std::endl;
	// ===================== Display =====================
	std::cout << "String   : " << str << std::endl;
	std::cout << "StringPTR: " << *stringPTR << std::endl;
	std::cout << "StringREF: " << stringREF << std::endl;
}