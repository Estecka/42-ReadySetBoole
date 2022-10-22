/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:18:46 by abaur             #+#    #+#             */
/*   Updated: 2022/10/22 17:52:15 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_HPP
#define EVAL_EXPR_HPP

#include <string>

/**
 * @param outSize	The size of the parsed expression. May be smaller than the 
 * 	input string's length.
 */
bool	eval_formula(const std::string& str, size_t& outSize);

bool	eval_formula(const std::string& str);

#endif
