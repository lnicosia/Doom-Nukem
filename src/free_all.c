/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:39:19 by lnicosia          #+#    #+#             */
/*   Updated: 2019/10/28 09:18:42 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		save_benchmark(t_env *env);

static void	free_textures(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_TEXTURE)
	{
		if (env->textures[i].surface)
			SDL_FreeSurface(env->textures[i].surface);
		i++;
	}
}

static void	free_sectors(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->nb_sectors)
	{
		if (env->sectors[i].vertices)
			ft_memdel((void**)&env->sectors[i].vertices);
		if (env->sectors[i].ceilings)
			ft_memdel((void**)&env->sectors[i].ceilings);
		if (env->sectors[i].floors)
			ft_memdel((void**)&env->sectors[i].floors);
		if (env->sectors[i].clipped_ceilings1)
			ft_memdel((void**)&env->sectors[i].clipped_ceilings1);
		if (env->sectors[i].clipped_floors1)
			ft_memdel((void**)&env->sectors[i].clipped_floors1);
		if (env->sectors[i].clipped_ceilings2)
			ft_memdel((void**)&env->sectors[i].clipped_ceilings2);
		if (env->sectors[i].clipped_floors2)
			ft_memdel((void**)&env->sectors[i].clipped_floors2);
		if (env->sectors[i].wall_width)
			ft_memdel((void**)&env->sectors[i].wall_width);
		if (env->sectors[i].textures)
			ft_memdel((void**)&env->sectors[i].textures);
		if (env->sectors[i].align)
			ft_memdel((void**)&env->sectors[i].align);
		if (env->sectors[i].scale)
			ft_memdel((void**)&env->sectors[i].scale);
		if (env->sectors[i].neighbors)
			ft_memdel((void**)&env->sectors[i].neighbors);
		if (env->sectors[i].sprites)
			ft_memdel((void**)&env->sectors[i].sprites);
		if (env->sectors[i].xmin)
			ft_memdel((void**)&env->sectors[i].xmin);
		if (env->sectors[i].xmax)
			ft_memdel((void**)&env->sectors[i].xmax);
		if (env->sectors[i].nb_sprites)
			ft_memdel((void**)&env->sectors[i].nb_sprites);
		i++;
	}
	ft_memdel((void**)&env->sectors);
}

void		free_camera(t_camera *camera)
{
	int	i;

	if (camera->screen_sectors)
		ft_memdel((void**)&camera->screen_sectors);
	if (camera->screen_pos)
		ft_memdel((void**)&camera->screen_pos);
	if (camera->rendered_sectors)
		ft_memdel((void**)&camera->rendered_sectors);
	if (camera->xmin)
		ft_memdel((void**)&camera->xmin);
	if (camera->xmax)
		ft_memdel((void**)&camera->xmax);
	if (camera->feet_y)
		ft_memdel((void**)&camera->feet_y);
	if (camera->head_y)
		ft_memdel((void**)&camera->head_y);
	if (camera->sector_computed)
		ft_memdel((void**)&camera->sector_computed);
	i = 0;
	if (camera->v)
	{
		while (i < camera->size)
		{
			if (camera->v[i])
				ft_memdel((void**)&camera->v[i]);
			i++;
		}
		ft_memdel((void**)&camera->v);
	}
}

void		free_all_sdl_relative(t_env *env)
{
	if (env->sdl.window)
		SDL_DestroyWindow(env->sdl.window);
	if (env->sdl.renderer)
		SDL_DestroyRenderer(env->sdl.renderer);
	if (env->sdl.texture)
		SDL_DestroyTexture(env->sdl.texture);
	if (env->sdl.texture_pixels)
		ft_memdel((void**)&env->sdl.texture_pixels);
	if (env->zbuffer)
		ft_memdel((void**)&env->zbuffer);
	if (env->max_ceiling)
		ft_memdel((void**)&env->max_ceiling);
	if (env->max_floor)
		ft_memdel((void**)&env->max_floor);
	if (env->current_ceiling)
		ft_memdel((void**)&env->current_ceiling);
	if (env->current_floor)
		ft_memdel((void**)&env->current_floor);
	if (env->z)
		ft_memdel((void**)&env->z);
	if (env->z_near_z)
		ft_memdel((void**)&env->z_near_z);
	if (env->alpha)
		ft_memdel((void**)&env->alpha);
	if (env->clipped_alpha)
		ft_memdel((void**)&env->clipped_alpha);
	if (env->line_height)
		ft_memdel((void**)&env->line_height);
	if (env->no_slope_current_ceiling)
		ft_memdel((void**)&env->no_slope_current_ceiling);
	if (env->no_slope_current_floor)
		ft_memdel((void**)&env->no_slope_current_floor);
	if (env->ceiling_start)
		ft_memdel((void**)&env->ceiling_start);
	if (env->floor_start)
		ft_memdel((void**)&env->floor_start);
	if (env->divider)
		ft_memdel((void**)&env->divider);
	if (env->neighbor_max_ceiling)
		ft_memdel((void**)&env->neighbor_max_ceiling);
	if (env->neighbor_max_floor)
		ft_memdel((void**)&env->neighbor_max_floor);
	if (env->neighbor_current_ceiling)
		ft_memdel((void**)&env->neighbor_current_ceiling);
	if (env->neighbor_current_floor)
		ft_memdel((void**)&env->neighbor_current_floor);
	if (env->texel)
		ft_memdel((void**)&env->texel);
	if (env->texel_near_z)
		ft_memdel((void**)&env->texel_near_z);
	if (env->camera_z)
		ft_memdel((void**)&env->camera_z);
	if (env->texel_camera_range)
		ft_memdel((void**)&env->texel_camera_range);
	if (env->zrange)
		ft_memdel((void**)&env->zrange);
	if (env->xmin)
		ft_memdel((void**)&env->xmin);
	if (env->xmax)
		ft_memdel((void**)&env->xmax);
	if (env->ymin)
		ft_memdel((void**)&env->ymin);
	if (env->ymax)
		ft_memdel((void**)&env->ymax);
	if (env->wall_texel)
		ft_memdel((void**)&env->wall_texel);
	if (env->vline_data)
		ft_memdel((void**)&env->vline_data);
}

void		free_all(t_env *env)
{
	int i;

	ft_printf("Freeing data..\n");
	if (!env)
		exit(0);
	free_all_sdl_relative(env);
	if (env->sdl.fonts.amazdoom70)
		TTF_CloseFont(env->sdl.fonts.amazdoom70);
	if (env->sdl.fonts.amazdoom50)
		TTF_CloseFont(env->sdl.fonts.amazdoom50);
	if (env->sdl.fonts.amazdoom20)
		TTF_CloseFont(env->sdl.fonts.amazdoom20);
	if (env->sdl.fonts.alice30)
		TTF_CloseFont(env->sdl.fonts.alice30);
	if (env->sdl.fonts.alice70)
		TTF_CloseFont(env->sdl.fonts.alice70);
	if (env->sdl.fonts.bebasneue)
		TTF_CloseFont(env->sdl.fonts.bebasneue);
	if (env->confirmation_box.str)
		ft_strdel(&env->confirmation_box.str);
	if (env->sectors)
		free_sectors(env);
	if (env->vertices)
		ft_memdel((void**)&env->vertices);
	if (env->objects)
		ft_memdel((void**)&env->objects);
	if (env->sprites)
		ft_memdel((void**)&env->sprites);
	if (env->sound.background)
		Mix_FreeMusic(env->sound.background);
	if (env->sound.footstep)
		Mix_FreeChunk(env->sound.footstep);
	if (env->sound.jump)
		Mix_FreeChunk(env->sound.jump);
	if (env->sector_list)
		ft_memdel((void**)&env->sector_list);
	if (env->res[0])
		ft_strdel(&env->res[0]);
	if (env->res[1])
		ft_strdel(&env->res[1]);
	if (env->res[2])
		ft_strdel(&env->res[2]);
	i = 0;
	while (i < NB_WEAPONS)
	{
		if (env->weapons[i].empty)
			Mix_FreeChunk(env->weapons[i].empty);
		if (env->weapons[i].sound)
			Mix_FreeChunk(env->weapons[i].sound);
		i++;
	}
	free_textures(env);
	free_camera(&env->player.camera);
	TTF_Quit();
	Mix_CloseAudio();
	SDL_Quit();
	ft_printf("Exiting..\n");
	save_benchmark(env);
}

int			crash(char *str, t_env *env)
{
	ft_dprintf(STDERR_FILENO, "%s", str);
	ft_printf("{red}[Critical error]{reset}\n");
	free_all(env);
	return (-1);
}
