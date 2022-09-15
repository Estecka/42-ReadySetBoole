/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:01:35 by abaur             #+#    #+#             */
/*   Updated: 2022/09/15 19:28:30 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./adder.hpp"
#include "../logutil/logutil.hpp"

#include <iostream>
#include <cstdlib>

extern int	main(int argc, char** argv){
	if (argc < 3) {
		std::cout << "Not enough arguments" << std::endl;
		return 1;
	}

	unsigned int a = atoi(argv[1]);
	for (int i=2; i<argc; i++) {
		unsigned int b = atoi(argv[i]);
		std::cout << a << " + " << b << " = " << std::flush;

		unsigned int r = adder(a, b);
		unsigned int ok = a + b;
		if (r == ok)
			std::cout << LOG_GREEN << r << LOG_CLEAR << std::endl;
		else
			std::cout << LOG_BOLD_RED << r << std::endl
			          << "\tExpected: " << ok << LOG_CLEAR << std::endl;
		
		a = ok;
	}
}