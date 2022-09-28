/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InvalidExprException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:06:35 by abaur             #+#    #+#             */
/*   Updated: 2022/09/28 16:11:16 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVALIDEXPREXCEPTION_HPP
#define INVALIDEXPREXCEPTION_HPP

#include <stdexcept>

class InvalidExprException : public std::invalid_argument
{
public:
	InvalidExprException(const std::string& what_arg);
};


#endif
