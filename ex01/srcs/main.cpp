/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:38:29 by nbodin            #+#    #+#             */
/*   Updated: 2026/03/11 18:30:05 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

int addLinear(void)
{
    static int  n = 0;
    return (++n);
}

int addRandom(void)
{
    return (rand() % 100000);
}

int main(void)
{
    {
        try {
            std::cout << "-----BASE EXAMPLE-----" << std::endl;
            Span sp = Span(5);

            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            
            std::cout << sp << std::endl;
            
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try {
            std::cout << "-----NEGATIVE NUMBERS-----" << std::endl;
            Span sp = Span(5);

            sp.addNumber(-2);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(-5);
            sp.addNumber(11);

            std::cout << sp << std::endl;
            
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try {
            std::cout << "-----TOO MUCH NUMBERS-----" << std::endl;
            Span sp = Span(5);

            sp.addNumber(-2);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(-5);
            sp.addNumber(11);
            sp.addNumber(23);
            
            std::cout << sp << std::endl;
            
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try {
            std::cout << "-----10000 LINEAR NUMBERS-----" << std::endl;
            Span sp = Span(10000);

            sp.addMultiple(10000, addLinear);
            //std::cout << sp << std::endl;
            
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try {
            std::cout << "-----10000 RANDOM NUMBERS-----" << std::endl;
            Span sp = Span(10000);
            srand(time(NULL));

            sp.addMultiple(10000, addRandom);
            //std::cout << sp << std::endl;
            
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try {
            std::cout << "-----ADD MULTIPLE, TOO MUCH NUMBERS-----" << std::endl;
            Span sp = Span(10);

            sp.addMultiple(11, addLinear);
            //std::cout << sp << std::endl;
            
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try {
            std::cout << "-----1 ELEMENT-----" << std::endl;
            Span sp = Span(5);

            sp.addNumber(6);
            
            std::cout << sp << std::endl;
            
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try {
            std::cout << "-----EMPTY-----" << std::endl;
            Span sp = Span(5);
            
            std::cout << sp << std::endl;
            
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}