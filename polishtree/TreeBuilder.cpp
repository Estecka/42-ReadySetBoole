/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeBuilder.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:03:31 by abaur             #+#    #+#             */
/*   Updated: 2022/10/10 15:35:26 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PolishTree.hpp"

#include <cstring>

static PolishNode*	BuildNode(char op, std::string& expr){
	PolishNode& node = *new PolishNode(op, NULL, NULL);

	BuildTree(expr, node._right, expr);
	BuildTree(expr, node._left,  expr);

	return &node;
}
static PolishNot*	BuildNot(std::string& expr){
	PolishNot& node = *new PolishNot(NULL);

	BuildTree(expr, node._child, expr);

	return &node;
}

extern void	BuildTree(const std::string& str, IPolishItem*& outTree, std::string& outRemainder){
	const std::string& expr = str;
	if (!expr.size())
		throw InvalidExprException("Expression has loose ends");

	char c = expr.at(expr.size()-1);
	outRemainder = expr.substr(0, expr.size()-1);

	if ('A' <= c && c <= 'Z')
		outTree = new PolishVar(c);
	else if (std::strchr("&|^>=", c))
		outTree = BuildNode(c,  outRemainder);
	else switch (c) {
		case '0':	outTree = new PolishBool(false);	break;
		case '1':	outTree = new PolishBool(true); 	break;
		case '!':	outTree = BuildNot (outRemainder);    	break;
		default:	throw new InvalidExprException("Unsupported symbol");
	}
}
