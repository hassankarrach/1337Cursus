/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:09:00 by hkarrach          #+#    #+#             */
/*   Updated: 2024/12/27 15:19:51 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon* _weapon;

	public:
		// Constructors
		HumanB(std::string name);
		HumanB(std::string name, Weapon *weapon);
		
		// Destructor
		~HumanB();

		// Member Functions
		void attack();

		// Setters
		void    setWeapon( Weapon &weapon );
};

#endif