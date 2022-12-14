/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truth_table.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:19:56 by abaur             #+#    #+#             */
/*   Updated: 2022/11/17 15:48:26 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "truth_table.hpp"

#include "../03-Boolean_Evaluation/eval_formula.hpp"
#include "../logutil/logcolors.hpp"
#include <iostream>
#include <sstream>

/**
 * @param outVarcount	Outputs the number of different variable names in this 
 * 	expression
 * @param outShiftmap	Outputs  a  shiftmap,  which  can  be  used  to  compute
 * 	a different varmap from each row index in this table.
 */
static void	Header(std::ostream& cout, const std::string& expr, short& outVarcount, char outShiftmap[26]){
	bool	exists[26] = { false };

	for (const char* str=expr.c_str(); *str; str++)
	if ('A' <= *str && *str <= 'Z' && !exists[*str - 'A']){
		exists[*str - 'A'] = true;
		outShiftmap[outVarcount] = *str;
		outVarcount++;
		cout << "| " << *str << " ";
	}
}

/**
 * @param outVarmap	outputs a varmap, which converts a variable's name into its
 * 	value for this row.
 */
static void	Row(std::ostream& cout, short i, short varcount, const char* shiftmap, bool (&outVarmap)[26]){
	for (int j=0; j<varcount; j++){
		bool value = 1 & (i>>j);
		outVarmap[shiftmap[j] - 'A'] = value;
		cout << "| " << (int)value << " ";
	}
	cout << "|";
}

extern std::string	get_truth_table(const std::string& expr) {
	short	varcount = 0 ;
	char	shiftmap[26] = { 0 }; // Translates variable column index into its name.
	bool	varmap[26] = { 0 };
	std::stringstream cout;


	Header(cout, expr, varcount, shiftmap);
	cout << "| = |" << std::endl;

	for (int i=0; i<varcount; i++)
		cout << "|---";
	cout << "|---|" << std::endl;

	for (int i=0; i<(1<<varcount); i++){
		Row(cout, i, varcount, shiftmap, varmap);
		cout <<  " " << (int)eval_formula(expr, varmap) << " |" << std::endl;
	}
	return cout.str();
}

extern void	print_truth_table(const std::string& expr) {
	std::cout << get_truth_table(expr) << std::endl;
}

extern bool	compare_truth_tables(const std::string& a, const std::string& b, std::string& outTable){
	short	varcount = 0 ;
	char	shiftmap[26] = { 0 }; // Translates variable column index into its name.
	bool	varmap[26] = { 0 };
	bool	r = false;
	std::stringstream cout;


	Header(cout, a+b, varcount, shiftmap);
	cout << "| " LOG_BOLD_CLEAR "src" LOG_CLEAR " | " LOG_BOLD_CYAN "dst" LOG_CYAN " |" LOG_CLEAR << std::endl;

	for (int i=0; i<varcount; i++)
		cout << "|---";
	cout << "|-----|" LOG_CYAN "-----|" LOG_CLEAR << std::endl;

	for (int i=0; i<(1<<varcount); i++){
		Row(cout, i, varcount, shiftmap, varmap);
		bool ra = eval_formula(a, varmap);
		bool rb = eval_formula(b, varmap);
		bool diff = (ra != rb);
		r |= (ra != rb);
		cout << "  " << (int)ra << "  |" 
		          << (diff ? LOG_BOLD_RED : LOG_CYAN)
		          << "  " << (int)rb << LOG_CYAN "  |" << (diff?LOG_BOLD_RED"!":LOG_CYAN" ")
		          << LOG_CLEAR << std::endl;
	}

	outTable = cout.str();
	return r;
}
