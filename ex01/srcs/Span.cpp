/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:06:23 by nbodin            #+#    #+#             */
/*   Updated: 2026/03/11 18:29:15 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <cstddef>
#include <algorithm>
#include <vector>
#include <iostream>

Span::Span() :
    _maxElements(0) {}

Span::Span(const unsigned int &numberOfElements) :
    _maxElements(numberOfElements) {}

Span::~Span() {}

Span::Span(const Span &copy) :
    _maxElements(copy._maxElements)
{
    if (!copy._elements.empty())
    {
        for (size_t i = 0; i < copy._elements.size(); i++)
            _elements.push_back(copy._elements.at(i));
    }
}

Span&   Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _elements.clear();
        if (!other._elements.empty())
        {
            for (size_t i = 0; i < other._elements.size(); i++)
                _elements.push_back(other._elements.at(i));
        }
    }
    return (*this);
}

int     Span::operator[](const unsigned int index) const
{
    return (_elements.at(index));
}

std::ostream&  operator<<(std::ostream &os, const Span &obj)
{
    if (obj.getSize() == 0)
        return (os);
    for (size_t i = 0; i < obj.getSize(); i++)
        os << obj[i] << ' ';
    os << std::endl;
    return (os);
}

const char* Span::VectorFullException::what() const throw()
{
    return ("Cant add more elements, the vector is full.\n");
}

const char* Span::NotEnoughElementsException::what() const throw()
{
    return ("There aren't enough elements to perform a span function.\n");
}

unsigned int    Span::getSize() const
{
    return (_elements.size());
}

void    Span::addNumber(const int number)
{
    if (_elements.size() + 1 > _maxElements)
        throw (VectorFullException());
    else
        _elements.push_back(number);
}

void    Span::addMultiple(const unsigned int quantity, int (*func)())
{
    if (_elements.size() + quantity > _maxElements)
        throw (VectorFullException());
    else
        std::generate_n(std::back_inserter(_elements), quantity, func);
}

unsigned int     Span::shortestSpan() const
{
    if (_elements.size() < 2)
        throw (NotEnoughElementsException());
    else
    {
        std::vector<int>    copy;
        unsigned int        shortestSpan;
        unsigned int        tempSpan;
        
        for (size_t i = 0; i < _elements.size(); i++)
                copy.push_back(_elements.at(i));
        std::sort(copy.begin(), copy.end()); 
        shortestSpan = copy.at(1) - copy.at(0);
        for (size_t i = 0; i < copy.size()- 1; i++)
        {
            tempSpan = copy.at(i + 1) - copy.at(i);
            if (tempSpan < shortestSpan)
                shortestSpan = tempSpan;
        }
        return (shortestSpan);
    }
}

unsigned int     Span::longestSpan() const
{
    if (_elements.size() < 2)
        throw (NotEnoughElementsException());
    else
    {
        std::vector<int>    copy;
        
        for (size_t i = 0; i < _elements.size(); i++)
                copy.push_back(_elements[i]);
        std::sort(copy.begin(), copy.end());
        return (copy.back() - copy.front());
    }
}


