/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IPolishItem.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:23:18 by abaur             #+#    #+#             */
/*   Updated: 2022/10/11 16:46:19 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IPOLISH_ITEM
#define IPOLISH_ITEM

#include <iostream>
#include <map>

class IPolishItem
{
public:
	typedef bool	varmap[26];

	virtual ~IPolishItem(){};

	/**
	 * Collapse the item into a single boolean value.
	 * @param values	The value to be associated with each variable names.
	 * @throw InvalidTreeException	The tree is incomplete or contains undefined
	 * 	variables.
	 */
	virtual bool	Evaluate(const varmap& values = {}) = 0;
	/**
	 * Draw a visual representation of the Item.
	 * 
	 * If multiline, each line will be prefixed with the provided value.
	 * The first line however, will never be padded, so that it can be easily
	 * appended to an existing tree.
	 */
	virtual std::string	Draw(std::string prefix = "") = 0;
};

#endif
