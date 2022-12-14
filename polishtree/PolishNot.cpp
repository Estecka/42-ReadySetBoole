/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PolishNot.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:10:54 by abaur             #+#    #+#             */
/*   Updated: 2022/10/10 16:01:18 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InvalidTreeException.hpp"
#include "PolishNot.hpp"

PolishNot::PolishNot(IPolishItem* child)
:_child(child)
{}

PolishNot::~PolishNot(){
	if (this->_child)
		delete this->_child;
}

bool PolishNot::Evaluate(const varmap& values){
	if (!this->_child)
		throw InvalidTreeException("A node has missing components");
	return !_child->Evaluate(values);
}
std::string	PolishNot::Draw(std::string prefix){

	return "!" + (_child ? _child->Draw(prefix+" ") : "??\n");
}
