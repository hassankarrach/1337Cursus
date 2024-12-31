/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkarrach <hkarrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:08:19 by hkarrach          #+#    #+#             */
/*   Updated: 2024/12/27 15:11:50 by hkarrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name);

int main()
{
	int n = 20;
	Zombie *Hord = zombieHorde(n, "Hord");

	if (Hord == NULL)
	{
		std::cout << "Error: create zombie horde failed" << std::endl;
		return 1;
	}
	
	// Announce each zombie
	for (int i = 0; i < n; i++)
		Hord[i].announce();
		
	delete [] Hord;
}