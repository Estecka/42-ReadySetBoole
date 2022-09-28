/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IPolishItem.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:23:18 by abaur             #+#    #+#             */
/*   Updated: 2022/09/28 15:39:17 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IPOLISH_ITEM
#define IPOLISH_ITEM

#include <iostream>

class IPolishItem
{
public:
	virtual ~IPolishItem(){};

	/**
	 * Collapse the item into a single boolean value.
	 * @throw InvalidTreeException	The tree  is incomplete  or contains unknown
	 * 	variables.
	 */
	virtual bool	Evaluate() = 0;
	/**
	 * Draw a visual representation of the Item.
	 * 
	 * If multiline, each line will be padded according to `level`.
	 * The first line however, will never be padded, so that it can be easily
	 * appended to an existing tree.
	 */
	virtual std::string	Draw(int level = 0) = 0;
};

#endif
