/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 20:10:16 by cbustama          #+#    #+#             */
/*   Updated: 2023/03/27 20:10:16 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RPN.hpp>

int main(int argc, char **argv)
{
    if (argc != 2)
        return (1);
    RPN rpn;
    if (rpn.rpn(argv[1]) == 1)
        std::cout << "Ha ocurrido un error" << std::endl;
    std::cout << std::endl;
    return 0;
}
