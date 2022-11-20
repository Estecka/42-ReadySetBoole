/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:44:28 by abaur             #+#    #+#             */
/*   Updated: 2022/11/20 17:44:41 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITSET_HPP
#define BITSET_HPP

#include <string>
#include <set>
#include <vector>

typedef std::basic_string<char>	bitstring;

bitstring       	set_to_bit(const std::set<int>& universe, const std::set<int>& set);
bitstring       	vec_to_bit(const std::set<int>& universe, const std::vector<int>& set);
std::vector<int>	bit_to_vec(const std::set<int>& universe, const bitstring& bits);

bitstring	operator&(const bitstring& a, const bitstring& b);
bitstring	operator|(const bitstring& a, const bitstring& b);
bitstring	operator^(const bitstring& a, const bitstring& b);
bitstring	operator%(const bitstring& a, const bitstring& b);
bitstring	operator<=(const bitstring& a, const bitstring& b);
bitstring	operator~(const bitstring& a);

#endif
