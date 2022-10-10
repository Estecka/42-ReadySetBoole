/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PolishBool.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:28:53 by abaur             #+#    #+#             */
/*   Updated: 2022/09/30 17:42:37 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PolishBool.hpp"

PolishBool::PolishBool(bool value) 
: _value(value)
{}

PolishBool::~PolishBool()
{}

bool	PolishBool::Evaluate(){
	return this->_value;
}

std::string	PolishBool::Draw(std::string){
	return _value ? "1\n" : "0\n";
}
