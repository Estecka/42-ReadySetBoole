/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:21:03 by abaur             #+#    #+#             */
/*   Updated: 2022/10/22 19:54:28 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./eval_expr.hpp"
#include "../logutil/logutil.hpp"
#include "../polishtree/PolishTree.hpp"

#include <iostream>
#include <cstdlib>
#include <cstring>

extern int	main(int argc, char** argv){
	for (int i=1; i<argc; i++) {
		std::cout << argv[i] << std::endl;
		try {
			size_t	size;
			size_t	len = strlen(argv[i]);
			bool r = eval_formula(argv[i], size);
			if (size != len)
				std::cout << LOG_YELLOW << "Expression has trailing characters." << LOG_CLEAR << std::endl;

			IPolishItem*	tree;
			std::string	remainder;
			BuildTree(argv[i], tree, remainder);
			std::cout << tree->Draw();

			std::cout << "= " << (r?"true":"false") << '\n' << std::endl;
			if (r != tree->Evaluate())
				std::cout << LOG_BOLD_RED << "Tree evaluation differs" << LOG_CLEAR << std::endl;
		}
		catch(const std::exception& e) {
			std::cout << LOG_YELLOW << e.what() << LOG_CLEAR"\n" << std::endl;
		}
	}
}
