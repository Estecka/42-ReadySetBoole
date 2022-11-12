/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conjunctive_normal_form.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:39:34 by abaur             #+#    #+#             */
/*   Updated: 2022/11/12 17:13:55 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conjunctive_normal_form.hpp"

#include "../05-Negation_Normal_Form/negation_normal_form.hpp"
#include "../polishlookup/PolishLookup.hpp"

struct pExpr {
	std::string	str;
	JumpString	jmp;
};


/**
 * Clones the expression withour modifying it
 */
static pExpr	Noop(const PolishLookup& node){
	const char*	str;
	const int* 	table;
	int	len;
	node.GetMemory(len, str, table);

	return (pExpr){
		std::string(str, len),
		JumpString(table, len)
	};
}

/**
 * Turns AB&C& into CAB&&
 */
static pExpr	SwapBinary(const pExpr& left, const pExpr& right){
	return (pExpr){
		right.str + left.str + '&',
		right.jmp + left.jmp + (int)(left.jmp.length()+1)
	};
}

/**
 * Turns AB&CD&& into ABCD&&&
 */
static pExpr	MergeAnds(const PolishLookup& node){
	//placeholder
	return Noop(node);
}


static pExpr	conjunctive_normal_form(const PolishLookup& node){
	if (!node.Left() || !node.Right())
		return Noop(node);

	pExpr _left  = conjunctive_normal_form(node + node.Left());
	pExpr _right = conjunctive_normal_form(node + node.Right());
	PolishLookup left (_left .str, _left .jmp);
	PolishLookup right(_right.str, _right.jmp);

	if (*left._head != '&' && *right._head != '&')
		return Noop(node);

	if (*node._head == '&') {
		if (*right._head != '&')
			return SwapBinary(_left, _right);
		else if (*left._head != '&')
			return Noop(node);
		else
			return MergeAnds(node);
	}
	else
	{
		//placeholder
		return Noop(node);
	}


}

extern std::string	conjunctive_normal_form(const std::string& expr){
	std::string nnf;
	JumpString	jumpTable;
	PolishLookup lookup;

	nnf = negational_normal_form(expr);
	lookup = CreateLookup(nnf, jumpTable);

	return conjunctive_normal_form(lookup).str;
}
