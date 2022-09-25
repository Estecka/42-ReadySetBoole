/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InvalidTreeException.cpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 19:05:29 by abaur             #+#    #+#             */
/*   Updated: 2022/09/25 19:07:25 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InvalidTreeException.hpp"

InvalidTreeException::InvalidTreeException(const std::string& what_arg)
: std::runtime_error(what_arg)
{}
