/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprgen.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:58:56 by abaur             #+#    #+#             */
/*   Updated: 2022/11/13 14:57:55 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exprgen.hpp"

#include <cstdlib>

static inline char	vargen(){
	if (rand() % 5)
		return 'A' + (rand() % ('Z'-'A'+1)) ;
	else
		return '0' + (rand() & 1);
}

static inline std::string	gategen(size_t complexity){
	char op = "!|&^=>"[rand() % 6];
	complexity--;

	if (op == '!')
		return exprgen(complexity) + std::string("!");
	else {
		size_t leftCpx  = rand() % (complexity+1);
		size_t rightCpx = complexity - leftCpx;

		return exprgen(leftCpx) + exprgen(rightCpx) + op;
	}
}

extern std::string	exprgen(size_t complexity){
	if (!complexity)
		return std::string() +vargen();
	else
		return gategen(complexity);
}
