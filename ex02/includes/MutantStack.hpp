/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:14:03 by nbodin            #+#    #+#             */
/*   Updated: 2026/03/13 16:41:53 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack<T> &copy);
        ~MutantStack();

        MutantStack<T>&    operator=(const MutantStack<T> &other);
        
        typedef         typename std::stack<T>::container_type::iterator                iterator;
        typedef         typename std::stack<T>::container_type::const_iterator          const_iterator;
        typedef         typename std::stack<T>::container_type::reverse_iterator        reverse_iterator;
        typedef         typename std::stack<T>::container_type::const_reverse_iterator  const_reverse_iterator;

        iterator                begin();
        iterator                end();

        const_iterator          begin() const;
        const_iterator          end() const;

        reverse_iterator        rbegin();
        reverse_iterator        rend();
        
        const_reverse_iterator  rbegin() const;
        const_reverse_iterator  rend() const;
};

template <typename T>
MutantStack<T>::MutantStack() :
    std::stack<T>::stack() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy) :
    std::stack<T>::stack(copy) {}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
MutantStack<T>&     MutantStack<T>::operator=(const MutantStack<T> &other)
{
    if (this != other)
        std::stack<T>::operator=(other);
    return (*this);
}

template <typename T>
typename    MutantStack<T>::iterator    MutantStack<T>::begin() {return (std::stack<T>::c.begin());}

template <typename T>
typename    MutantStack<T>::iterator    MutantStack<T>::end() {return (std::stack<T>::c.end());}

template <typename T>
typename    MutantStack<T>::const_iterator  MutantStack<T>::begin() const {return (std::stack<T>::c.begin());}

template <typename T>
typename    MutantStack<T>::const_iterator  MutantStack<T>::end() const {return (std::stack<T>::c.end());}

template <typename T>
typename    MutantStack<T>::reverse_iterator    MutantStack<T>::rbegin() {return (std::stack<T>::c.rbegin());}

template <typename T>
typename    MutantStack<T>::reverse_iterator    MutantStack<T>::rend() {return (std::stack<T>::c.rend());}

template <typename T>
typename    MutantStack<T>::const_reverse_iterator  MutantStack<T>::rbegin() const {return (std::stack<T>::c.rbegin());}

template <typename T>
typename    MutantStack<T>::const_reverse_iterator  MutantStack<T>::rend() const {return (std::stack<T>::c.rend());}


#endif