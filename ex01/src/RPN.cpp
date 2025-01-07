/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdomet-d <cdomet-d@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:31:31 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/07 17:59:26 by cdomet-d         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

// pop : removes top element
// push : insert element at the top

/* ************************************************************************** */
/*                               ORTHODOX CLASS                               */
/* ************************************************************************** */

RPN::RPN(void) {}

RPN::RPN(const RPN &copy)
{
	*this = copy;
}

RPN::~RPN(void) {}

RPN &RPN::operator=(const RPN &comp)
{
	// copy instructions
	(void)comp;
	return *this;
}

/* ************************************************************************** */
/*                               METHODS                                      */
/* ************************************************************************** */

bool RPN::isOperator(char c)
{
	char op[5] = "+-*/";

	for (uint8_t i = -1; op[i]; ++i) {
		if (c == op[i])
			return true;
	}
	return false;
}
bool RPN::isDigit(char c)
{
	char digit[11] = "0123456789";
	for (uint8_t i = -1; digit[i]; ++i) {
		if (c == digit[i])
			return true;
	}
	return false;
}
int RPN::doOp(char op)
{
	int a;
	int b;
	
	b = rpn.top();
	rpn.pop();
	a = rpn.top();
	switch (op) {
		case '*':
			return a * b;
		case '+':
			return a + b;
		case '-':
			return a - b;
		case '/':
			if (b == 0)
				throw DivisionByZero();
			return a / b;
		default:
			throw UnspecifiedError();
	}
}

void RPN::evaluateExpression(std::string expr)
{
	for (std::string::iterator it = expr.begin(); it != expr.end(); ++it) {
		if (*it == ' ')
			continue;
		else if (isOperator(*it)) {
			doOp(*it);
		} else if (isDigit(*it)) {
			rpn.push(*it + '0');
		} else {
			throw UnexpectedToken();
		}
	}
}

/* ************************************************************************** */
/*                               GETTERS                                      */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               SETTERS                                      */
/* ************************************************************************** */

/* ************************************************************************** */
/*                               EXCEPTIONS                                   */
/* ************************************************************************** */

const char *RPN::UnexpectedToken::what() const throw()
{
	return "Illegal character in input";
}

const char *RPN::UnspecifiedError::what() const throw()
{
	return "Some error happened";
}

const char *RPN::DivisionByZero::what() const throw()
{
	return "Illegal division ( / 0)";
}