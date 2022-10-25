/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_formula.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:19:56 by abaur             #+#    #+#             */
/*   Updated: 2022/10/25 17:51:17 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_formula.hpp"

#include "../polishtree/InvalidExprException.hpp"

#include <cstring>

/**
 * @param head	The position from which parsing should start. The string is 
 * 	parsed in reverse order.
 * @param limit	The first character of the string.
 * @param outEnd	Outputs the character following the parsed expression.
 */
static bool	eval_formula(const bool varmap[26], const char* limit, const char* head, const char*& outEnd){
	if (head < limit)
		throw InvalidExprException("Expression is incomplete");

	outEnd = head - 1;
	if ('A' <= *head && *head <= 'Z')
		return varmap[(*head) - 'A'];
	else switch (*head)
	{
		case '0':	return false;
		case '1':	return true;
		case '!':	return !eval_formula(varmap, limit, outEnd, outEnd);
		default:	break;
	}

	bool l, r;
	r = eval_formula(varmap, limit, outEnd, outEnd);
	l = eval_formula(varmap, limit, outEnd, outEnd);
	switch (*head)
	{
		default:	throw InvalidExprException("Expression contains invalid characters");
		case '&':	return l & r;
		case '|':	return l | r;
		case '^':	return l ^ r;
		case '=':	return l == r;
		case '>':	return l <= r;
	}
}

bool	eval_formula(const std::string& str, const bool varmap[26], size_t& outSize) {
	const char*	outEnd;
	const char* c_str = str.c_str();

	bool r = eval_formula(varmap, c_str, c_str+str.length()-1, outEnd);

	outSize = str.length() - (outEnd - c_str) - 1;
	return r;
}

bool	eval_formula(const std::string& str, size_t& outSize) {
	return eval_formula(str, (bool[26]){}, outSize);
}
bool	eval_formula(const std::string& str, bool varmap[26]) {
	size_t	outSize;
	return eval_formula(str, varmap, outSize);
}
bool	eval_formula(const std::string& str) {
	return eval_formula(str, (bool[26]){});
}
