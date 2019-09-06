/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threaded_skybox.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 21:21:31 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/06 16:50:44 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "render.h"

void	*skybox_thread(void *param)
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
		//render.light = 255 - ft_fclamp(render.z * 2.00, 0.00, 255.00);

		render.texel.x = ((1.0 - render.alpha) * render.x1z1 + render.alpha * render.x2z2) * render.z;
		render.texel.y = ((1.0 - render.alpha) * render.y1z1 + render.alpha * render.y2z2) * render.z;
		// Calculer y actuel du plafond et du sol
		render.max_ceiling = render.clipped_alpha * render.ceil_range + render.ceiling1;
		//render.current_ceiling = ft_clamp(render.max_ceiling, 0, env->h - 1);
		//ft_printf("x = %d\n", x);
		//ft_printf("ymin[x] = %d ymax[x] = %d\n", env->ymin[x], env->ymax[x]);
		render.current_ceiling = ft_clamp(render.max_ceiling, env->ymin[x], env->ymax[x]);
		render.max_floor = render.clipped_alpha * render.floor_range + render.floor1;
		render.line_height = render.max_floor - render.max_ceiling;
		//render.current_floor = ft_clamp(render.max_floor, 0, env->h - 1);
		render.current_floor = ft_clamp(render.max_floor, env->ymin[x], env->ymax[x]);
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
		//ft_printf("max floor = %f\n", render.max_floor);
		//ft_printf("current floor = %f\n", render.current_floor);
		//ft_printf("x = %d start = %f end = %f\n", x, render.current_ceiling, render.current_floor);
		// Dessiner le plafond de ymin jusqu'au plafond
		//ft_printf("cc\n");
		if (render.current_ceiling > 0)
			draw_ceiling(render, env);
		// Dessiner le sol du sol jusqu'a ymax
		if (render.current_floor < env->h)
			draw_floor(render, env);
		draw_vline(vline, render, env);
		if ((env->options.zbuffer || env->options.contouring)
				&& (x == (int)render.preclip_x1
					|| x == (int)render.preclip_x2))
		{
			//ft_printf("drawing line at %d from %d to %d\n", vline.x, vline.start, vline.end);
			draw_vline_color(vline, render, env);
		}
		//ft_printf("cc2\n");
		x++;
	}
	/*if (!env->options.wall_color && THREADS == 1)
	{
		//ft_printf("x1 = %d, x2 = %d\n", (int)render.xmin, (int)render.xmax);
		ft_printf("xstart = %d, xend = %d\n\n", ((t_render_thread*)param)->xstart, x - 1);
		if (!env->inputs.shift)
			update_screen(env);
		else
			update_screen_zbuffer(env);
		SDL_Delay(1000);
	}*/
	return (NULL);
}

void	threaded_skybox(t_env *env, t_render render)
{
	//t_render_thread	original;
	t_render_thread	rt[1];
	pthread_t		threads[1];
	int				i;

	/*original.env = env;
	original.render = render;
	original.xstart = render.xstart;
	original.xend = render.xend;*/
	//raycasting(&original);
	i = 0;
	//ft_printf("raycasting.c line 100\n");
	while (i < 1)
	{
		rt[i].env = env;
		//ft_memcpy((void *)&rt[i].env, (void *)env, sizeof(t_env));
		//ft_memcpy((void *)&rt[i].render, (void*)&render , sizeof(t_render));
		rt[i].render = render;
		rt[i].xstart = render.xstart + (render.xend - render.xstart) / (double)1* i;
		rt[i].xend = render.xstart + (render.xend - render.xstart) / (double)1 * (i + 1);
		//ft_printf("raycasting.c line 107\n");
		if (pthread_create(&threads[i], NULL, skybox_thread, &rt[i]) > 0)
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
