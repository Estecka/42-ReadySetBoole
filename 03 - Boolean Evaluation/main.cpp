/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:21:03 by abaur             #+#    #+#             */
/*   Updated: 2022/09/28 16:19:10 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./eval_expr.hpp"
#include "../logutil/logutil.hpp"

#include <iostream>
#include <cstdlib>

extern int	main(int argc, char** argv){
	for (int i=1; i<argc; i++) {
		std::cout << argv[i] << std::endl;
		try {
			bool r = eval_formula(argv[i]);
			std::cout << "= " << (r?"true":"false") << '\n' << std::endl;
		}
		catch(const std::exception& e) {
			std::cout << LOG_YELLOW << e.what() << LOG_CLEAR"\n" << std::endl;
		}
	}
}
