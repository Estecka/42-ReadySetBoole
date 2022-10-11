/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PolishVar.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:45:17 by abaur             #+#    #+#             */
/*   Updated: 2022/10/11 17:41:39 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PolishVar.hpp"

PolishVar::PolishVar(char name)
: _name(name)
{}

PolishVar::~PolishVar()
{}

bool PolishVar::Evaluate(const varmap& values){
	return values[_name - 'A'];
}

std::string	 PolishVar::Draw(std::string){
	return _name + std::string("\n");
}
