/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 17:36:47 by cbustama          #+#    #+#             */
/*   Updated: 2022/03/23 15:56:38 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	continue_line(t_data *l_2, int count, char **arg)
{
	int	fd;
	int	a;

	if (count == 0)
		_write(10);
	fd = 0;
	l_2->h = count;
	l_2->line = (char **)malloc(sizeof(char *) * (count + 1));
	fd = open(arg[0], O_RDONLY);
	a = count;
	count = 0;
	while (count < a)
		l_2->line[count++] = get_next_line(fd);
	close (fd);
	l_2->line[count] = NULL;
}

void	_line(char **arg, t_data *l_2)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(arg[0], O_RDONLY);
	if (fd == -1)
	{
		_write(6);
	}
	else
	{
		line = get_next_line(fd);
		while (line != NULL)
		{	
			free(line);
			line = get_next_line(fd);
			count++;
		}
		free(line);
		close (fd);
	}
	continue_line (l_2, count, &arg[0]);
}

void	end_game(t_data *l)
{
	int	a;
	int	b;

	if (l->out == l->c)
	{
		l->j = 0;
		while (l->line[l->j])
		{
			l->i = 0;
			while (l->line[l->j][l->i] != '\n')
			{
				if (l->line[l->j][l->i] == 'E')
				{
					a = l->i * N;
					b = l->j * N;
					l->addr = mlx_xpm_file_to_image(l->p_, TP2, &l->n, &l->n);
					mlx_put_image_to_window(l->p_, l->win, l->addr, a, b);
				}
				l->i++;
			}
			l->j++;
		}
	}
}

void	init_var(char **argv)
{
	t_data	line;

	line.n = 50;
	line.c = 0;
	line.p.w = 1;
	line.p.d_ = 1;
	line.p.a_ = 1;
	line.p.s_ = 1;
	line.p.count = 0;
	line.out = 0;
	_line(&argv[0], &line);
	line.w = ft_strlen(line.line[0]) - 1;
	line.p_ = mlx_init();
	line.win = mlx_new_window(line.p_, line.w * N, line.h * N, "./so_long");
	line.enemy = _enemy(line);
	img_put(&line);
	_error_two(&line);
	_movement(&line);
	mlx_hook(line.win, 2, 1L << 0, _input, &line);
	mlx_hook(line.win, 17, 1L << 17, _esc, &line);
	mlx_loop(line.p_);
}

int	main(int argc, char **argv)
{
	int		i;

	if (argc != 2)
		_write(6);
	i = ft_strlen(argv[1]) - 1;
	if ((argv[1][i] != 'r') || (argv[1][i - 1] != 'e')
		|| (argv[1][i - 2] != 'b') || (argv[1][i - 3] != '.'))
		_write(5);
	init_var(&argv[1]);
	return (0);
}
