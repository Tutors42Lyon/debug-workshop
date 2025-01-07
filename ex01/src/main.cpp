/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:57:46 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/07 15:22:36 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int ac, char *av[])
{
	if (ac < 2) {
		std::cerr << "Usage: ./RPN <input>" << std::endl;
		return 1;
	}

	RPN rpn;
	std::string expr = av[1];
	try {
		rpn.evaluateExpression(expr);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}