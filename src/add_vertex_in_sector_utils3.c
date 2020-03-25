#include "env.h"

int		modify_neighbors(t_env *env, int index, int sector)
{
	int	i;

	if (!(env->sectors[sector].neighbors =
	  	(int *)ft_realloc(env->sectors[sector].neighbors,
		sizeof(int) * env->sectors[sector].nb_vertices,
		sizeof(int) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc neighbors"));
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		env->sectors[sector].neighbors[i] =
		env->sectors[sector].neighbors[i - 1];
		i--;
	}
	env->sectors[sector].neighbors[i] = env->sectors[sector].neighbors[i - 1];
	return (0);
}

int		modify_walls_map_lvl(t_env *env, int sector)
{
	int	j;
		
	j = 0;
	while (j < env->sectors[sector].nb_vertices - 1)
	{
		if (env->sectors[sector].walls_map_lvl[j])
			ft_memdel((void**)&env->sectors[sector].walls_map_lvl[j]);
		j++;
	}
	ft_memdel((void**)&env->sectors[sector].walls_map_lvl);
	j = 0;
	if (!(env->sectors[sector].walls_map_lvl =
	  	(double **)ft_realloc(env->sectors[sector].walls_map_lvl,
		sizeof(double*) * env->sectors[sector].nb_vertices,
		sizeof(double*) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc walls_map_lvl"));
	while(j < env->sectors[sector].nb_vertices)
	{
		set_sector_wall_map_array(&env->sectors[sector],
		env->wall_textures[env->sectors[sector].textures[j]], j, env);
		j++;
	}
	return (0);
}
