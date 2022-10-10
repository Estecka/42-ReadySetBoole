/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PolishVar.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:37:39 by abaur             #+#    #+#             */
/*   Updated: 2022/10/10 16:01:18 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLISHVAR_HPP
#define POLISHVAR_HPP

#include "IPolishItem.hpp"

class PolishVar : public IPolishItem
{
public:
	char	_name;

	PolishVar(char name);
	~PolishVar();

	bool	Evaluate(const varmap& = {});
	std::string	Draw(std::string = "");
};

#endif
