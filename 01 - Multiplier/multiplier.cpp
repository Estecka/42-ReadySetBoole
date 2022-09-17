/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:07:02 by abaur             #+#    #+#             */
/*   Updated: 2022/09/17 17:57:49 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../00 - Adder/adder.hpp"

/**
 * Fills all bits with the value of the first bit.
 */
#define TRUTH(n)	( ((signed int)n << 31) >> 31 )

extern unsigned int	multiplier(unsigned int a, unsigned int b){
	unsigned int r = 0;

	for (unsigned int i=1; i; i<<=1) {
		r = adder(r, a & TRUTH(b));

		b >>= 1;
		a <<= 1;
	}
	
	return r;
}
