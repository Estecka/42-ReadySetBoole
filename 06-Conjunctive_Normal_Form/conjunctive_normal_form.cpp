/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conjunctive_normal_form.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:39:34 by abaur             #+#    #+#             */
/*   Updated: 2022/11/14 18:27:51 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conjunctive_normal_form.hpp"

#include "../05-Negation_Normal_Form/negation_normal_form.hpp"
#include "../polishlookup/PolishLookup.hpp"

#include <vector>

struct pExpr {
	std::string	str;
	JumpString	jmp;
};


/**
 * Clones the expression without modifying it.
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
 * Returns a new binary node with updated childs.
 */
static pExpr	Update(const PolishLookup& node, const pExpr& left, const pExpr& right){
	return (pExpr){
		left.str + right.str + *node._head,
		left.jmp + right.jmp + -(int)(right.jmp.length() + 1),
	};
}


/**
 * Turns AB&C& into CAB&&
 */
static pExpr	SwapBinary(const pExpr& left, const pExpr& right){
	return (pExpr){
		right.str + left.str + '&',
		right.jmp + left.jmp + -(int)(left.jmp.length()+1)
	};
}

/**
 * Turns AB&CD&& into ABCD&&&
 * Also aplicable for any amount of successive & in any child.
 */
static pExpr	MergeAnds(const PolishLookup& node, const pExpr& _left, const PolishLookup& left, const pExpr& _right){
	pExpr	_lOperands;
	pExpr	_lOperators;
	size_t opCount = 0;

	while (left._head[-opCount] == '&')
		opCount++;

	opCount = _left.str.length() - opCount;
	_lOperands.str = _left.str.substr(0, opCount);
	_lOperands.jmp = _left.jmp.substr(0, opCount);
	_lOperators.str = _left.str.substr(opCount);
	_lOperators.jmp = _left.jmp.substr(opCount);

	for (size_t i=0; i<_lOperators.jmp.length(); i++)
		_lOperators.jmp[i] += *node._jump;

	return (pExpr){
		_lOperands.str + _right.str + *node._head + _lOperators.str,
		_lOperands.jmp + _right.jmp + *node._jump + _lOperators.jmp,
	};
}

static inline void	FindItems(PolishLookup i, std::vector<pExpr>& outp){
	while (true)
	if (*i._head=='&'){
		outp.push_back(Noop(i + i.Left()));
		i += i.Right();
	}
	else {
		outp.push_back(Noop(i));
		return;
	}
}
/**
 * Turns AB&C| into AC|BC|&
 * Also applicable for any amount of successive & in any child.
 */
static pExpr	MergeOrs(const PolishLookup& left, const PolishLookup& right){
	std::vector<pExpr> lItems, rItems;
	FindItems(left,  lItems);
	FindItems(right, rItems);

	pExpr result;
	for (size_t l=0; l<lItems.size(); l++)
	for (size_t r=0; r<rItems.size(); r++){
		if (l || r) {
			result.str += '&';
			result.jmp += -(int)result.str.length();
		}
		result.str = lItems[l].str + rItems[r].str + '|'                              + result.str;
		result.jmp = lItems[l].jmp + rItems[r].jmp + -(int)(rItems[r].jmp.length()+1) + result.jmp;
	}
	return result;
}


static pExpr	conjunctive_normal_form(const PolishLookup& node){
	if (!node.Left() || !node.Right())
		return Noop(node);

	pExpr _left  = conjunctive_normal_form(node + node.Left());
	pExpr _right = conjunctive_normal_form(node + node.Right());
	PolishLookup left (_left .str, _left .jmp);
	PolishLookup right(_right.str, _right.jmp);

	if (*left._head != '&' && *right._head != '&')
		return Update(node, _left, _right);

	if (*node._head == '&') {
		if (*right._head != '&')
			return SwapBinary(_left, _right);
		else if (*left._head != '&')
			return Update(node, _left, _right);
		else
			return MergeAnds(node, _left, left, _right);
	}
	else
		return MergeOrs(left, right);


}

extern std::string	conjunctive_normal_form(const std::string& expr){
	std::string nnf;
	JumpString	jumpTable;
	PolishLookup lookup;

	nnf = negational_normal_form(expr);
	lookup = CreateLookup(nnf, jumpTable);

	return conjunctive_normal_form(lookup).str;
}
