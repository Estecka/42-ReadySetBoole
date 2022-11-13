/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exprgen.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 21:57:26 by abaur             #+#    #+#             */
/*   Updated: 2022/11/13 14:53:34 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPRGEN_HPP
#define EXPRGEN_HPP

#include <string>

/**
 * @param complexity	The amount of operators the expression will contain.
 */
std::string	exprgen(size_t complexity);

#endif
