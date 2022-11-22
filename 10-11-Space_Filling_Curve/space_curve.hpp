/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_curve.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:39:33 by abaur             #+#    #+#             */
/*   Updated: 2022/11/22 17:50:00 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SPACE_CURVE_HPP
#define SPACE_CURVE_HPP

#define ushort	unsigned short

struct vec2{
	ushort x;
	ushort y;
};

float	map(ushort x, ushort y);
vec2 	reverse_map(float n);

#endif
