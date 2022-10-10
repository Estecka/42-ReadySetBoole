/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:19:56 by abaur             #+#    #+#             */
/*   Updated: 2022/10/10 15:04:54 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "eval_expr.hpp"

#include "../polishtree/PolishTree.hpp"

bool	eval_formula(const std::string& str) {
	IPolishItem*	tree;
	std::string 	remainder;

	BuildTree(str, tree, remainder);
	if (remainder.size())
		throw InvalidExprException("Expression has trailing characters");
	std::cerr << tree->Draw();

	return tree->Evaluate();
}
