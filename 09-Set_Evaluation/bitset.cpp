/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:45:47 by abaur             #+#    #+#             */
/*   Updated: 2022/11/18 18:19:55 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bitset.hpp"

bitset	vec_to_bit(const std::set<int>& universe, const std::vector<int>& vec){
	return set_to_bit(universe, std::set<int>(vec.begin(), vec.end()));
}
bitset	set_to_bit(const std::set<int>& universe, const std::set<int>& set){
	bitset result;

	std::set<int>::const_iterator elt = universe.begin();
	for (int n=0; (n*sizeof(int))<universe.size(); n++){
		result.push_back(0);
		for (int i=0; (n*sizeof(int)+i)<universe.size(); i++, elt++) {
			if (set.find(*elt) != set.end())
				result[n] |= 1 << i;
		}
	}

	return result;
}

std::vector<int>	bit_to_vec(const std::set<int>& universe, const bitset& bits){
	std::vector<int> result;

	std::set<int>::const_iterator elt = universe.begin();
	for (int n=0; (n*sizeof(int))  <universe.size(); n++)
	for (int i=0; (n*sizeof(int)+i)<universe.size(); i++, elt++) {
		if ((bits[n] >> i) & 1)
			result.push_back(*elt);
	}

	return result;
}

bitset	operator&(const bitset& a, const bitset& b){
	bitset r = a;
	for (size_t i=0; i<b.length(); i++)
		r[i] &= b[i];
	return r;
}
bitset	operator|(const bitset& a, const bitset& b){
	bitset r = a;
	for (size_t i=0; i<b.length(); i++)
		r[i] |= b[i];
	return r;
}
bitset	operator^(const bitset& a, const bitset& b){
	bitset r = a;
	for (size_t i=0; i<b.length(); i++)
		r[i] ^= b[i];
	return r;
}
bitset	operator%(const bitset& a, const bitset& b){
	bitset r = a;
	for (size_t i=0; i<b.length(); i++)
		r[i] = !(a[i] ^ b[i]);
	return r;
}
bitset	operator<=(const bitset& a, const bitset& b){
	bitset r = a;
	for (size_t i=0; i<b.length(); i++)
		r[i] = b[i] | ~a[i];
	return r;
}
bitset	operator~(const bitset& a) {
	bitset r = a;
	for (size_t i=0; i<a.length(); i++)
		r[i] = ~r[i];
	return r;
}
