/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:33:41 by abaur             #+#    #+#             */
/*   Updated: 2022/11/17 19:02:47 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef POWERSET_HPP
#define POWERSET_HPP

#include <vector>

typedef std::vector<int>	t_Set;
typedef std::vector<std::vector<int>>	t_PowerSet;

t_PowerSet	powerset(const t_Set& set);

#endif
