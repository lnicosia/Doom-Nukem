/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:21:31 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/13 14:14:20 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	*raycasting(void *param)
{
	t_render	render;
	t_env		*env;
	int			x;
	int			xend;
	t_vline		vline;
	t_sector	sector;

	render = ((t_render_thread*)param)->render;
	env = ((t_render_thread*)param)->env;
	x = ((t_render_thread*)param)->xstart;
	xend = ((t_render_thread*)param)->xend;
	sector = env->sectors[render.sector];
	while (x <= xend)
	{
		render.currentx = x;
		render.alpha = (x - render.preclip_x1) / render.preclip_xrange;
		render.clipped_alpha = (x - render.x1) / render.xrange;
		render.z = 1.0 / ((1.0 - render.alpha) / render.vz1 + render.alpha / render.vz2);
		render.clipped_z = 1.0 / ((1.0 - render.clipped_alpha) / render.clipped_vz1 + render.clipped_alpha / render.clipped_vz2);
		// Lumiere
		//render.light = 255 - ft_fclamp(render.z * 2.00, 0.00, 255.00);

		render.texel.x = ((1.0 - render.alpha) * render.x1z1 + render.alpha * render.x2z2) * render.z;
		render.texel.y = ((1.0 - render.alpha) * render.y1z1 + render.alpha * render.y2z2) * render.z;
		// Calculer y actuel du plafond et du sol
		render.max_ceiling = render.clipped_alpha * render.ceil_range + render.ceiling1;
		//render.current_ceiling = ft_clamp(render.max_ceiling, 0, env->h - 1);
		render.current_ceiling = ft_clamp(render.max_ceiling, env->ymin[x], env->ymax[x]);
		render.max_floor = render.clipped_alpha * render.floor_range + render.floor1;
		//render.current_floor = ft_clamp(render.max_floor, 0, env->h - 1);
		render.current_floor = ft_clamp(render.max_floor, env->ymin[x], env->ymax[x]);
		render.no_slope_current_ceiling = render.clipped_alpha * render.no_slope_ceil_range + render.no_slope_ceiling1;
		render.no_slope_current_floor = render.clipped_alpha * render.no_slope_floor_range + render.no_slope_floor1;
		render.line_height = render.no_slope_current_floor - render.no_slope_current_ceiling;
		//render.floor_horizon = render.alpha * render.floor_horizon_range + render.floor_horizon1;
		render.ceiling_start = render.max_ceiling - render.ceiling_horizon;
		render.floor_start = render.max_floor - render.floor_horizon;
		/*render.ceiling_start = render.max_ceiling - render.horizon;
		render.floor_start = render.max_floor - render.horizon;*/
		vline.start = render.current_ceiling;
		vline.end = render.current_floor;
		vline.x = x;
		vline.color = 0xFF222222;
		vline.color = 0xFFFF0000;
		// Dessiner le plafond de ymin jusqu'au plafond
		if (render.current_ceiling > env->ymin[x])
			draw_ceiling(render, env);
		// Dessiner le sol du sol jusqu'a ymax
		if (render.current_floor < env->ymax[x])
			draw_floor(render, env);
		if (sector.neighbors[render.i] >= 0)
		{
			get_neighbor_ceil_floor(&render, env, x);
			// Dessiner corniche
			if (render.current_neighbor_ceiling > render.current_ceiling)
				draw_upper_wall(render, env);
			// Dessiner marche
			if (render.current_neighbor_floor < render.current_floor)
				draw_bottom_wall(render, env);
			env->ymin[x] = ft_clamp(
					ft_max(render.current_neighbor_ceiling, render.current_ceiling),
					env->ymin[x], env->ymax[x]);
			env->ymax[x] = ft_clamp(
					ft_min(render.current_neighbor_floor, render.current_floor),
					env->ymin[x], env->ymax[x]);
		}
		else
		{
			draw_vline(vline, render, env);
			if ((env->options.zbuffer || env->options.contouring)
					&& (x == (int)render.preclip_x1
						|| x == (int)render.preclip_x2))
			{
				//ft_printf("drawing line at %d from %d to %d\n", vline.x, vline.start, vline.end);
				draw_vline_color(vline, render, env);
			}
		}
		x++;
	}
	if (!env->options.wall_color && THREADS == 1)
	{
		//ft_printf("x1 = %d, x2 = %d\n", (int)render.xmin, (int)render.xmax);
		ft_printf("xstart = %d, xend = %d\n\n", ((t_render_thread*)param)->xstart, x - 1);
		if (!env->inputs.shift)
			update_screen(env);
		else
			update_screen_zbuffer(env);
		SDL_Delay(1000);
	}
	return (NULL);
}

void	threaded_raycasting(t_env *env, t_render render)
{
	//t_render_thread	original;
	t_render_thread	rt[THREADS];
	pthread_t		threads[THREADS];
	int				i;

	/*original.env = env;
	original.render = render;
	original.xstart = render.xstart;
	original.xend = render.xend;*/
	//raycasting(&original);
	i = 0;
	//ft_printf("\ndebut = %d fin = %d\n", render.xstart, render.xend);
	//ft_printf("raycasting.c line 100\n");
	while (i < THREADS)
	{
		rt[i].env = env;
		//ft_memcpy((void *)&rt[i].env, (void *)env, sizeof(t_env));
		//ft_memcpy((void *)&rt[i].render, (void*)&render , sizeof(t_render));
		rt[i].render = render;
		rt[i].xstart = render.xstart + (render.xend - render.xstart) / (double)THREADS * i;
		rt[i].xend = render.xstart + (render.xend - render.xstart) / (double)THREADS * (i + 1);
		//ft_printf("raycasting.c line 107\n");
		if (pthread_create(&threads[i], NULL, raycasting, &rt[i]) > 0)
			return ;
		//ft_printf("raycasting.c line 109\n");
		i++;
	}
	while (i-- > 0)
	{
		//ft_printf("raycasting.c line 114\n");
		//if (threads[i])
		//{
			//ft_printf("thread exist\n");
			pthread_join(threads[i], NULL);
		//}
		//else
			//ft_printf("error, thread doesn't exist\n");
		//ft_printf("raycasting.c line 116\n");
	}
	//ft_printf("raycasting.c line 118\n");
}
