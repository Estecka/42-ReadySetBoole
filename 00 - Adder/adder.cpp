/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adder.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:57:59 by abaur             #+#    #+#             */
/*   Updated: 2022/09/15 19:53:47 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern unsigned int	adder(unsigned int a, unsigned int b){
	unsigned int carry;

	for (unsigned int i=1; i|0; i<<=1) {
		carry = (a & b) << 1;
		a ^= b;
		b = carry;
	}

	return a;
}
