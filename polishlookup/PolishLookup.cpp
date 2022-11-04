/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PolishLookup.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 18:16:32 by abaur             #+#    #+#             */
/*   Updated: 2022/11/04 19:09:38 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PolishLookup.hpp"

#include <cstring>

PolishLookup::PolishLookup(void):
_head(NULL),
_jump(NULL)
{}

PolishLookup::PolishLookup(const char* head, const int* jump):
_head(head),
_jump(jump)
{}

PolishLookup::PolishLookup(const PolishLookup& other):
_head(other._head),
_jump(other._jump)
{}
PolishLookup::~PolishLookup()
{}


void	PolishLookup::GetMemory(int& outLen, const char*& outStr, const int*& outJmp){
	outLen = this->Tail();
	outStr = this->_head + outLen;
	outJmp = this->_jump + outLen;
	outLen = 1-outLen;
}

int	PolishLookup::Left(){
	return *_jump;
}
int	PolishLookup::Right(){
	if (*_jump || *_head == '!' )
		return -1;
	else
		return 0;
}

int	PolishLookup::Tail() {
	int i = 0;

	while (true) 
	{
		if (_jump[i])
			i += _jump[i];
		else if (_head[i] == '!')
			i += -1;
		else
			return i;
	}
}


PolishLookup&	PolishLookup::operator=(const PolishLookup& other){
	new(this) PolishLookup(other);
	return *this;
}
PolishLookup&	PolishLookup::operator+=(int i) { _jump+=i; _head+=i; return *this; }
PolishLookup&	PolishLookup::operator-=(int i) { _jump-=i; _head-=i; return *this; }
PolishLookup&	PolishLookup::operator++() { _jump++; _head++; return *this; };
PolishLookup&	PolishLookup::operator--() { _jump--; _head--; return *this; };

PolishLookup	PolishLookup::operator+(int i) { return PolishLookup(_head+i, _jump+i); };
PolishLookup	PolishLookup::operator-(int i) { return PolishLookup(_head+i, _jump+i); };

PolishLookup	PolishLookup::operator++(int) { PolishLookup r = *this; ++(*this); return r; };
PolishLookup	PolishLookup::operator--(int) { PolishLookup r = *this; --(*this); return r; };

