/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:31:26 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/07 16:57:03 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <stdint.h>
#include <string>

class RPN {
  public:
	/*                               ORTHODOX CLASS                           */
	RPN(void);
	RPN(const RPN &copy);
	~RPN(void);
	RPN &operator=(const RPN &copy);

	/*                               METHODS                                  */
	void evaluateExpression(std::string expr);

	/*                               GETTERS                                  */

	/*                               SETTERS                                  */
  private:
	std::stack< int > rpn;

	/*                               METHODS                                  */
	bool isOperator(char c);
	bool isDigit(char c);
	bool hasEnoughOperands();
	int doOp(char op);

	/*                               EXCEPTIONS                               */
	class UnexpectedToken : public std::exception {
	  public:
		const char *what() const throw();
	};
	class UnspecifiedError : public std::exception {
	  public:
		const char *what() const throw();
	};
	class DivisionByZero : public std::exception {
	  public:
		const char *what() const throw();
	};
};

#endif
