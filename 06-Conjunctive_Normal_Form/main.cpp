/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:19:27 by abaur             #+#    #+#             */
/*   Updated: 2022/10/30 18:30:13 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conjunctive_normal_form.hpp"

#include "../logutil/logutil.hpp"
#include "../polishtree/PolishTree.hpp"
#include "../04-Truth_Table/truth_table.hpp"

#include <iostream>
#include <exception>

extern int	main(int argc, char** argv){
	IPolishItem	*src=NULL, *dst=NULL;
	std::string	remainder, nnf;

	for (int i=1; i<argc; i++) 
	try {
		std::cout << LOG_BOLD_CLEAR"\n" << argv[i] << std::endl;
		BuildTree(argv[i], src, remainder);
		std::cout << LOG_CLEAR << src->Draw();
		if (remainder.length())
			ft::clog << ft::log::warning << "Input expression has trailing characters" << std::endl;

		nnf = conjunctive_normal_form(argv[i]);
		std::cout << LOG_BOLD_CYAN << nnf << std::endl;
		BuildTree(nnf, dst, remainder);
		std::cout << LOG_CYAN << dst->Draw();
		if (remainder.length())
			std::cout << LOG_BOLD_RED << "KO: Output expression has trailing characters" << std::endl;

		std::string	truth_table;
		if (compare_truth_tables(argv[i], nnf, truth_table)){
			std::cout << LOG_BOLD_RED "KO: Truth tables differ:\n" LOG_CLEAR << std::endl;
			std::cout << truth_table << std::endl;
		}
		else
			std::cout << LOG_BOLD_GREEN "Truth tables OK" LOG_CLEAR << std::endl;

		std::cout << LOG_CLEAR << std::endl;
		delete src, src=NULL;
		delete dst, src=NULL;
	}
	catch(std::exception& e)
	{
		ft::clog << ft::log::error << e.what() << std::endl;
		if (src) delete src, src=NULL;
		if (dst) delete dst, dst=NULL;
	}
}
