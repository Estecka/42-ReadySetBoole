/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:21:03 by abaur             #+#    #+#             */
/*   Updated: 2022/11/05 17:21:04 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "truth_table.hpp"
#include "../logutil/logutil.hpp"
#include "../polishtree/PolishTree.hpp"

#include <iostream>
#include <stdnoreturn.h>
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


static void	Compare(const char* base, int argc, const char*const* argv, bool shorter){
	IPolishItem* tree;
	std::string remainder;
	std::cout << LOG_BOLD_CLEAR << base << LOG_CLEAR << std::endl;

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

		bool diff = compare_truth_tables(base, argv[i], remainder);
		if (!shorter)
			std::cout << remainder;
		else if (diff)
			std::cout << LOG_BOLD_RED "Diff" LOG_CLEAR << std::endl;
		else
			std::cout << LOG_BOLD_GREEN "OK" LOG_CLEAR << std::endl,
		delete tree;
	}
}

static noreturn void	ArgcErr(){
	std::cerr << "Not enough arguments" << std::endl;
	exit(EXIT_FAILURE);
}

extern int	main(int argc, char** argv){
	bool compare=false, shorter=false;

	argc--, argv++;
	if (argc < 1)
		ArgcErr();

	compare = !std::strcmp(argv[0], "--compare");
	if (compare){
		argc--, argv++;
		if (argc < 2)
			ArgcErr();
	}
	
	shorter = !std::strcmp(argv[0], "--short");
	if (shorter){
		if (argc < 3)
			ArgcErr();
		argc--, argv++;
	}

	if (compare)
		Compare(argv[0], argc-1, argv+1, shorter);
	else
		List(argc, argv);
}
