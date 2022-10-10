/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truth_table.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:19:56 by abaur             #+#    #+#             */
/*   Updated: 2022/10/10 15:52:09 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "truth_table.hpp"

#include "../polishtree/PolishTree.hpp"

void	print_truth_table(const std::string& str) {
	IPolishItem*	tree;
	std::string 	remainder;

	BuildTree(str, tree, remainder);
	if (remainder.size())
		throw InvalidExprException("Expression has trailing characters");
	std::cerr << tree->Draw() << std::endl;
}
