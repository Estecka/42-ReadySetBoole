/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitstring.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:45:47 by abaur             #+#    #+#             */
/*   Updated: 2022/11/20 19:18:42 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitstring.hpp"

// #include <iostream>

#define sizeof_bitchunk	(8*sizeof(bitstring::value_type))

bitstring	vec_to_bit(const std::set<int>& universe, const std::vector<int>& vec){
	return set_to_bit(universe, std::set<int>(vec.begin(), vec.end()));
}
bitstring	set_to_bit(const std::set<int>& universe, const std::set<int>& set){
	bitstring result;
	for (size_t i=0; i<universe.size(); i+=sizeof_bitchunk)
		result.push_back(0);

	size_t n=0, i=0;
	for (std::set<int>::const_iterator elt=universe.begin(); elt!=universe.end(); elt++, i++){
		if (i >= sizeof_bitchunk)
			n++, i-= sizeof_bitchunk;
		if (set.find(*elt) != set.end()) {
			result[n] |= 1 << i;
			// std::cerr << n << " " << i << " = " << *elt << std::endl;
		}
	}

	return result;
}

std::vector<int>	bit_to_vec(const std::set<int>& universe, const bitstring& bits){
	std::vector<int> result;

	size_t n=0, i=0;
	for (std::set<int>::const_iterator elt=universe.begin(); elt!=universe.end(); elt++, i++){
		if (i >= sizeof_bitchunk)
			n++, i-= sizeof_bitchunk;
		if ((bits[n] >> i) & 1){
			result.push_back(*elt);
			// std::cerr << n << " " << i << " = " << *elt << std::endl;
		}
	}

	return result;
}

bitstring	operator&(const bitstring& a, const bitstring& b){
	bitstring r = a;
	for (size_t i=0; i<b.length(); i++)
		r[i] &= b[i];
	return r;
}
bitstring	operator|(const bitstring& a, const bitstring& b){
	bitstring r = a;
	for (size_t i=0; i<b.length(); i++)
		r[i] |= b[i];
	return r;
}
bitstring	operator^(const bitstring& a, const bitstring& b){
	bitstring r = a;
	for (size_t i=0; i<b.length(); i++)
		r[i] ^= b[i];
	return r;
}
bitstring	operator%(const bitstring& a, const bitstring& b){
	bitstring r = a;
	for (size_t i=0; i<b.length(); i++)
		r[i] = ~(a[i] ^ b[i]);
	return r;
}
bitstring	operator<=(const bitstring& a, const bitstring& b){
	bitstring r = a;
	for (size_t i=0; i<b.length(); i++)
		r[i] = b[i] | ~a[i];
	return r;
}
bitstring	operator~(const bitstring& a) {
	bitstring r = a;
	for (size_t i=0; i<a.length(); i++)
		r[i] = ~r[i];
	return r;
}
