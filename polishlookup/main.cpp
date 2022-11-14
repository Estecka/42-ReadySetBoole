/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 19:02:28 by abaur             #+#    #+#             */
/*   Updated: 2022/11/14 17:42:29 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PolishLookup.hpp"

#include <iostream>

extern int main(int argc, char** argv){
	for (int i=1; i<argc; i++){
		JumpString table;
		CreateLookup(argv[i], table);

		std::cout << argv[i] << '\n'
		          << table   << '\n'
		          << std::endl;
	}
}
