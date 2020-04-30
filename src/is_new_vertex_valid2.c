#include "env.h"

int			get_vertex_in_sector(t_env *env, int sector)
{
	int	i;
	int	ret;

	i = 0;
	while (i < env->sectors[sector].nb_vertices)
	{
		if (env->sectors[sector].vertices[i] == env->editor.selected_vertex)
			break ;
		i++;
	}
	ret = env->sectors[sector].vertices[i];
	return (ret);
}

t_vertex	find_second_vertex(t_env *env, t_sector sector, int new_index,
int index)
{
	int			i;
	t_vertex	res;

	i = 0;
	while (i < sector.nb_vertices)
	{
		if (sector.vertices[i] == index)
			break ;
		else
			i++;
	}
	if (i == 0)
		res = env->vertices[sector.vertices[sector.nb_vertices - 1]];
	else
		res = env->vertices[sector.vertices[i + new_index]];
	return (res);
}

int			check_all_angles(t_v2 *p, int res, int i, int straight)
{
	if (((p[i + 1].x - p[i].x) * (p[i + 2].y - p[i + 1].y)
			- ((p[i + 1].y - p[i].y) * (p[i + 2].x - p[i + 1].x))) > 0)
	{
		if (!res)
			res += straight;
		res++;
	}
	else if (((p[i + 1].x - p[i].x) * (p[i + 2].y - p[i + 1].y)
	- ((p[i + 1].y - p[i].y) * (p[i + 2].x - p[i + 1].x))) < 0)
	{
		if (!res)
			res -= straight;
		res--;
	}
	else if (((p[i + 1].x - p[i].x) * (p[i + 2].y - p[i + 1].y)
	- ((p[i + 1].y - p[i].y) * (p[i + 2].x - p[i + 1].x))) == 0 && res)
		res += res > 0 ? 1 : -1;
	return (res);
}
