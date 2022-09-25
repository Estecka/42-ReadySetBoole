/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InvalidExprException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:05:29 by abaur             #+#    #+#             */
/*   Updated: 2022/09/25 19:06:59 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InvalidExprException.hpp"

InvalidExprException::InvalidExprException(const std::string& what_arg)
: std::invalid_argument(what_arg)
{}
