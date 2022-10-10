/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PolishNot.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:07:38 by abaur             #+#    #+#             */
/*   Updated: 2022/10/07 18:17:47 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLISH_NOT
#define POLISH_NOT

#include "IPolishItem.hpp"

class PolishNot : public IPolishItem
{
public:
	IPolishItem*	_child;

	PolishNot(IPolishItem*	child);
	~PolishNot();

	bool	Evaluate();
	std::string	Draw(std::string = "");
};



#endif
