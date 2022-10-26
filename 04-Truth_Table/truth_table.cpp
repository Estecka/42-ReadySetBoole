/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truth_table.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:19:56 by abaur             #+#    #+#             */
/*   Updated: 2022/10/26 18:40:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "truth_table.hpp"

#include "../03-Boolean_Evaluation/eval_formula.hpp"
#include <iostream>

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

static void	Row(short i, short varcount, const char* shiftmap, const std::string& expr){
	bool varmap[26] = { 0 }; // Translates variable name into its value;

	for (int j=0; j<varcount; j++){
		bool value = 1 & (i>>j);
		varmap[shiftmap[j] - 'A'] = value;
		std::cout << "| " << (int)value << " ";
	}
	std::cout << "| " << eval_formula(expr, varmap) << " |" << std::endl;
}

void	print_truth_table(const std::string& expr) {
	short	varcount = 0 ;
	char	shiftmap[26] = { 0 }; // Translates variable column index into its name.


	Header(expr, varcount, shiftmap);

	for (int i=0; i<varcount; i++)
		std::cout << "|---";
	std::cout << "|---|" << std::endl;

	for (int i=0; i<(1<<varcount); i++)
		Row(i, varcount, shiftmap, expr);
}
