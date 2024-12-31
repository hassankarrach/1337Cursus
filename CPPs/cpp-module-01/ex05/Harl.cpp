/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:09:32 by hkarrach          #+#    #+#             */
/*   Updated: 2024/12/27 15:09:33 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
	std::cout << "Harl Constructor" << std::endl;
}
Harl::~Harl()
{
	std::cout << "Harl Destructor" << std::endl;
}
void Harl::complain(std::string level) {
    void (Harl::*ptr_complain[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    
    for (int i = 0; i < 4; i++) {
        if (levels[i] == level) {
            (this->*ptr_complain[i])();
            break;
        }
    }
}

void Harl::debug(void)
{
	std::cout << MAGENTA << "[DEBUG]   " << DEFAULT;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}
void Harl::info(void)
{
	std::cout << GRAY << "[INFO]    " << DEFAULT;
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}
void Harl::warning(void)
{
	std::cout << YELLOW << "[WARNING] " << DEFAULT;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}
void Harl::error(void)
{
	std::cout << RED << "[ERROR]   " << DEFAULT;
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}