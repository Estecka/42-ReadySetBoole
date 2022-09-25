/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:18:46 by abaur             #+#    #+#             */
/*   Updated: 2022/09/25 18:26:07 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVAL_EXPR_HPP
#define EVAL_EXPR_HPP

#include "InvalidExprException.hpp"
#include "InvalidTreeException.hpp"
#include "IPolishItem.hpp"
#include "PolishBool.hpp"
#include "PolishNode.hpp"

bool	eval_formula(const std::string& str);

#endif
