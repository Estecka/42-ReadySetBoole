/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitstring.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:45:47 by abaur             #+#    #+#             */
/*   Updated: 2022/11/20 17:46:17 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitstring.hpp"

bitstring	vec_to_bit(const std::set<int>& universe, const std::vector<int>& vec){
	return set_to_bit(universe, std::set<int>(vec.begin(), vec.end()));
}
bitstring	set_to_bit(const std::set<int>& universe, const std::set<int>& set){
	bitstring result;

	std::set<int>::const_iterator elt = universe.begin();
	for (int n=0; (n*8*sizeof(bitstring::value_type))<universe.size(); n++){
		result.push_back(0);
		for (int i=0; (n*sizeof(int)+i)<universe.size(); i++, elt++) {
			if (set.find(*elt) != set.end())
				result[n] |= 1 << i;
		}
	}

	return result;
}

std::vector<int>	bit_to_vec(const std::set<int>& universe, const bitstring& bits){
	std::vector<int> result;

	std::set<int>::const_iterator elt = universe.begin();
	for (int n=0; (n*8*sizeof(bitstring::value_type))  <universe.size(); n++)
	for (int i=0; (n*8*sizeof(bitstring::value_type)+i)<universe.size(); i++, elt++) {
		if ((bits[n] >> i) & 1)
			result.push_back(*elt);
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
