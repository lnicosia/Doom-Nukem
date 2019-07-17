/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:21:31 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/17 16:14:48 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
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
		render.clipped_z = 1.0 / ((1.0 - render.clipped_alpha) / render.clipped_vz1 + render.clipped_alpha / render.vz2);
		// Lumiere
		render.light = 255 - ft_fclamp(render.z * 2.00, 0.00, 255.00);

		render.texel.x = ((1.0 - render.alpha) * render.x1z1 + render.alpha * render.x2z2) * render.z;
		render.texel.y = ((1.0 - render.alpha) * render.y1z1 + render.alpha * render.y2z2) * render.z;
		// Calculer y actuel du plafond et du sol
		render.max_ceiling = render.clipped_alpha * render.ceil_range + render.ceiling1;
		//render.current_ceiling = ft_clamp(render.max_ceiling, render.ymin, render.ymax);
		render.current_ceiling = ft_clamp(render.max_ceiling, env->ymin[x], env->ymax[x]);
		render.max_floor = render.clipped_alpha * render.floor_range + render.floor1;
		render.line_height = render.max_floor - render.max_ceiling;
		//render.current_floor = ft_clamp(render.max_floor, render.ymin, render.ymax);
		render.current_floor = ft_clamp(render.max_floor, env->ymin[x], env->ymax[x]);
		render.ceiling_horizon = render.max_ceiling - render.horizon;
		render.floor_horizon = render.max_floor - render.horizon;
		vline.start = render.current_ceiling;
		vline.end = render.current_floor;
		vline.x = x;
		// Dessiner le plafond de ymin jusqu'au plafond
		if (render.current_ceiling > 0)
			draw_ceiling(render, env);
		// Dessiner le sol du sol jusqu'a ymax
		if (render.current_floor < env->h)
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
					env->ymin[x],
					env->ymax[x]);
			env->ymax[x] = ft_clamp(
					ft_min(render.current_neighbor_floor, render.current_floor),
					env->ymin[x],
					env->ymax[x]);
		}
		else
			draw_vline(vline, render, env);
		x++;
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
	while (i < THREADS)
	{
		rt[i].env = env;
		rt[i].render = render;
		rt[i].xstart = render.xstart + (render.xend - render.xstart) / (double)THREADS * i;
		rt[i].xend = render.xstart + (render.xend - render.xstart) / (double)THREADS * (i + 1);
		pthread_create(&threads[i], NULL, raycasting, &rt[i]);
		i++;
	}
	while (i-- > 0)
		pthread_join(threads[i], NULL);
}
