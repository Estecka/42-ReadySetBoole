/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:18:46 by abaur             #+#    #+#             */
/*   Updated: 2022/10/07 18:18:56 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_HPP
#define EVAL_EXPR_HPP

#include "InvalidExprException.hpp"
#include "InvalidTreeException.hpp"
#include "IPolishItem.hpp"
#include "PolishBool.hpp"
#include "PolishNode.hpp"
#include "PolishNot.hpp"

bool	eval_formula(const std::string& str);

#endif
