/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:44:28 by abaur             #+#    #+#             */
/*   Updated: 2022/11/18 18:16:28 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITSET_HPP
#define BITSET_HPP

#include <string>
#include <set>
#include <vector>

typedef std::basic_string<int>	bitset;

bitset          	set_to_bit(const std::set<int>& universe, const std::set<int>& set);
bitset          	vec_to_bit(const std::set<int>& universe, const std::vector<int>& set);
std::vector<int>	bit_to_vec(const std::set<int>& universe, const bitset& bits);

bitset	operator&(const bitset& a, const bitset& b);
bitset	operator|(const bitset& a, const bitset& b);
bitset	operator^(const bitset& a, const bitset& b);
bitset	operator%(const bitset& a, const bitset& b);
bitset	operator<=(const bitset& a, const bitset& b);
bitset	operator~(const bitset& a);

#endif
