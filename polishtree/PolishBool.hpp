/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PolishBool.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:38:20 by abaur             #+#    #+#             */
/*   Updated: 2022/10/10 16:01:18 by abaur            ###   ########.fr       */
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

	bool	Evaluate(const varmap& = {});
	std::string	Draw(std::string = "");

private:
	bool _value;
};

#endif
