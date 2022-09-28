/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PolishBool.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:38:20 by abaur             #+#    #+#             */
/*   Updated: 2022/09/25 19:55:47 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLISH_BOOL
#define POLISH_BOOL

#include "IPolishItem.hpp"

class PolishBool : public IPolishItem
{
public:
	PolishBool(bool value);
	~PolishBool();

	bool	Evaluate();
	std::string	Draw(int level=0);

private:
	bool _value;
};

#endif
