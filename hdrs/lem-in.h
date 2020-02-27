/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem-in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:06:19 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/27 17:58:38 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct	s_room
{
	int				x_coord;
	int				y_coord;
	int				distance;
	int				link_count;
	int				*links;
	char			*name;
	struct s_room	*next;
}				t_room;

int		ft_is_int(char *str);
void	ft_strarrdel(char ***arr);
int		read_input(t_room ***graph, unsigned int *ant_no);
void	free_graph(t_room ***graph);
t_room	*create_room(char **room_info);

#endif