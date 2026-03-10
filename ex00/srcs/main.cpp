/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbodin <nbodin@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 15:47:23 by nbodin            #+#    #+#             */
/*   Updated: 2026/03/10 17:30:57 by nbodin           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <string>

int main(void)
{
    {
        try {
            std::cout << "-----VECTOR-----" << std::endl;
            std::vector<int>    v;
            v.push_back(1);
            v.push_back(4);
            v.push_back(2);
            v.push_back(7);
            v.push_back(8);
            displayContainer(v);
            easyfind(v, 2);
            std::cout << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try {
            std::cout << "-----LIST-----" << std::endl;
            std::list<int>    l;
            l.push_back(1);
            l.push_back(4);
            l.push_back(2);
            l.push_back(7);
            l.push_back(8);
            displayContainer(l);
            easyfind(l, 7);
            std::cout << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try {
            std::cout << "-----DEQUE-----" << std::endl;
            std::deque<int>    d;
            d.push_back(1);
            d.push_back(4);
            d.push_back(2);
            d.push_back(7);
            d.push_back(8);
            displayContainer(d);
            easyfind(d, 8);
            std::cout << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try {
            std::cout << "-----NOT FOUND-----" << std::endl;
            std::vector<int>    v;
            v.push_back(1);
            v.push_back(4);
            v.push_back(2);
            v.push_back(7);
            v.push_back(8);
            displayContainer(v);
            easyfind(v, 9);
            std::cout << std::endl;
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        try {
            std::cout << "-----CHAR CONTAINER-----" << std::endl;
            std::vector<char>    v;
            v.push_back('1');
            v.push_back('4');
            v.push_back('2');
            v.push_back('7');
            displayContainer(v);
            v.push_back('8');
            easyfind(v, '4');
        }
        catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    // {
    //     try {
    //         std::cout << "-----STRING CONTAINER-----" << std::endl;
    //         std::vector<std::string>    v;
    //         v.push_back("hello");
    //         v.push_back("my");
    //         v.push_back("friend");
    //         displayContainer(v);
    //         easyfind(v, 97);
    //     }
    //     catch (const std::exception &e) {
    //         std::cout << e.what() << std::endl;
    //     }
    // }
    return (0);
}