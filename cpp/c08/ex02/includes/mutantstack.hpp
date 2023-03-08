/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 13:57:24 by cbustama          #+#    #+#             */
/*   Updated: 2023/03/06 19:50:28 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP
# include <iostream>
# include <stack>

template <typename T>
class MutantStack: public std::stack<T>
{
    public:
        MutantStack();
        MutantStack(const MutantStack<T>  &copy_obj);
        ~MutantStack();
        //MutantStack  &operator=(MutantStack<T> const &n_obj);
        typedef typename MutantStack<T>::container_type::iterator iterator;
        //typedef typename container::iterator iterator;
        iterator begin(void)
        {
            return this->c.begin();
        }
        iterator end(void)
        {
            return this->c.end();
        }
};

#endif
