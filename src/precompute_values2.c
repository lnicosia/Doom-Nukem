#include "render.h"

void	precompute_clipped_bullet_holes(int i, t_camera *camera,
		t_sector *sector, t_env *env)
{
	t_list			*wall_bullet_holes;
	t_bullet_hole	*curr;

	wall_bullet_holes = sector->wall_bullet_holes[i];
	while (wall_bullet_holes)
	{
	  	curr = (t_bullet_hole*)wall_bullet_holes->content;
		curr->scale.x =
			env->object_sprites[BULLET_HOLE].size[0].x
			/ curr->map_scale.x * sector->wall_width[i]
			/ camera->v[sector->num][i].clipped_vz2;
		wall_bullet_holes = wall_bullet_holes->next;
	}
}

void	precompute_clipped_vertex(int i, t_camera *camera, t_sector *sector,
		t_env *env)
{
	size_t	k;
	int		j;

	k = 0;
	while (k < env->wall_textures[sector->textures[i]].nb_maps)
	{
		camera->v[sector->num][i].texture_scale[k].x =
		((env->wall_textures[sector->textures[i]].maps[k]->w /
		sector->scale[i].x) * sector->wall_width[i] /
		camera->v[sector->num][i].clipped_vz2);
		k++;
	}
	j = 0;
	while (j < sector->wall_sprites[i].nb_sprites)
	{
		if (sector->wall_sprites[i].sprite[j] != -1)
			camera->v[sector->num][i].sprite_scale[j].x = 
	(env->object_sprites[sector->wall_sprites[i].sprite[j]].size[0].x
	/ sector->wall_sprites[i].scale[j].x) * sector->wall_width[i]
			/ camera->v[sector->num][i].clipped_vz2;
		j++;
	}
}

void	precompute_visible_bullet_holes(int i, t_camera *camera,
		t_sector *sector, t_env *env)
{
	t_list			*wall_bullet_holes;
	t_bullet_hole	*curr;

	wall_bullet_holes = sector->wall_bullet_holes[i];
	while (wall_bullet_holes)
	{
	  	curr = (t_bullet_hole*)wall_bullet_holes->content;
		curr->scale.x =
			env->object_sprites[BULLET_HOLE].size[0].x
			/ curr->map_scale.x * sector->wall_width[i]
			/ camera->v[sector->num][i + 1].vz;
		wall_bullet_holes = wall_bullet_holes->next;
	}
}

void	precompute_visible_vertex(int i, t_camera *camera, t_sector *sector,
		t_env *env)
{
	size_t	k;
	int		j;

	k = 0;
	while (k < env->wall_textures[sector->textures[i]].nb_maps)
	{
		camera->v[sector->num][i].texture_scale[k].x =
		((env->wall_textures[sector->textures[i]].maps[k]->w /
		sector->scale[i].x) * sector->wall_width[i] /
		camera->v[sector->num][i + 1].vz);
		k++;
	}
	j = 0;
	while (j < sector->wall_sprites[i].nb_sprites)
	{
		if (sector->wall_sprites[i].sprite[j] != -1)
			camera->v[sector->num][i].sprite_scale[j].x =
			(env->object_sprites[sector->wall_sprites[i].sprite[j]].
			size[0].x / sector->wall_sprites[i].scale[j].x)
			* sector->wall_width[i] / camera->v[sector->num][i + 1].vz;
		j++;
	}
	precompute_visible_bullet_holes(i, camera, sector, env);
}
