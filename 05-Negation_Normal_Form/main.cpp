/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 14:19:27 by abaur             #+#    #+#             */
/*   Updated: 2022/10/15 14:55:18 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "negation_normal_form.hpp"
#include "../logutil/logutil.hpp"

#include "../polishtree/PolishTree.hpp"

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

		nnf = negational_normal_form(argv[i]);
		std::cout << LOG_BOLD_CYAN << nnf << std::endl;
		BuildTree(nnf, dst, remainder);
		std::cout << LOG_CYAN << dst->Draw();
		if (remainder.length())
			std::cout << LOG_BOLD_RED << "KO: Output expression has trailing characters" << std::endl;
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
