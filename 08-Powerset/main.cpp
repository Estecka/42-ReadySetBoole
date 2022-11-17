/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:36:23 by abaur             #+#    #+#             */
/*   Updated: 2022/11/17 19:05:39 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "powerset.hpp"

#include "../logutil/logutil.hpp"

#include <stdlib.h>
#include <iostream>

template <class T>
std::ostream&	operator<<(std::ostream& cout, const std::vector<T>& vec){
	cout << "{ ";

	for (size_t i=0; i<vec.size(); i++){
		if (i)
			cout << ", ";
		cout << vec[i];
	}

	cout << " }";
	return cout;
}

extern int	main(int argc, char** argv){
	t_Set set(argc-1);
	for (int i=1; i<argc; i++)
		set[i-1] = std::atoi(argv[i]);

	std::cout << LOG_BOLD_CLEAR << set.size() << '\t' << set << LOG_CLEAR << std::endl;

	t_PowerSet power = powerset(set);
	std::cout << LOG_CYAN << power.size() << '\t' << power << LOG_CLEAR << '\n' << std::endl;	
}
