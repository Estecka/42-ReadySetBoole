/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 14:33:21 by abaur             #+#    #+#             */
/*   Updated: 2022/11/13 15:12:54 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exprgen.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

extern int	main(int argc, char** argv){
	int cpxMin, cpxMax;
	std::srand(std::time(NULL) + std::clock());

	if (argc < 2)
		cpxMin = std::rand() % 20;
	else
		cpxMin = std::atoi(argv[1]);

	if (argc < 3)
		cpxMax = cpxMin;
	else
		cpxMax = std::atoi(argv[2]);

	int cpx = cpxMax - cpxMin;
	cpx = std::rand() % (cpx+1);
	cpx = cpxMin + cpx;
	
	std::cout << exprgen(cpx) << std::endl;
}
