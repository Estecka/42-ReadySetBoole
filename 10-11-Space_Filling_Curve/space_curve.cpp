/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_curve.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:51:34 by abaur             #+#    #+#             */
/*   Updated: 2022/11/30 02:29:25 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "space_curve.hpp"

extern double	map(ushort x, ushort y){
	unsigned int xy = ((unsigned int)y << 16) | x;
	double f = 0;

	for (int i=0; i<32; i++)
	if (1 & (xy >> i))
		f += 1.0/(2L << i);

	return f;
};

extern vec2 	reverse_map(double n){
	unsigned int xy = 0;
	double step = 0;

	for (int i=0; i<32; i++){
		double frac = 1.0/(2L << i);
		if (n >= step+frac) {
			step+=frac;
			xy |= 1 << i;
		}
	}

	return (vec2){
		(unsigned short)(xy),
		(unsigned short)(xy >> 16),
	};
};
