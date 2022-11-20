/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:21:03 by abaur             #+#    #+#             */
/*   Updated: 2022/11/20 15:27:27 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./eval_set.hpp"
#include "../logutil/logutil.hpp"
#include "../polishtree/PolishTree.hpp"

#include <iostream>
#include <set>
#include <string>
#include <stdnoreturn.h>
#include <vector>
#include <cstdlib>
#include <cstring>

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

static void	CheckSet(const char* str, std::vector<std::vector<int>> allSets){
	int	checklist = 0;
	size_t	varcount = 0;

	for (str; *str; str++)
	if ('A' <= *str && *str <= 'Z')
	{
		short offset = 'A' - *str;
		if (!(checklist & (1<<offset))){
			varcount++;
			checklist |= 1<<offset;
		}
	}
	if (allSets.size() < varcount) {
		ft::clog << ft::log::error << "Not enough sets provided" << std::endl;
		exit (1);
	}
}

static std::vector<int>	ParseSet(const char* str){
	std::vector<int> result;

	while(*str){
		result.push_back(std::atoi(str));
		while (*str && *str!=',')
			str++;
		if (*str == ',')
			str++;
	}

	return result;
}

static noreturn	void ArgcThrow(){
	std::cerr << "Not enough arguments" << std::endl;
	exit(1);
}
extern int	main(int argc, char** argv){
	if (argc < 3 )
		ArgcThrow();


	const char*const expr = argv[1];
	std::vector<std::vector<int>>	allSets;
	for (int i=2; i<argc; i++)
		allSets.push_back(ParseSet(argv[i]));
	CheckSet(expr, allSets);
	for (size_t x=0; x<allSets.size(); x++)
	if (allSets[x].size()) {
		std::cout << LOG_BOLD_CYAN << (char)('A'+x) << ": " << allSets[x] << std::endl;
	}

	std::cout << LOG_BOLD_CLEAR << expr << LOG_CLEAR << std::endl;

	{
		IPolishItem* tree;
		std::string remainder;
		BuildTree(expr, tree, remainder);
		std::cout << tree->Draw();
		delete tree;
		if (remainder.size())
			ft::clog << ft::log::warning << "Expression has trailing characters" << std::endl;
	}
	std::cout << " = " << eval_set(expr, allSets) << std::endl;

	std::cout << std::endl;
}
