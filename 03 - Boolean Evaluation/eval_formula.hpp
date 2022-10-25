/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_formula.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:18:46 by abaur             #+#    #+#             */
/*   Updated: 2022/10/25 17:51:26 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_FORMULA_HPP
#define EVAL_FORMULA_HPP

#include <string>

/**
 * @param varmap	Indicates the value to substitue variables with. Variables 
 * 	are indexed based on their name, in order from A to Z.
 * @param outSize	The size of the parsed expression. May be smaller than the 
 * 	input string's length.
 */
bool	eval_formula(const std::string& str, const bool varmap[26], size_t& outSize);
bool	eval_formula(const std::string& str, const bool varmap[26]);
bool	eval_formula(const std::string& str, size_t& outSize);
bool	eval_formula(const std::string& str);

#endif
