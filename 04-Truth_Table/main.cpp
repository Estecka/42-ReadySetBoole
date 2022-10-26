/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:21:03 by abaur             #+#    #+#             */
/*   Updated: 2022/10/26 18:50:38 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "truth_table.hpp"
#include "../logutil/logutil.hpp"
#include "../polishtree/PolishTree.hpp"

#include <iostream>
#include <cstdlib>

extern int	main(int argc, char** argv){
	for (int i=1; i<argc; i++) {
		IPolishItem* tree;
		std::string remainder;

		std::cout << argv[i] << std::endl;
		try {
			BuildTree(argv[i], tree, remainder);
			if (remainder.length())
				ft::clog << ft::log::warning << "Expression has trailing characters" << std::endl;
			std::cerr << tree->Draw();
			print_truth_table(argv[i]);
			std::cout << std::endl;
		}
		catch(const std::exception& e) {
			std::cout << LOG_YELLOW << e.what() << LOG_CLEAR"\n" << std::endl;
		}
	}
}
