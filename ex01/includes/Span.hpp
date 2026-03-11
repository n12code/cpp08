/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 14:22:42 by nbodin            #+#    #+#             */
/*   Updated: 2026/03/11 18:15:49 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>

class Span
{
    private:
        const unsigned int  _maxElements;
        std::vector<int>    _elements;
    public:
        Span();
        Span(const unsigned int &numberOfElements);
        ~Span();
        Span(const Span &copy);

        Span&   operator=(const Span &other);
        int     operator[](const unsigned int index) const;

        class VectorFullException : public std::exception {
            virtual const char* what() const throw();
        };
        class NotEnoughElementsException : public std::exception {
            virtual const char* what() const throw();
        };
        
        unsigned int        getSize() const;
        void                addNumber(int number);
        void                addMultiple(const unsigned int quantity, int (*func)());
        unsigned int        shortestSpan() const;
        unsigned int        longestSpan() const; 
};

std::ostream&  operator<<(std::ostream &os, const Span &obj);

#endif