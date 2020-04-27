#include "env.h"

int		check_next_to_vertex(t_env *env, int i, int j)
{
	t_sector sector;

	sector = env->sectors[i];
	if (((j > 0 && sector.vertices[j] == env->editor.split.v1
	  	&& (sector.vertices[j - 1] == env->editor.split.v2
		|| sector.vertices[j + 1] == env->editor.split.v2)))
		|| (sector.vertices[j] == env->editor.split.v1 && j == 0
		&& (sector.vertices[sector.nb_vertices - 1] == env->editor.split.v2
		|| sector.vertices[j + 1] == env->editor.split.v2)))
		return (0);
	else if (((j > 0 && sector.vertices[j] == env->editor.split.v2
	  	&& (sector.vertices[j - 1] == env->editor.split.v1
		|| sector.vertices[j + 1] == env->editor.split.v1)))
		|| (sector.vertices[j] == env->editor.split.v2 && j == 0
		&& (sector.vertices[sector.nb_vertices - 1] == env->editor.split.v1
		|| sector.vertices[j + 1] == env->editor.split.v1)))
		return (0);
	return (1);
}

int		check_vertex_neighbors(t_env *env, int i, int j)
{
	if (!check_next_to_vertex(env, i, j))
		return (0);
	env->editor.split.sector = i;
	return (1);
}

int		check_sectors(t_env *env)
{
	int	i;
	int	j;
	int	first;

	first = 0;
	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if ((env->sectors[i].vertices[j] == env->editor.split.v1
			|| env->sectors[i].vertices[j] == env->editor.split.v2) && !first)
				first = 1;
			else if (first
				&& (env->sectors[i].vertices[j] == env->editor.split.v1
				|| env->sectors[i].vertices[j] == env->editor.split.v2))
			  	return (check_vertex_neighbors(env, i, j));
			j++;
		}
		first = 0;
		i++;
	}
	return (0);
}

int		check_pos_vertices(t_env *env)
{
	t_list	*tmp;

	tmp = env->editor.current_vertices;
	env->editor.split.v1 = ((t_vertex*)tmp->content)->num;
	tmp = env->editor.current_vertices->next;
	env->editor.split.v2 = ((t_vertex*)tmp->content)->num;
	if (check_sectors(env))
		return (1);
	return (0);
}
