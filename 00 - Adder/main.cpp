/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:01:35 by abaur             #+#    #+#             */
/*   Updated: 2022/09/15 18:50:18 by abaur            ###   ########.fr       */
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

	ft::clog << ft::log::info << "Boop" << std::endl;
}