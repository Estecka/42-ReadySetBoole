/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PolishNode.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:33:06 by abaur             #+#    #+#             */
/*   Updated: 2022/10/10 16:01:18 by abaur            ###   ########.fr       */
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

bool	PolishNode::Evaluate(const varmap& values){
	if (!this->_left || !this->_right)
		throw InvalidTreeException("A node has missing components");
	bool l = this->_left ->Evaluate(values);
	bool r = this->_right->Evaluate(values);

	switch (this->_op)
	{
		default:	throw InvalidTreeException("Unsuported operator");
		case '&':	return l & r;
		case '|':	return l | r;
		case '^':	return l ^ r;
		case '=':	return l == r;
		case '>':	return l <= r;
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
