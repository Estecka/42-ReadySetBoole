/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TreeBuilder.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:59:48 by abaur             #+#    #+#             */
/*   Updated: 2022/10/10 15:06:25 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREEBUILDER_HPP
#define TREEBUILDER_HPP

#include "./IPolishItem.hpp"

void	BuildTree(const std::string& expr, IPolishItem*& outTree, std::string& outRemainder);

#endif
