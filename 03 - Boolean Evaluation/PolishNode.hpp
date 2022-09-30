/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PolishNode.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:17:18 by abaur             #+#    #+#             */
/*   Updated: 2022/09/30 17:43:10 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLISH_NODE_HPP
#define POLISH_NODE_HPP

#include "IPolishItem.hpp"

class PolishNode : public IPolishItem
{
	public:
		char _op;
		IPolishItem	*_left, *_right;

		PolishNode(char op, IPolishItem* left, IPolishItem* right);
		~PolishNode();

		bool	Evaluate();
		std::string	Draw(std::string = "");
};

#endif
