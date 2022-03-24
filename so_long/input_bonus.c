/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:43:07 by cbustama          #+#    #+#             */
/*   Updated: 2022/03/22 18:17:56 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	_s(t_data *line)
{
	if (line->line[line->p.y + 1][line->p.x] == '1')
		return ;
	if (line->line[line->p.y + 1][line->p.x] == 'E' && line->out == line->c)
		_esc(line);
	if (line->line[line->p.y + 1][line->p.x] == 'K')
		_esc(line);
	else if (line->line[line->p.y + 1][line->p.x] == 'E')
		return ;
	if (line->line[line->p.y + 1][line->p.x] == '0')
	{
		line->line[line->p.y + 1][line->p.x] = 'P';
		line->line[line->p.y][line->p.x] = '0';
		line->p.y += 1;
	}
	else if (line->line[line->p.y + 1][line->p.x] == 'C')
	{	
		line->line[line->p.y][line->p.x] = '0';
		line->line[line->p.y + 1][line->p.x] = '0';
		line->line[line->p.y + 1][line->p.x] = 'P';
		line->p.y += 1;
		line->c++;
	}
	_walk_s(line);
}

void	_a(t_data *line)
{
	if (line->line[line->p.y][line->p.x - 1] == '1')
		return ;
	if (line->line[line->p.y][line->p.x - 1] == 'E' && line->out == line->c)
		_esc(line);
	if (line->line[line->p.y][line->p.x - 1] == 'K')
		_esc(line);
	else if (line->line[line->p.y][line->p.x - 1] == 'E')
		return ;
	if (line->line[line->p.y][line->p.x - 1] == '0')
	{
		line->line[line->p.y][line->p.x - 1] = 'P';
		line->line[line->p.y][line->p.x] = '0';
		line->p.x -= 1;
	}
	else if (line->line[line->p.y][line->p.x - 1] == 'C')
	{
		line->line[line->p.y][line->p.x] = '0';
		line->line[line->p.y][line->p.x - 1] = '0';
		line->line[line->p.y][line->p.x - 1] = 'P';
		line->p.x -= 1;
		line->c++;
	}
	_walk_a(line);
}

void	_d(t_data *line)
{
	if (line->line[line->p.y][line->p.x + 1] == '1')
		return ;
	if (line->line[line->p.y][line->p.x + 1] == 'E' && line->out == line->c)
		_esc(line);
	if (line->line[line->p.y][line->p.x + 1] == 'K')
		_esc(line);
	else if (line->line[line->p.y][line->p.x + 1] == 'E')
		return ;
	if (line->line[line->p.y][line->p.x + 1] == '0')
	{
		line->line[line->p.y][line->p.x + 1] = 'P';
		line->line[line->p.y][line->p.x] = '0';
		line->p.x += 1;
	}
	else if (line->line[line->p.y][line->p.x + 1] == 'C')
	{
		line->line[line->p.y][line->p.x] = '0';
		line->line[line->p.y][line->p.x + 1] = '0';
		line->line[line->p.y][line->p.x + 1] = 'P';
		line->p.x += 1;
		line->c++;
	}
	_walk_d(line);
}

void	_w(t_data *line)
{
	if (line->line[line->p.y - 1][line->p.x] == '1')
		return ;
	if (line->line[line->p.y - 1][line->p.x] == 'E' && line->out == line->c)
		_esc(line);
	if (line->line[line->p.y - 1][line->p.x] == 'K')
		_esc(line);
	else if (line->line[line->p.y - 1][line->p.x] == 'E')
		return ;
	if (line->line[line->p.y - 1][line->p.x] == '0')
	{
		line->line[line->p.y - 1][line->p.x] = 'P';
		line->line[line->p.y][line->p.x] = '0';
		line->p.y -= 1;
		_walk(line);
	}
	else if (line->line[line->p.y - 1][line->p.x] == 'C')
	{	
		line->line[line->p.y][line->p.x] = '0';
		line->line[line->p.y - 1][line->p.x] = '0';
		line->line[line->p.y - 1][line->p.x] = 'P';
		line->p.y -= 1;
		line->c++;
		_walk(line);
	}
}
