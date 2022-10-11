/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truth_table.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:19:56 by abaur             #+#    #+#             */
/*   Updated: 2022/10/11 17:43:59 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "truth_table.hpp"

#include "../polishtree/PolishTree.hpp"

static void	Header(const std::string& expr, short& varcount, char shiftmap[26]){
	bool	exists[26] = { false };

	for (const char* str=expr.c_str(); *str; str++)
	if ('A' <= *str && *str <= 'Z' && !exists[*str - 'A']){
		exists[*str - 'A'] = true;
		shiftmap[varcount] = *str;
		varcount++;
		std::cout << "| " << *str << " ";
	}

	std::cout << "| = |" << std::endl;
}

static void	Row(short i, short varcount, const char* shiftmap, IPolishItem& tree){
	bool varmap[26] = { 0 }; // Translates variable name into its value;

	for (int j=0; j<varcount; j++){
		bool value = 1 & (i>>j);
		varmap[shiftmap[j] - 'A'] = value;
		std::cout << "| " << (int)value << " ";
	}
	std::cout << "| " << tree.Evaluate(varmap) << " |" << std::endl;
}


static IPolishItem*	GetTree(const std::string& expr){
	IPolishItem*	tree;
	std::string 	remainder;

	BuildTree(expr, tree, remainder);
	if (remainder.size())
		delete tree, throw InvalidExprException("Expression has trailing characters");

	return tree;
}

void	print_truth_table(const std::string& str) {
	IPolishItem*	tree = GetTree(str);
	short	varcount = 0 ;
	char	shiftmap[26] = { 0 }; // Translates variable column index into its name.

	std::cerr << tree->Draw();

	Header(str, varcount, shiftmap);

	for (int i=0; i<varcount; i++)
		std::cout << "|---";
	std::cout << "|---|" << std::endl;

	for (int i=0; i<(1<<varcount); i++)
		Row(i, varcount, shiftmap, *tree);

	std::cerr << std::endl;
	delete tree;
}
