#include "env.h"
#include "wall_sprite_remover.h"

int		delete_floor_bullet_hole(void *p, void *penv)
{
	t_env					*env;
	t_wall_sprite_remover	*param;

	env = (t_env*)penv;
	param = (t_wall_sprite_remover*)p;
	ft_printf("deleting sprite %d of sector %d floor\n",
	param->sprite, param->sector);
	env->sectors[param->sector].floor_sprites.sprite = ft_delindex(
	env->sectors[param->sector].floor_sprites.sprite, sizeof(short)
	* env->sectors[param->sector].nb_floor_sprites,
	sizeof(short),
	sizeof(short) * param->sprite);
	env->sectors[param->sector].floor_sprites.scale = ft_delindex(
	env->sectors[param->sector].floor_sprites.scale, sizeof(t_v2)
	* env->sectors[param->sector].nb_floor_sprites,
	sizeof(t_v2),
	sizeof(t_v2) * param->sprite);
	env->sectors[param->sector].floor_sprites.pos = ft_delindex(
	env->sectors[param->sector].floor_sprites.pos, sizeof(t_v2)
	* env->sectors[param->sector].nb_floor_sprites,
	sizeof(t_v2),
	sizeof(t_v2) * param->sprite);
	env->sectors[param->sector].nb_floor_sprites--;
	ft_memdel(&p);
	return (1);
}

int		delete_wall_bullet_hole(void *p, void *penv)
{
	t_env					*env;
	t_wall_sprite_remover	*param;
	int						i;

	env = (t_env*)penv;
	param = (t_wall_sprite_remover*)p;
	ft_printf("deleting sprite %d of wall %d of sector %d\n",
	param->sprite, param->wall, param->sector);
	env->sectors[param->sector].sprites[param->wall].sprite = ft_delindex(
	env->sectors[param->sector].sprites[param->wall].sprite, sizeof(short)
	* env->sectors[param->sector].nb_sprites[param->wall],
	sizeof(short),
	sizeof(short) * param->sprite);
	env->sectors[param->sector].sprites[param->wall].scale = ft_delindex(
	env->sectors[param->sector].sprites[param->wall].scale, sizeof(t_v2)
	* env->sectors[param->sector].nb_sprites[param->wall],
	sizeof(t_v2),
	sizeof(t_v2) * param->sprite);
	env->sectors[param->sector].sprites[param->wall].pos = ft_delindex(
	env->sectors[param->sector].sprites[param->wall].pos, sizeof(t_v2)
	* env->sectors[param->sector].nb_sprites[param->wall],
	sizeof(t_v2),
	sizeof(t_v2) * param->sprite);
	env->sectors[param->sector].nb_sprites[param->wall]--;
	if (set_camera_sprites_array(&env->player.camera, param->sector,
		param->wall, env))
		return (-1);
	ft_memdel(&p);
	return (1);
}
