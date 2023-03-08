/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:24:26 by cbustama          #+#    #+#             */
/*   Updated: 2023/02/24 21:06:47 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP
# include <iostream>
# include <vector>
# include <algorithm>

class span
{
    private:
        int _n;
        std::vector<int> myvector;
    public:
        span();
        span(int n);
        ~span();
        span(const span  &copy_obj);
        span const &operator=(span const &n_obj);
        void addNumber(int n);
        std::vector<int> &get();
        int shortestSpan();
        int longestSpan();
};
#endif // !SPAN_HPP
