/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PolishLookup.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 17:40:04 by abaur             #+#    #+#             */
/*   Updated: 2022/11/14 17:08:32 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLISHLOOKUP_HPP
#define POLISHLOOKUP_HPP

#include <string>
#include <iostream>

typedef std::basic_string<int>	JumpString;
struct	PolishLookup;

std::ostream&	operator<<(std::ostream&, JumpString);

/**
 * @param inExpr	The expression that will be referenced to by the lookup.
 * @param outTable	The jump table that will be referenced to by the lookup.
 */
PolishLookup	CreateLookup(const std::string& inExpr, JumpString& outTable);

struct PolishLookup
{
public:
	const char*	_head;
	const int*	_jump;

	PolishLookup(void);
	PolishLookup(const char* _head, const int* _jump);
	PolishLookup(const std::string& expr, const JumpString& jumpTable);
	PolishLookup(const PolishLookup&);
	~PolishLookup();


	/**************************************************************************/
	/* ## Accessors and properties                                            */
	/**************************************************************************/

	/**
	 * @param outLen	Outputs the number of elements in outStr and outTable.
	 * @param outStr	Output points to the first character of the sub-expression's string.
	 * @param ouTable	Output points to the first element of the sub-expression's jump table.
	 */
	void	GetMemory(int& outLen, const char*& outStr, const int*& outTable) const;

	/**
	 * @return	If this expression starts with a binary node, the index of its 
	 * second operand. 0 otherwise.
	 */
	int	Left() const;
	/**
	 * @return	If this expression starts with a node, the index of its first 
	 * operand. 0 otherwise.
	 */
	int	Right() const;
	/**
	 * The index of the leftmost item of this expresssion.
	 */
	int	Tail() const;


	/**************************************************************************/
	/* ## Operators                                                           */
	/**************************************************************************/

	PolishLookup&	operator=(const PolishLookup&);

	PolishLookup&	operator+=(int);
	PolishLookup	operator+(int) const;
	PolishLookup&	operator-=(int);
	PolishLookup	operator-(int) const;

	PolishLookup	operator++(int);
	PolishLookup&	operator++();
	PolishLookup	operator--(int);
	PolishLookup&	operator--();
};

#endif
