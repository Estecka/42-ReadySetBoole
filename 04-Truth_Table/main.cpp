/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:21:03 by abaur             #+#    #+#             */
/*   Updated: 2022/10/29 19:41:53 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "truth_table.hpp"
#include "../logutil/logutil.hpp"
#include "../polishtree/PolishTree.hpp"

#include <iostream>
#include <cstdlib>
#include <cstring>

static void	List(int argc, const char*const* argv){
	for (int i=0; i<argc; i++) {
		IPolishItem* tree = NULL;
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
		if (tree) delete tree;
	}
}


static void	Compare(const char* base, int argc, const char*const* argv){
	IPolishItem* tree;
	std::string remainder;
	std::cout << base << std::endl;

	BuildTree(base, tree, remainder);
	if (remainder.length())
		ft::clog << ft::log::warning << "Base expression has trailing characters" << std::endl;
	std::cout << tree->Draw();
	delete tree;

	for (int i=0; i<argc; i++) {
		std::cout << LOG_BOLD_CYAN "\n" << argv[i] << LOG_CLEAR << std::endl;

		tree = NULL;
		BuildTree(argv[i], tree, remainder);
		if (remainder.length())
			ft::clog << ft::log::warning << "Expression has trailing characters" << std::endl;
		std::cerr << LOG_CYAN << tree->Draw() << LOG_CLEAR;

		compare_truth_tables(base, argv[i], remainder);
		std::cout << remainder;
		delete tree;
	}
}

extern int	main(int argc, char** argv){
	if (argc < 2 || !std::strcmp(argv[1], "--compare")){
		if (argc < 4){
			std::cerr << "Not enough arguments" << std::endl;
			exit(EXIT_FAILURE);
		}
		else
			Compare(argv[2], argc-3, argv+3);
	}
	else
		List(argc-1, argv+1);
}
