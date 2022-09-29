/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:12:29 by cbustama          #+#    #+#             */
/*   Updated: 2022/09/27 20:10:38 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "contact.hpp"
# include <iomanip>
# include <string>
class phonebook
{
	public:
		phonebook()
		{
			return ;
		}

		~phonebook()
		{
			return ;
		}

		contact _agend[8];
		void	add(int i);
		void	search();
		void	index_data (int i)
		{
			if (i > 7)
				std::cout << "ERROR NO VALID NUMBER" << std::endl;
			else
			{
				std::cout << "Firts Name = " << _agend[i].get_firstname() << std::endl;
				std::cout << "Last Name = " << _agend[i].get_lastname() << std::endl;
				std::cout << "Nick Name = " << _agend[i].get_nickname() << std::endl;
				std::cout << "Phone = " << _agend[i].get_phone() << std::endl;
				std::cout << "Dark Secret = " << _agend[i].get_darksecret() << std::endl;		
			}
	}
};

#endif
