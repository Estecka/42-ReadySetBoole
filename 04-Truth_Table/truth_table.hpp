/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truth_table.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaur <abaur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 15:22:35 by abaur             #+#    #+#             */
/*   Updated: 2022/11/17 15:36:51 by abaur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef TRUTH_TABLE_HPP
#define TRUTH_TABLE_HPP

#include <string>

void	print_truth_table(const std::string& str);
std::string	get_truth_table(const std::string& str);

/**
 * @return true if the expression results differ in any case.
 */
bool	compare_truth_tables(const std::string& a, const std::string& b, std::string& outTable);

#endif
