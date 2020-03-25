#include "add_vertex.h"

int		realloc_sector_arrays3(t_env *env, int sector, int j)
{
	if (modify_t_wall_sprites_tab_in_sector(env, j, sector,
		  &env->sectors[sector].wall_sprites))
		return (-1);
	if (modify_t_list_tab_in_sector(env, j, sector,
		&env->sectors[sector].wall_bullet_holes))
		return (-1);
	return (0);
}

int		realloc_sector_arrays2(t_env *env, int sector, int j)
{
	if (modify_double_tab_in_sector(env, j, sector,
		&env->sectors[sector].clipped_floors1))
		return (-1);
	if (modify_double_tab_in_sector(env, j, sector,
		&env->sectors[sector].clipped_ceilings1))
		return (-1);
	if (modify_double_tab_in_sector(env, j, sector,
		&env->sectors[sector].clipped_ceilings2))
		return (-1);
	if (modify_double_tab_in_sector(env, j, sector,
		&env->sectors[sector].clipped_floors2))
		return (-1);
	if (modify_double_tab_in_sector(env, j, sector,
		&env->sectors[sector].wall_width))
		return (-1);
	if (modify_t_v2_tab_in_sector(env, j, sector,
		&env->sectors[sector].scale))
		return (-1);
	if (modify_t_v2_tab_in_sector(env, j, sector,
		&env->sectors[sector].align))
		return (-1);
	if (modify_walls_map_lvl(env, sector))
		return (-1);
	return (realloc_sector_arrays3(env, sector, j));
}

int		realloc_sector_arrays(t_env *env, int sector, int j)
{
	if ((env->editor.add.v1 == env->sectors[sector].vertices[0]
	&& env->editor.add.v2 == env->sectors[sector].
	vertices[env->sectors[sector].nb_vertices - 1])
	|| (env->editor.add.v2 == env->sectors[sector].vertices[0]
	&& env->editor.add.v1 == env->sectors[sector].
	vertices[env->sectors[sector].nb_vertices - 1]))
		j = env->sectors[sector].nb_vertices - 1;
	if (modify_vertices_in_sector(env, j, sector))
		return (-1);
	if (modify_textures(env, j, sector))
		return (-1);
	if (modify_neighbors(env, j, sector))
		return (-1);
	if (modify_int_tab_in_sector(env, j, sector, &env->sectors[sector].portals))
		return (-1);
	if (modify_int_tab_in_sector(env, j, sector,
		&env->sectors[sector].selected))
		return (-1);
	if (modify_double_tab_in_sector(env, j, sector,
		&env->sectors[sector].floors))
		return (-1);
	if (modify_double_tab_in_sector(env, j, sector,
		&env->sectors[sector].ceilings))
		return (-1);
	return (realloc_sector_arrays2(env, sector, j));
}
