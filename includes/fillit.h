/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbrochar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 12:00:51 by gbrochar          #+#    #+#             */
/*   Updated: 2016/10/05 11:58:04 by fanno            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "../libft/libft.h"

typedef struct	s_tetromino
{
	char		type;
	char		x;
	char		y;
}				t_tetromino;

int				ft_strstr_binary(const char *s1, char *s2);
void			ft_replace_linefeed(char **tiles);
char			**ft_create_types(void);
char			**ft_allocate_types(void);

t_tetromino		*ft_get_file(char *file_name);
t_tetromino		*ft_split_file_content(char *file_content, int tiles_nb);
t_tetromino		*ft_check_tiles(char **tiles);
t_tetromino		*ft_get_struct(char **tiles);

void			ft_solve(t_tetromino *tiles);
int				ft_solve_2(char grid[22][23], t_tetromino *tiles, int nb);
void			ft_print_grid(char grid[22][23]);

void			init(int (*f_check[19])(char[22][23], t_tetromino *, int));
void			ft_init_grid(char grid[22][23], t_tetromino *tiles);

int				ft_check_ir0(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_ir90(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_or0(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_tr0(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_tr90(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_tr180(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_tr270(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_sr0(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_sr90(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_zr0(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_zr90(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_lr0(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_lr90(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_lr180(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_lr270(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_jr0(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_jr90(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_jr180(char grid[22][23], t_tetromino *tiles, int nb);
int				ft_check_jr270(char grid[22][23], t_tetromino *tiles, int nb);

#endif
