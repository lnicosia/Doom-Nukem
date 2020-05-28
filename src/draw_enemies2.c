/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_enemies2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 16:13:34 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 16:13:34 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "enemies.h"

void	*enemy_loop(void *param)
{
	t_env			*env;
	t_render_object	*orender;
	t_sprite_drawer	drawer;

	orender = ((t_enemy_thread*)param)->orender;
	env = ((t_enemy_thread*)param)->env;
	drawer.enemy = ((t_enemy_thread*)param)->enemy;
	drawer.sprite = &env->enemy_sprites[drawer.enemy->sprite];
	drawer.texture = &env->sprite_textures[drawer.sprite->texture];
	drawer.x = ((t_enemy_thread*)param)->xstart;
	drawer.xend = ((t_enemy_thread*)param)->xend;
	drawer.yend = orender->yend;
	drawer.sector = &env->sectors[drawer.enemy->sector];
	while (++drawer.x <= drawer.xend)
	{
		get_sprite_x(orender, &drawer);
		while (drawer.y < drawer.yend)
		{
			draw_vline_enemy(orender, &drawer, env);
			drawer.y++;
		}
	}
	return (NULL);
}

void	init_enemy_render(t_render_object *orender, t_enemy *enemy,
t_v2 size, t_env *env)
{
	orender->x1 = orender->screen_pos.x - size.y / 4;
	orender->x2 = orender->screen_pos.x + size.y / 4;
	orender->y1 = orender->screen_pos.y - size.x / 2;
	orender->y2 = orender->screen_pos.y;
	orender->light_color = enemy->light_color;
	orender->brightness = enemy->brightness;
	orender->intensity = enemy->intensity;
	orender->xstart = ft_clamp(orender->x1, 0, env->w - 1);
	orender->ystart = ft_clamp(orender->y1 + 1, 0, env->h - 1);
	orender->xend = ft_clamp(orender->x2, 0, env->w - 1);
	orender->yend = ft_clamp(orender->y2, 0, env->h - 1);
	enemy->left = orender->xstart;
	enemy->right = orender->xend;
	enemy->top = orender->ystart;
	enemy->bottom = orender->yend;
	orender->xrange = orender->x2 - orender->x1;
	orender->yrange = orender->y2 - orender->y1;
}

int		threaded_enemy_loop(t_enemy *enemy, t_render_object *orender,
t_env *env)
{
	t_enemy_thread	et[env->nprocs];
	pthread_t		threads[env->nprocs];
	int				i;

	i = 0;
	while (i < env->nprocs)
	{
		et[i].env = env;
		et[i].enemy = enemy;
		et[i].orender = orender;
		et[i].xstart = orender->xstart + (orender->xend - orender->xstart)
		/ (double)env->nprocs * i;
		et[i].xend = orender->xstart + (orender->xend - orender->xstart)
		/ (double)env->nprocs * (i + 1);
		if (pthread_create(&threads[i], NULL, enemy_loop, &et[i]))
			return (-1);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			return (-1);
	return (0);
}

int		draw_enemy(t_camera *camera, t_enemy *enemy, t_env *env,
int death_sprite)
{
	t_render_object	orender;
	t_sprite		*sprite;
	t_v2			size;
	double			sprite_ratio;

	if (death_sprite >= 0)
		enemy->sprite = env->enemy_sprites[enemy->sprite].death_counterpart;
	orender.camera = camera;
	sprite = &env->enemy_sprites[enemy->sprite];
	project_enemy(&orender, enemy, env);
	if (sprite->oriented)
		orender.index = get_enemy_direction(enemy);
	else if (death_sprite >= 0)
		orender.index = death_sprite;
	else
		orender.index = 0;
	size.x = env->w * enemy->scale / enemy->rotated_pos.z;
	sprite_ratio = sprite->size[orender.index].x
	/ (double)sprite->size[orender.index].y;
	size.y = size.x * sprite_ratio;
	init_enemy_render(&orender, enemy, size, env);
	if (threaded_enemy_loop(enemy, &orender, env))
		return (-1);
	return (0);
}
