/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:09:11 by hkarrach          #+#    #+#             */
/*   Updated: 2024/12/27 15:54:36 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
}
HumanB::HumanB(std::string name, Weapon *weapon) : _name(name), _weapon(weapon)
{
}
HumanB::~HumanB()
{
}

void HumanB::attack()
{
	if (!this->_weapon || this->_weapon->getType().empty())
	{
		std::cout << this->_name << " has no weapon to attack with" << std::endl;
		return;
	}
	else
		std::cout << this->_name << " attacks with a " << this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
	std::cout << this->_name << " has acquired a " << weapon.getType() << std::endl;
}