/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:19:56 by abaur             #+#    #+#             */
/*   Updated: 2022/09/28 15:16:48 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.hpp"


static void	BuildTree(const std::string& str, IPolishItem*& outTree, std::string& outRemainder);


static PolishNode*	BuildNode(char op, std::string& expr){
	PolishNode& node = *new PolishNode(op, NULL, NULL);

	BuildTree(expr, node._left, expr);
	BuildTree(expr, node._right, expr);

	return &node;
}

static void	BuildTree(const std::string& str, IPolishItem*& outTree, std::string& outRemainder){
	const std::string& expr = str;
	if (!expr.size())
		throw InvalidExprException("Expression has loose ends.");

	char c = expr.at(expr.size()-1);
	outRemainder = expr.substr(0, expr.size()-1);

	switch (c) {
		case '0':	outTree = new PolishBool(false);	break;
		case '1':	outTree = new PolishBool(true); 	break;
		default: 	outTree = BuildNode(c, outRemainder);	break;
	}
}

bool	eval_formula(const std::string& str) {
	IPolishItem*	tree;
	std::string 	remainder;

	BuildTree(str, tree, remainder);
	if (remainder.size())
		throw InvalidExprException("Expression has trailing characters");

	return tree->Evaluate();
}
