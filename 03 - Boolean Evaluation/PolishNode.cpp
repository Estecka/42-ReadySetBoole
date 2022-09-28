/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PolishNode.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:33:06 by abaur             #+#    #+#             */
/*   Updated: 2022/09/28 16:16:16 by abaur            ###   ########.fr       */
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

std::string	PolishNode::Draw(int level){
	std::string	graph;
	std::string	prefix;

	for (int i=0; i<level; i++)
		prefix += " │";

	graph += (_op=='|') ? ':' : _op;
	graph += + "┬";
	graph += _right ? _right->Draw(level+1) : "??\n";
	graph += prefix + " └";
	graph += _left  ? _left ->Draw(level+1) : "??\n";

	return graph;
}
