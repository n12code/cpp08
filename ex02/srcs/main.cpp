/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:03:26 by nbodin            #+#    #+#             */
/*   Updated: 2026/03/13 17:03:25 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>
#include <vector>

int main(void)
{
    {
        std::cout << "-----MUTANT-----" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
        std::cout << std::endl;
    }
    {
        std::cout << "-----LIST-----" << std::endl;
        std::list<int> list;
        list.push_back(5);
        list.push_back(17);
        std::cout << list.back() << std::endl << std::endl;
        list.pop_back();
        std::cout << list.size() << std::endl << std::endl;
        list.push_back(3);
        list.push_back(5);
        list.push_back(737);
        list.push_back(0);
        std::list<int>::iterator it = list.begin();
        std::list<int>::iterator ite = list.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int, std::list<int> > s(list);
        std::cout << std::endl;
    }
    {
        std::cout << "-----VECTOR-----" << std::endl;
        std::vector<int> vector;
        vector.push_back(5);
        vector.push_back(17);
        std::cout << vector.back() << std::endl << std::endl;
        vector.pop_back();
        std::cout << vector.size() << std::endl << std::endl;
        vector.push_back(3);
        vector.push_back(5);
        vector.push_back(737);
        vector.push_back(0);
        std::vector<int>::iterator it = vector.begin();
        std::vector<int>::iterator ite = vector.end();
        ++it;
        --it;
        while (it != ite)
        {
        std::cout << *it << std::endl;
        ++it;
        }
        std::stack<int, std::vector<int> > s(vector);
        std::cout << std::endl;
    }
    {
        std::cout << "-----MUTANT REVERSE-----" << std::endl;
        MutantStack<int> mstack;
        mstack.push(5);
        mstack.push(17);
        std::cout << mstack.top() << std::endl << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl << std::endl;
        mstack.push(3);
        mstack.push(5);
        mstack.push(737);
        mstack.push(0);
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();
        ++it;
        --it;
        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::cout <<std::endl;
        MutantStack<int>::reverse_iterator rit = mstack.rbegin();
        MutantStack<int>::reverse_iterator rite = mstack.rend();
        ++rit;
        --rit;
        while (rit != rite)
        {
            std::cout << *rit << std::endl;
            ++rit;
        }
    }
    return (0);
}