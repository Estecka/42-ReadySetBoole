/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InvalidTreeException.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 18:06:35 by abaur             #+#    #+#             */
/*   Updated: 2022/09/28 16:11:23 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INVALIDTREEEXCEPTION_HPP
#define INVALIDTREEEXCEPTION_HPP

#include <stdexcept>

class InvalidTreeException : public std::runtime_error
{
public:
	InvalidTreeException(const std::string& what_arg);
};


#endif
