/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   negation_normal_form.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:19:56 by abaur             #+#    #+#             */
/*   Updated: 2022/10/15 18:04:34 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "negation_normal_form.hpp"

#include "../polishtree/InvalidExprException.hpp"

/**
 * @param neg	Whether the expression should be parsed as such, or negated as a whole.
 * @param head	The position from which parsing should start. The string is 
 * 	parsed in reverse order.
 * @param limit	The first character of the string.
 * @param outEnd	Outputs the character following the parsed expression.
 */
static std::string	negational_normal_form(bool neg, const char* limit, const char* head, const char*& outEnd){
	if (head < limit)
		throw InvalidExprException("Expression is incomplete");
	while (*head == '!'){
		neg = !neg;
		head--;
		if (head < limit)
			throw InvalidExprException("Expression is incomplete");
	}


	if (('A' <= *head && *head <= 'Z')
	||  (*head == '0' || *head == '1')){
		outEnd = head-1;
		return *head + std::string(neg?"!":"");
	}
	else {
		bool negA, negB;
		char op;
		switch (*head){
			default:	throw InvalidExprException("Expression contains unsupported symbols");
			case '|':	negA=neg,   negB=neg,   op=(neg?'&':*head); break;
			case '&':	negA=neg,   negB=neg,   op=(neg?'|':*head); break;
			case '^':	negA=false, negB=false, op=(neg?'=':*head); break;
			case '=':	negA=false, negB=false, op=(neg?'^':*head); break;
			case '>':	negA=false, negB=neg,   op=(neg?'=':*head); break;
		}
		std::string B = negational_normal_form(negB, limit, head-1, outEnd);
		std::string A = negational_normal_form(negA, limit, outEnd, outEnd);
		return A + B + op;
	}
}

std::string	negational_normal_form(const std::string& expr){
	const char* limit = expr.c_str();
	const char* head  = limit + expr.length()-1;
	const char* outEnd;

	return negational_normal_form(false, limit, head, outEnd);
}
