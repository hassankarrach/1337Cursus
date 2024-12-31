/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:09:52 by hkarrach          #+#    #+#             */
/*   Updated: 2024/12/27 15:09:53 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int getLevel(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
			return i;
	}
	return -1;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./Harl [DEBUG|INFO|WARNING|ERROR]" << std::endl;
		return 1;
	}

	Harl harl;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	std::string level = av[1];

	switch (getLevel(level))
	{
		case 0:
			harl.complain("DEBUG");
			// fall through
		case 1:
			harl.complain("INFO");
			// fall through
		case 2:
			harl.complain("WARNING");
			// fall through
		case 3:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "Invalid level" << std::endl;
			break;
	}
	
	return 0;
}