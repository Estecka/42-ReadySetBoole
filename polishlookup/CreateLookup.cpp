/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CreateLookup.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:22:51 by abaur             #+#    #+#             */
/*   Updated: 2022/11/12 14:50:20 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PolishLookup.hpp"

#include <strings.h>
#include <cstring>
#include <exception>
#include <iostream>

/**
 * Populates a jump table for a given expression.
 * @param head	The root of the expression to parse
 * @param jump	The position of the root in the corresponding  jump table.
 * @return	The length of the parsed expression.
 */
static int	CreateLookup(const char* head, int* jump){
	if (('A' <= *head && *head <= 'Z')
	||  ('0' == *head || *head == '1')){
		*jump = 0;
		return 1;
	}
	else if (*head == '!'){
		*jump = 0;
		return 1 + CreateLookup(head-1, jump-1);
	}
	else if (std::strchr("&|^=>", *head)){
		*jump = -1 - CreateLookup(head-1, jump-1);
		return (-*jump) + CreateLookup(head+*jump, jump+*jump);
	} else {
		*jump = 0;
		return 0;
	}
}

extern PolishLookup	CreateLookup(const std::string& inExpr, JumpString& outTable){
	PolishLookup r;
	int	size = inExpr.length();
	int	table[size];

	bzero(table, sizeof(table));
	r._head = inExpr.c_str() + size - 1;
	CreateLookup(r._head, table + size - 1);


	outTable = JumpString(table, size);
	r._jump = outTable.c_str() + size - 1;
	return r;
}
