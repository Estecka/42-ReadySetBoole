/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_set.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:08:52 by abaur             #+#    #+#             */
/*   Updated: 2022/11/18 18:22:40 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_set.hpp"
#include "bitset.hpp"

#include "../polishtree/InvalidExprException.hpp"

#include <set>
#include <string>

static bitset	eval_set(const bitset varmap[26], const char* limit, const char* head, const char*& outEnd){
	if (head < limit)
		throw InvalidExprException("Expression is incomplete");

	outEnd = head - 1;
	if ('A' <= *head && *head <= 'Z')
		return varmap[(*head) - 'A'];
	else if (*head == '!')
		return ~eval_set(varmap, limit, outEnd, outEnd);

	bitset l, r;
	r = eval_set(varmap, limit, outEnd, outEnd);
	l = eval_set(varmap, limit, outEnd, outEnd);
	switch (*head)
	{
		default:	throw InvalidExprException("Expression contains invalid characters");
		case '&':	return l & r;
		case '|':	return l | r;
		case '^':	return l ^ r;
		case '=':	return l % r;
		case '>':	return l <= r;
	}
}

std::vector<int>	eval_set(const std::string& expr, const std::vector<std::vector<int>>& sets){
	std::set<int>	universe;

	for (size_t x=0; x<sets.size();    x++)
	for (size_t y=0; y<sets[x].size(); y++)
		universe.insert(sets[x][y]);

	bitset	empty = ~set_to_bit(universe, universe);
	bitset	varmap[26] = { empty };
	for (size_t i=0; i<sets.size() && i<26; i++)
		varmap[i] = vec_to_bit(universe, sets[i]);

	const char* outEnd;
	const char* c_str = expr.c_str();
	return bit_to_vec(universe, eval_set(varmap, c_str, c_str+expr.length()-1, outEnd));
}
