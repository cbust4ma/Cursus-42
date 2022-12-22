/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 13:43:09 by cbustama          #+#    #+#             */
/*   Updated: 2022/12/01 19:03:32 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
    protected:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &d_copy);
        Brain &operator=(Brain const &d_copy);
        ~Brain();
};

#endif
