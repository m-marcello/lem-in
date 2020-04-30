/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   graph_del.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:46:04 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/04/30 15:22:59 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

void	vert_del(t_vert **vert)
{
	if (vert == NULL || *vert == NULL)
		return ;
	ft_strdel(&((*vert)->name));
	ft_bzero((*vert), sizeof(t_vert));
	free((*vert));
	(*vert) = NULL;
}

void	edge_del(t_edge **edge)
{
	if (edge == NULL || *edge == NULL)
		return ;
	ft_bzero((*edge)->invert, sizeof(t_edge));
	if ((*edge)->invert != NULL)
		free(((*edge)->invert));
	ft_bzero((*edge), sizeof(t_edge));
	free((*edge));
	(*edge) = NULL;
}

void	path_del(t_graph *graph)
{
	unsigned int	i;

	i = 0;
	while (i < graph->path_count && graph->paths[i])
	{
		ft_bzero(graph->paths[i], sizeof(t_path));
		ft_memdel((void**)&(graph->paths[i]));
		i++;
	}
	ft_memdel((void**)&(graph->paths));
}

void	graph_del(t_graph *graph)
{
	t_edge	**walk_edge;
	t_edge	*del_edge;
	t_vert	**walk_vert;
	t_vert	*del_vert;

	walk_edge = &(graph->edge_list);
	if (graph->paths != NULL)
		path_del(graph);
	while ((*walk_edge) != NULL)
	{
		del_edge = (*walk_edge);
		(*walk_edge) = (*walk_edge)->next_edge;
		edge_del(&del_edge);
	}
	walk_vert = &(graph->vert_list);
	while ((*walk_vert) != NULL)
	{
		del_vert = (*walk_vert);
		(*walk_vert) = (*walk_vert)->next_vert;
		hmap_del_slot(graph->vertices, del_vert->name);
		vert_del(&del_vert);
	}
	hmap_del_map(&(graph->vertices));
	ft_bzero(graph, sizeof(t_graph));
}
