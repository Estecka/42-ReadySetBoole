/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:36:58 by abaur             #+#    #+#             */
/*   Updated: 2022/11/17 19:14:40 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "powerset.hpp"

extern t_PowerSet	powerset(const t_Set& set){
	const int	setsize = set.size();
	const int	powersize = 1 << setsize;
	t_PowerSet result(powersize);

	for (int i=0; i<powersize; i++){
		result[i].reserve(setsize);
		for (int j=0; j<setsize; j++){
			if (1 & (i>>j))
				result[i].push_back(set[j]);
		}
	}

	return result;
}
