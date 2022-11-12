/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:02:28 by abaur             #+#    #+#             */
/*   Updated: 2022/11/12 21:26:04 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PolishLookup.hpp"

#include <iostream>

extern int main(int argc, char** argv){
	for (int i=1; i<argc; i++){
		JumpString table;
		CreateLookup(argv[i], table);

		std::cout << argv[i] << std::endl;
		for (size_t j=0; j<table.length(); j++)
		if (table[j]){
			if (table[j] < -9)
				std::cout << (char)('a' - 10 - table[j]);
			else
				std::cout << -table[j];
		}
		else
			std::cout << '_';
		std::cout << '\n' << std::endl;
	}
}
