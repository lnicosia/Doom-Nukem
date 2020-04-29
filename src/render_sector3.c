#include "render.h"

void	render_current_wall_vline(t_sector *sector, t_render *render,
t_env *env)
{
  	compute_vline_data(sector, render, env);
	if (render->current_ceiling > env->ymin[render->x]
		|| render->current_floor < env->ymax[render->x])
	  	precompute_texels(render);
	if (draw_wall_sprites(sector, render, env))
		return ;
	draw_wall_bullet_holes(sector, render, env);
	draw_floor_and_ceiling(sector, render, env);
	if (sector->neighbors[render->i] != -1)
	  	draw_bottom_and_upper_walls(sector, render, env);
	else
	{
		if (sector->textures[render->i] < 0)
			draw_skybox(render, WALL, env);
		else
		draw_wall(sector, render, env);
	}
}

void	*wall_loop(void *param)
{
	t_sector		*sector;
	t_render		render;
	t_env			*env;
	int				x;
	int				xend;

	sector = ((t_render_thread*)param)->sector;
	render = ((t_render_thread*)param)->render;
	env = ((t_render_thread*)param)->env;
	x = ((t_render_thread*)param)->xstart;
	xend = ((t_render_thread*)param)->xend;
	while (x <= xend)
	{
		render.x = x;
		render_current_wall_vline(sector, &render, env);
		x++;
	}
	return (NULL);
}

int		threaded_wall_loop(t_sector *sector, t_render *render, t_env *env)
{
	t_render_thread	rt[THREADS];
	pthread_t		threads[THREADS];
	int				i;

	i = 0;
	while (i < THREADS)
	{
		render->thread = i;
		rt[i].sector = sector;
		rt[i].render = *render;
		rt[i].env = env;
		rt[i].xstart = render->xstart + (render->xend - render->xstart)
			/ (double)THREADS * i;
		rt[i].xend = render->xstart + (render->xend - render->xstart)
			/ (double)THREADS * (i + 1);
		if (pthread_create(&threads[i], NULL, wall_loop, &rt[i]))
			return (-1);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			return (-1);
	return (0);
}

int		colorize_selected_portal(t_sector *sector, t_render *render, t_env *env)
{
	t_render_thread	rt[THREADS];
	pthread_t		threads[THREADS];
	int				i;

	i = 0;
	while (i < THREADS)
	{
		render->thread = i;
		rt[i].sector = sector;
		rt[i].render = *render;
		rt[i].env = env;
		rt[i].xstart = render->xstart + (render->xend - render->xstart)
			/ (double)THREADS * i;
		rt[i].xend = render->xstart + (render->xend - render->xstart)
			/ (double)THREADS * (i + 1) - 1;
		if (pthread_create(&threads[i], NULL, portal_loop, &rt[i]))
			return (-1);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			return (-1);
	return (0);
}

int		select_portal(t_sector *sector, t_render *render, t_env *env)
{
	t_render_thread	rt[THREADS];
	pthread_t		threads[THREADS];
	int				i;

	i = 0;
	while (i < THREADS)
	{
		render->thread = i;
		rt[i].sector = sector;
		rt[i].render = *render;
		rt[i].env = env;
		rt[i].xstart = render->xstart + (render->xend - render->xstart)
			/ (double)THREADS * i;
		rt[i].xend = render->xstart + (render->xend - render->xstart)
			/ (double)THREADS * (i + 1);
		if (pthread_create(&threads[i], NULL, select_portal_loop, &rt[i]))
			return (-1);
		i++;
	}
	while (i-- > 0)
		if (pthread_join(threads[i], NULL))
			return (-1);
	return (0);
}