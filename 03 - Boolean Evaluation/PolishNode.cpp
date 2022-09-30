/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PolishNode.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:33:06 by abaur             #+#    #+#             */
/*   Updated: 2022/09/30 17:42:48 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InvalidTreeException.hpp"
#include "PolishNode.hpp"

PolishNode::PolishNode(char op, IPolishItem* left, IPolishItem* right) :
_op(op),
_left(left),
_right(right)
{}

PolishNode::~PolishNode(){
	if (this->_left)
		delete this->_left;
	if (this->_right)
		delete this->_right;
}

bool	PolishNode::Evaluate(){
	if (!this->_left || !this->_right)
		throw InvalidTreeException("A node has missing components");
	bool l = this->_left ->Evaluate();
	bool r = this->_right->Evaluate();

	switch (this->_op)
	{
		default:	throw InvalidTreeException("Unsuported operator");
		case '&':	return l & r;
		case '|':	return l | r;
		case '^':	return l ^ r;
	}
}

std::string	PolishNode::Draw(std::string prefix){
	std::string	graph;

	graph += (_op=='|') ? ':' : _op;
	graph += + "┬";
	graph += _right ? _right->Draw(prefix + " │") : "??\n";
	graph += prefix + " └";
	graph += _left  ? _left ->Draw(prefix + "  ") : "??\n";

	return graph;
}
