/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:01:35 by abaur             #+#    #+#             */
/*   Updated: 2022/09/23 19:05:35 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./gray_code.hpp"
#include "../logutil/logutil.hpp"

#include <iostream>
#include <cstdlib>

/*
 * Curtesy of https://en.wikipedia.org/wiki/Gray_code#Converting_to_and_from_Gray_code
 */
static unsigned int	GrayToBin(unsigned int n){
	unsigned int mask = n;

	while (mask) {
		mask >>= 1;
		n ^= mask;
	}
	return n;
}

static std::string	ToBin(unsigned int n){
	std::string bin = "";

	for (n; n; n>>=1) {
		if (n & 1)
			bin = "1"+bin;
		else
			bin = "0"+bin;
	}
	return bin.size() ? bin : "0";
}

extern int	main(int argc, char** argv){
	for (int i=1; i<argc; i++) {
		unsigned int n = std::atoi(argv[i]);
		unsigned int r = gray_code(n);
		unsigned int ok = GrayToBin(r);

		const char* COLOR = (n == ok) ? LOG_GREEN : LOG_BOLD_RED;
		std::cout << "  ┌ " << n << " -> " << COLOR << r << LOG_CLEAR << std::endl
		          << " ┌─ " << ToBin(n) << std::endl
		          << " └> " << COLOR << ToBin(r) << LOG_CLEAR << std::endl;
		if (n != ok)
			std::cout << LOG_RED"\tThis is gray code for : " << ok << " ─ " << ToBin(ok) << LOG_CLEAR << std::endl;
	}
}