/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbustama <cbustama@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 15:14:58 by cbustama          #+#    #+#             */
/*   Updated: 2022/03/22 17:41:14 by cbustama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# define _CRTDBG_MAP_ALLOC
# define BACK "./image/back.xpm"
# define GROUND "./image/ground.xpm"
# define _GROUND "./image/_ground.xpm"
# define COLLEC "./image/coffee.xpm"
# define _BACK "./image/back2.xpm"
# define BEER "./image/beer.xpm"
# define PJ_ "./image/pj1.xpm"
# define PJ_1 "./image/pj2.xpm"
# define W_0 "./image/w1.xpm"
# define W_1 "./image/w2.xpm"
# define TP_ "./image/teleport.xpm"
# define TP2 "./image/tp2.xpm"
# define D_0 "./image/d1.xpm"
# define D_1 "./image/d2.xpm"
# define A_0 "./image/a1.xpm"
# define A_1 "./image/a2.xpm"
# define E_1 "./image/frame-1.xpm"
# define E_2 "./image/frame-2.xpm"
# define E_3 "./image/frame-3.xpm"
# define E_4 "./image/frame-4.xpm"
# define E_5 "./image/frame-5.xpm"
# define E_6 "./image/frame-6.xpm"
# define E_7 "./image/frame-7.xpm"
# define E_8 "./image/frame-8.xpm"
# define N 50
# include "mlx.h"
# include "libft/libft.h"

typedef struct s_player {
	int		x;
	int		y;
	void	*play[2];
	void	*d[2];
	void	*a[2];
	int		w;
	int		d_;
	int		a_;
	int		s_;
	int		count;
}t_player;
typedef struct s_data {
	void		*img;
	char		*addr;
	int			w;
	int			h;
	int			end;
	char		**line;
	void		*p_;
	void		*win;
	int			n;
	int			j;
	int			i;
	int			count;
	t_player	p;
	void		*s;
	int			c;
	int			pl;
	int			out;
}t_data;
int		_esc(t_data *line);
int		_input(int keycode, t_data *line);
void	img_put(t_data *line);
void	_w(t_data *line);
void	_d(t_data *line);
void	_a(t_data *line);
void	_s(t_data *line);
void	_walk_d(t_data *line);
void	_walk_s(t_data *line);
void	_walk_a(t_data *line);
void	_walk(t_data *line);
void	end_game(t_data *line);
void	_write(int count);
void	continue_error(t_data *l);
void	_error_two(t_data *l);
#endif
