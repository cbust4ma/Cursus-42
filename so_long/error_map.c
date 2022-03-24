/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:02:23 by cbustama          #+#    #+#             */
/*   Updated: 2022/03/23 15:37:39 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	_write(int cont)
{
	if (cont == 0)
		printf("\x1b[31mError\nOnly allowed '0', '1' 'P' And 'C'. \x1b[0m\n");
	if (cont == 1)
		printf("\x1b[31mError\nNot a rectangle or not surrounded by '1'.\x1b[0m\n");
	if (cont == 2)
		printf("\x1b[31mError\nIs not surrounded by '1'.\x1b[0m\n");
	if (cont == 3)
		printf("\x1b[31mError\nOnly one Character is allowed\x1b[0m\n");
	if (cont == 4)
		printf("\x1b[31mError\nNo Character.\x1b[0m\n");
	if (cont == 5)
		printf("\x1b[31mError\nIt is not a '.ber' file.\x1b[0m\n");
	if (cont == 6)
		printf("\x1b[31mError\nEnter a file.\x1b[0m\n");
	if (cont == 7)
		printf("\x1b[31mError\nThere must be at least one collectable.\x1b[0m\n");
	if (cont == 8)
		printf("\x1b[31mError\nThere must be at least one exit.\x1b[0m\n");
	if (cont == 9)
		printf("\x1b[31mError\nIt is empty\x1b[0m\n");
	exit(EXIT_SUCCESS);
}

int	ft_check_char(char c)
{
	return (c == '0' || c == '1' || c == 'P' || c == 'E'
		|| c == 'C' || c == '\n');
}

void	_error(t_data *l)
{
	if (l->h == '\0' && l->w == '\0')
		_write(9);
	if (l->h == l->w)
		_write(1);
}

void	_error_(t_data *l)
{
	l->j = 0;
	while (l->line[l->j])
	{
		l->i = 0;
		while (l->line[l->j][l->i] != '\n')
		{
			if (l->j == 0 || l->j == l->h - 1)
			{
				if (l->line[l->j][l->i] != '1')
					_write(2);
			}
			else
			{
				if (l->i == 0 || l->i == l->w - 1)
				{
					if (l->line[l->j][l->i] != '1')
						_write(2);
				}
			}
			l->i++;
		}	
		l->j++;
		if (l->i != l->w)
			_write(1);
	}
}

void	continue_error(t_data *l)
{
	int	count;

	l->j = 0;
	count = 0;
	while (l->line[l->j])
	{
		l->i = 0;
		while (l->line[l->j][l->i])
		{
			if (!ft_check_char(l->line[l->j][l->i]))
				_write(0);
			if (l->line[l->j][l->i] == 'P')
			{
				count++;
				if (count >= 2)
					_write(3);
			}	
			l->i++;
		}
		l->j++;
	}
	if (count == 0)
		_write(4);
	_error_(l);
	_error(l);
}
