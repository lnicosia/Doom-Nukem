#include "env.h"

void	revert_sector(t_sector *sector, t_env *env)
{
	int			i;
	int			index;
	int			j;
	int		*tmp;

	i = 1;
	j = 1;
	if (!(tmp = (int *)ft_memalloc(sizeof(int) * (sector->nb_vertices + 1))))
		return ;
	tmp[0] = sector->vertices[0];
	while (i < sector->nb_vertices)
	{
		if (env->editor.reverted)
			index = sector->nb_vertices - j;
		else
			index = j;
		tmp[i] = sector->vertices[index];
		i++;
		j++;
	}
	tmp[sector->nb_vertices] = tmp[0];
	free(sector->vertices);
	sector->vertices = tmp;
}

int		fill_sector_first_vertex(t_sector *sector, t_env *env)
{
	sector->portals[0] = 1;
    sector->vertices[0] = sector->vertices[sector->nb_vertices];
    sector->neighbors[0] = sector->neighbors[sector->nb_vertices];
    sector->textures[0] = sector->textures[sector->nb_vertices];
    sector->wall_sprites[0] = sector->wall_sprites[sector->nb_vertices];
    sector->align[0] = sector->align[sector->nb_vertices];
    sector->scale[0] = sector->scale[sector->nb_vertices];
    sector->wall_sprites[0].nb_sprites = 0;
	if (!(sector->walls_map_lvl[0] = (double*)ft_memalloc(sizeof(double)
		* env->wall_textures[sector->textures[0]].nb_maps)))
		return (ft_perror("Could not malloc sector walls map lvl"));
	if (set_sector_wall_map_array(sector,
		&env->wall_textures[sector->textures[0]], 0, env))
	  	return (-1);
	return (0);
}

int		fill_sector_last_vertex(t_sector *sector, t_env *env)
{
	sector->portals[sector->nb_vertices] = 1;
    sector->vertices[sector->nb_vertices] = sector->vertices[0];
    sector->neighbors[sector->nb_vertices] = sector->neighbors[0];
    sector->textures[sector->nb_vertices] = sector->textures[0];
    sector->wall_sprites[sector->nb_vertices] = sector->wall_sprites[0];
    sector->align[sector->nb_vertices] = sector->align[0];
    sector->scale[sector->nb_vertices] = sector->scale[0];
    sector->wall_sprites[sector->nb_vertices].nb_sprites = 0;
	if (!(sector->walls_map_lvl[sector->nb_vertices] =
	  	(double*)ft_memalloc(sizeof(double) * env->wall_textures[sector->
		textures[sector->nb_vertices]].nb_maps)))
		return (ft_perror("Could not malloc sector walls map lvl"));
	if (set_sector_wall_map_array(sector,
		&env->wall_textures[sector->textures[sector->nb_vertices]],
		sector->nb_vertices, env))
	  	return (-1);
	return (0);
}
