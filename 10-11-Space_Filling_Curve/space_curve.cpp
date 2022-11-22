/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_curve.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:51:34 by abaur             #+#    #+#             */
/*   Updated: 2022/11/22 18:27:51 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "space_curve.hpp"

extern float	map(ushort x, ushort y){
	return ((unsigned int)y << 16) + x;
};

extern vec2 	reverse_map(float n){
	return (vec2){
		(unsigned short)n,
		(unsigned short)((int)n >> 16),
	};
};
