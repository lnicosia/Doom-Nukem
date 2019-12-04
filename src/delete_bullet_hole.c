#include "env.h"
#include "wall_sprite_remover.h"

int		delete_ceiling_bullet_hole(void *p, void *penv)
{
	t_env					*env;
	t_floor_sprite_remover	*param;

	env = (t_env*)penv;
	param = (t_floor_sprite_remover*)p;
	env->sectors[param->sector].ceiling_sprites.sprite = ft_delindex(
	env->sectors[param->sector].ceiling_sprites.sprite, sizeof(short)
	* env->sectors[param->sector].ceiling_sprites.nb_sprites,
	sizeof(short),
	sizeof(short) * param->sprite);
	env->sectors[param->sector].ceiling_sprites.scale = ft_delindex(
	env->sectors[param->sector].ceiling_sprites.scale, sizeof(t_v2)
	* env->sectors[param->sector].ceiling_sprites.nb_sprites,
	sizeof(t_v2),
	sizeof(t_v2) * param->sprite);
	env->sectors[param->sector].ceiling_sprites.pos = ft_delindex(
	env->sectors[param->sector].ceiling_sprites.pos, sizeof(t_v2)
	* env->sectors[param->sector].ceiling_sprites.nb_sprites,
	sizeof(t_v2),
	sizeof(t_v2) * param->sprite);
	env->sectors[param->sector].ceiling_sprites.nb_sprites--;
	shift_ceiling_bullet_hole_events(param->sector, param->sprite, env);
	ft_memdel(&p);
	return (1);
}

int		delete_floor_bullet_hole(void *p, void *penv)
{
	t_env					*env;
	t_floor_sprite_remover	*param;

	env = (t_env*)penv;
	param = (t_floor_sprite_remover*)p;
	env->sectors[param->sector].floor_sprites.sprite = ft_delindex(
	env->sectors[param->sector].floor_sprites.sprite, sizeof(short)
	* env->sectors[param->sector].floor_sprites.nb_sprites,
	sizeof(short),
	sizeof(short) * param->sprite);
	env->sectors[param->sector].floor_sprites.scale = ft_delindex(
	env->sectors[param->sector].floor_sprites.scale, sizeof(t_v2)
	* env->sectors[param->sector].floor_sprites.nb_sprites,
	sizeof(t_v2),
	sizeof(t_v2) * param->sprite);
	env->sectors[param->sector].floor_sprites.pos = ft_delindex(
	env->sectors[param->sector].floor_sprites.pos, sizeof(t_v2)
	* env->sectors[param->sector].floor_sprites.nb_sprites,
	sizeof(t_v2),
	sizeof(t_v2) * param->sprite);
	env->sectors[param->sector].floor_sprites.nb_sprites--;
	shift_floor_bullet_hole_events(param->sector, param->sprite, env);
	ft_memdel(&p);
	return (1);
}

int		delete_wall_bullet_hole(void *p, void *penv)
{
	t_env					*env;
	t_wall_sprite_remover	*param;

	env = (t_env*)penv;
	param = (t_wall_sprite_remover*)p;
	env->sectors[param->sector].wall_sprites[param->wall].sprite = ft_delindex(
	env->sectors[param->sector].wall_sprites[param->wall].sprite, sizeof(short)
	* env->sectors[param->sector].wall_sprites[param->wall].nb_sprites,
	sizeof(short),
	sizeof(short) * param->sprite);
	env->sectors[param->sector].wall_sprites[param->wall].scale = ft_delindex(
	env->sectors[param->sector].wall_sprites[param->wall].scale, sizeof(t_v2)
	* env->sectors[param->sector].wall_sprites[param->wall].nb_sprites,
	sizeof(t_v2),
	sizeof(t_v2) * param->sprite);
	env->sectors[param->sector].wall_sprites[param->wall].pos = ft_delindex(
	env->sectors[param->sector].wall_sprites[param->wall].pos, sizeof(t_v2)
	* env->sectors[param->sector].wall_sprites[param->wall].nb_sprites,
	sizeof(t_v2),
	sizeof(t_v2) * param->sprite);
	env->sectors[param->sector].wall_sprites[param->wall].nb_sprites--;
	if (set_camera_sprites_array(&env->player.camera, param->sector,
		param->wall, env))
		return (-1);
	shift_wall_bullet_hole_events(param->sector, param->wall, param->sprite,
	env);
	ft_memdel(&p);
	return (1);
}
