/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:48:38 by nbodin            #+#    #+#             */
/*   Updated: 2026/03/10 17:41:49 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>
# include <exception>
# include <iostream>

class   NotFoundException : public std::exception
{
    virtual const char* what() const throw();
};

const char *NotFoundException::what() const throw()
{
    return ("Element not found in the container\n");
}

template <typename T>
void    easyfind(const T &container, const int &number)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), number);
    if (it != container.end())
        std::cout << number << " was first found at index " << std::distance(container.begin(),it) << std::endl;
    else
        throw NotFoundException();
}

template <typename T>
void    displayContainer(const T &container)
{
    for (typename T::const_iterator it = container.begin(); it != container.end(); it++)
        std::cout << *it  << " ";
    std::cout << std::endl;
}

#endif