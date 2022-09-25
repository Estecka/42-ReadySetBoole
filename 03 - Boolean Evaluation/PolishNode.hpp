/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PolishNode.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:17:18 by abaur             #+#    #+#             */
/*   Updated: 2022/09/25 18:35:18 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLISH_NODE_HPP
#define POLISH_NODE_HPP

#include "IPolishItem.hpp"

class PolishNode : IPolishItem
{
	public:
		PolishNode(char op, IPolishItem* left, IPolishItem* right);
		~PolishNode();

		bool	Evaluate();
		std::string	Draw(int level=0);
		
	private:
		char _op;
		IPolishItem	*_left, *_right;
};

#endif
