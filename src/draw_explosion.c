/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_explosion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:24:44 by gaerhard          #+#    #+#             */
/*   Updated: 2020/04/29 17:24:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void		draw_vline_explosion(t_render_explosion *erender,
t_sprite_drawer *drawer, t_env *env)
{
	drawer->xalpha = (drawer->x - erender->x1) / erender->xrange;
	if (drawer->sprite->reversed[erender->index])
		drawer->xalpha = 1.0 - drawer->xalpha;
	drawer->textx = (1.0 - drawer->xalpha)
	* drawer->sprite->start[erender->index].x + drawer->xalpha
	* drawer->sprite->end[erender->index].x;
	drawer->y = erender->ystart;
	while (++drawer->y < drawer->yend)
	{
		drawer->yalpha = (drawer->y - erender->y1) / erender->yrange;
		drawer->texty = (1.0 - drawer->yalpha)
		* drawer->sprite->start[erender->index].y + drawer->yalpha
		* drawer->sprite->end[erender->index].y;
		if ((drawer->texture->str[drawer->textx + drawer->texty
			* drawer->texture->surface->w] != 0xFFC10099))
		{
			env->sdl.texture_pixels[drawer->x + drawer->y * env->w] =
			drawer->texture->str[drawer->textx + drawer->texty
			* drawer->texture->surface->w];
			env->zbuffer[drawer->x + drawer->y * env->w] =
			drawer->explosion->rotated_pos.z;
		}
	}
}

static void	*explosion_loop(void *param)
{
	t_env				*env;
	t_render_explosion	*erender;
	t_sprite_drawer		drawer;

	erender = ((t_explosion_thread*)param)->erender;
	env = ((t_explosion_thread*)param)->env;
	drawer.explosion = ((t_explosion_thread*)param)->explosion;
	drawer.sprite = &env->object_sprites[drawer.explosion->sprite];
	drawer.texture = &env->sprite_textures[drawer.sprite->texture];
	drawer.x = ((t_explosion_thread*)param)->xstart;
	drawer.xend = ((t_explosion_thread*)param)->xend;
	drawer.yend = erender->yend;
	while (++drawer.x <= drawer.xend)
	{
		draw_vline_explosion(erender, &drawer, env);
	}
	return (NULL);
}

static int	threaded_explosion(t_explosion *explosion,
t_render_explosion *erender, t_env *env)
{
	t_explosion_thread	pt[env->nprocs];
	pthread_t			threads[env->nprocs];
	int					i;

	i = 0;
	while (i < env->nprocs)
	{
		pt[i].env = env;
		pt[i].explosion = explosion;
		pt[i].erender = erender;
		pt[i].xstart = erender->xstart + (erender->xend - erender->xstart)
		/ (double)env->nprocs * i;
		pt[i].xend = erender->xstart + (erender->xend - erender->xstart)
		/ (double)env->nprocs * (i + 1);
		if (pthread_create(&threads[i], NULL, explosion_loop, &pt[i]))
			return (-1);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			return (-1);
	return (0);
}

void		init_explosion_render(t_render_explosion *erender,
t_explosion *explosion, t_env *env)
{
	int		centre_alignment;

	if (explosion->centered_sprite)
	{
		centre_alignment = (erender->y2 - erender->y1) / 2;
		erender->y1 += centre_alignment;
		erender->y2 += centre_alignment;
	}
	erender->xstart = ft_clamp(erender->x1, 0, env->w - 1);
	erender->ystart = ft_clamp(erender->y1 + 1, 0, env->h - 1);
	erender->xend = ft_clamp(erender->x2, 0, env->w - 1);
	erender->yend = ft_clamp(erender->y2, 0, env->h - 1);
	explosion->left = erender->xstart;
	explosion->right = erender->xend;
	explosion->top = erender->ystart;
	explosion->bottom = erender->yend;
	erender->xrange = erender->x2 - erender->x1;
	erender->yrange = erender->y2 - erender->y1;
}

int			draw_explosion(t_camera *camera, t_explosion *explosion,
t_env *env, int index)
{
	t_render_explosion	erender;
	t_sprite			*sprite;
	t_v2				size;
	double				sprite_ratio;

	sprite = &env->object_sprites[explosion->sprite];
	erender.camera = camera;
	project_explosion(&erender, explosion, env);
	erender.index = index;
	size.x = env->w * explosion->scale / explosion->rotated_pos.z;
	sprite_ratio = sprite->size[erender.index].x
		/ (double)sprite->size[erender.index].y;
	size.y = size.x * sprite_ratio;
	erender.x1 = erender.screen_pos.x - size.y / 4;
	erender.x2 = erender.screen_pos.x + size.y / 4;
	erender.y1 = erender.screen_pos.y - size.x / 2;
	erender.y2 = erender.screen_pos.y;
	init_explosion_render(&erender, explosion, env);
	if (threaded_explosion(explosion, &erender, env))
		return (-1);
	return (0);
}
