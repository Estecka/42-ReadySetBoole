/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:21:03 by abaur             #+#    #+#             */
/*   Updated: 2022/11/17 15:50:46 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SAT.hpp"
#include "../04-Truth_Table/truth_table.hpp"
#include "../logutil/logutil.hpp"
#include "../polishtree/PolishTree.hpp"

#include <iostream>
#include <stdnoreturn.h>
#include <cstdlib>
#include <cstring>

extern int	main(int argc, char** argv){
	for (int i=1; i<argc; i++){
		try {
			std::string table = get_truth_table(argv[i]);
			bool isSat = sat(argv[i]);
			bool expected = std::strstr(table.c_str(), "| 1 |\n");

			std::cout << LOG_BOLD_CLEAR << argv[i] << LOG_CLEAR << std::endl;
			std::cout << (isSat?"true":"false") << std::endl;
			if (isSat == expected)
				std::cout << LOG_GREEN "OK" LOG_CLEAR << std::endl;
			else 
				std::cout << LOG_BOLD_RED "KO:\n" LOG_CLEAR << table << std::endl;
			std::cout << std::endl;
		}
		catch(const std::exception& e){
			ft::clog << ft::log::error << e.what() << std::endl;
		}
	}
}
