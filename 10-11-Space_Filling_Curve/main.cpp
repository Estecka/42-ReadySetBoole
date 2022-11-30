/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:55:32 by abaur             #+#    #+#             */
/*   Updated: 2022/11/30 02:09:33 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "space_curve.hpp"
#include "../logutil/logutil.hpp"

static std::ostream& operator<<(std::ostream& out, const vec2& tuple){
	return out << '(' << tuple.x << ", " << tuple.y << ')';
}

static vec2	GetTuple(const char* str){
	const char* y=str;
	while (*y=='-' || ('0'<=*y && *y<='9'))
		y++;
	if (*y != ',') {
		ft::clog << ft::log::error << "Invalid argument: " << str << std::endl;
		exit(1);
	}
	y++;
	return (vec2){
		(unsigned short)std::atoi(str),
		(unsigned short)std::atoi(y),
	};
}

extern int	main(int argc, char** argv){
	// std::cout 
	// 	<< "float:  " << 8*sizeof(float) << "\n"
	// 	<< "double: " << 8*sizeof(double) << '\n'
	// 	<< std::endl;

	for (int i=1; i<argc; i++){
		vec2 arg = GetTuple(argv[i]);
		double n = map(arg.x, arg.y);
		vec2 r = reverse_map(n);

		bool range = (0 <= n && n <= 1);
		bool biject = (arg.x==r.x && arg.y==r.y);

		std::cout << LOG_BOLD_CLEAR << arg << LOG_CLEAR 
			<< (biject ? " <-> ": " -> ")
			<< (range ? LOG_CLEAR : LOG_BOLD_RED) << n << LOG_CLEAR
			;
		if (!biject)
			std::cout << LOG_CLEAR" -> " LOG_BOLD_RED << r;
		std::cout
			<< '\n' << (biject ? LOG_BOLD_GREEN"Bijection OK" : LOG_BOLD_RED"Bijection KO")
			<< '\n' << (range ? LOG_BOLD_GREEN"Range OK" : LOG_BOLD_RED"Range KO")
			<< '\n' << LOG_CLEAR << std::endl;
	}
}
