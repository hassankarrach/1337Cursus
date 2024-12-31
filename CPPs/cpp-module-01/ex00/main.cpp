/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:07:52 by hkarrach          #+#    #+#             */
/*   Updated: 2024/12/27 15:07:53 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void randomChump(std::string name);
Zombie *newZombie(std::string name);

int main()
{
	randomChump("Zoo1");
	// =======================================
	Zombie *Zombie1 = new Zombie("Zoo");
	Zombie1->announce();

	delete (Zombie1);
}