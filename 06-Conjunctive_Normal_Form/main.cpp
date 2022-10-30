/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:19:27 by abaur             #+#    #+#             */
/*   Updated: 2022/10/30 19:25:33 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conjunctive_normal_form.hpp"

#include "../logutil/logutil.hpp"
#include "../polishtree/PolishTree.hpp"
#include "../04-Truth_Table/truth_table.hpp"

#include <iostream>
#include <exception>
#include <cstring>

static bool CheckNormalForm(const std::string& expr){
	const char*const first = expr.c_str();
	const char*const last  = first + expr.length() - 1;

	for (const char* i=last; i>=first; i--){
		if (('A' <= *i && *i <= 'Z')
		||  ('0' == *i || *i == '1')){
			continue;
		}
		else if (!std::strchr("!&|", *i)) {
			std::cout << LOG_BOLD_RED "KO: Invalid character: " << *i << LOG_CLEAR << std::endl;
			return false;
		}
		else if (i[1] == '!') {
			std::cout << LOG_BOLD_RED "KO: Forbidden negation: " << *i << "!" LOG_CLEAR << std::endl;
			return false;
		}
		else if (i[1] && i[1]!='&' && *i=='&') {
			std::cout << LOG_BOLD_RED "KO: Forbidden conjunction: &" << i[1] << LOG_CLEAR << std::endl;
			return false;
		}
	}

	std::cout << LOG_BOLD_GREEN "Normal form OK" LOG_CLEAR << std::endl;
	return true;
}


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

		CheckNormalForm(nnf);

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
