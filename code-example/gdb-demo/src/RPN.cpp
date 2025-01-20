/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcottet <lcottet@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 11:31:31 by cdomet-d          #+#    #+#             */
/*   Updated: 2025/01/20 10:19:35 by lcottet          ###   ########lyon.fr   */
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
	char	op[5] = "+-*/";
	uint8_t i;

	for (i = 0; op[i]; ++i) {
		if (c == op[i])
			return true;
	}
	return false;
}
bool RPN::isDigit(char c)
{
	char 	digit[11] = "0123456789";
	uint8_t i;

	for (i = 0; digit[i]; ++i) {
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
	for (size_t i = 0;i < expr.length(); ++i) {
		if (expr[i] == ' ')
			continue;
		else if (isOperator(expr[i])) {
			doOp(expr[i]);
		} else if (isDigit(expr[i])) {
			rpn.push(expr[i] + '0');
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