/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SAT.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:19:56 by abaur             #+#    #+#             */
/*   Updated: 2022/11/17 15:06:57 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SAT.hpp"

#include "../03-Boolean_Evaluation/eval_formula.hpp"
#include "../logutil/logcolors.hpp"

/**
 * @param outVarcount	Outputs the number of different variable names in this 
 * 	expression
 * @param outShiftmap	Outputs  a  shiftmap,  which  can  be  used  to  compute
 * 	a different varmap from each row index in this table.
 */
static void	Header(const std::string& expr, short& outVarcount, char outShiftmap[26]){
	bool	exists[26] = { false };

	for (const char* str=expr.c_str(); *str; str++)
	if ('A' <= *str && *str <= 'Z' && !exists[*str - 'A']){
		exists[*str - 'A'] = true;
		outShiftmap[outVarcount] = *str;
		outVarcount++;
	}
}

/**
 * @param outVarmap	outputs a varmap, which converts a variable's name into its
 * 	value for this row.
 */
static void	Row(short i, short varcount, const char* shiftmap, bool (&outVarmap)[26]){
	for (int j=0; j<varcount; j++){
		bool value = 1 & (i>>j);
		outVarmap[shiftmap[j] - 'A'] = value;
	}
}

extern bool	sat(const std::string& expr) {
	short	varcount = 0 ;
	char	shiftmap[26] = { 0 }; // Translates variable column index into its name.
	bool	varmap[26] = { 0 };


	Header(expr, varcount, shiftmap);

	for (int i=0; i<(1<<varcount); i++){
		Row(i, varcount, shiftmap, varmap);
		if (eval_formula(expr, varmap))
			return true;
	}
	return false;
}
