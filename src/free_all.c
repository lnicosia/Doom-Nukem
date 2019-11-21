/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:39:19 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/20 12:13:46 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

int		save_benchmark(t_env *env);

static void	free_textures(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_TEXTURES)
	{
		if (env->textures[i].surface)
			SDL_FreeSurface(env->textures[i].surface);
		i++;
	}
}

void		free_events(t_event	*events, size_t size)
{
	size_t	j;

	j = 0;
	while (j < size)
	{
		if (events[j].check_param)
		{
			ft_memdel((void**)&events[j].check_param);
		}
		if (events[j].update_param)
		{
			ft_memdel((void**)&events[j].update_param);
		}
			j++;
	}
	if (events)
		ft_memdel((void**)&events);
}

static void	free_sectors(t_env *env)
{
	int		i;
	int		j;

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
		if (env->sectors[i].xmin)
			ft_memdel((void**)&env->sectors[i].xmin);
		if (env->sectors[i].xmax)
			ft_memdel((void**)&env->sectors[i].xmax);
		if (env->sectors[i].nb_sprites)
			ft_memdel((void**)&env->sectors[i].nb_sprites);
		if (env->sectors[i].floor_map_lvl)
			ft_memdel((void**)&env->sectors[i].floor_map_lvl);
		if (env->sectors[i].ceiling_map_lvl)
			ft_memdel((void**)&env->sectors[i].ceiling_map_lvl);
		if (env->sectors[i].walls_map_lvl)
		{
			j = 0;
			while (j < env->sectors[i].nb_vertices)
			{
				if (env->sectors[i].walls_map_lvl[j])
				ft_memdel((void**)&env->sectors[i].walls_map_lvl[j]);
				j++;
			}
			ft_memdel((void**)&env->sectors[i].walls_map_lvl);
		}
		if (env->sectors[i].sprites)
		{
			j = 0;
			while (j < env->sectors[i].nb_vertices)
			{
				if (env->sectors[i].sprites[j].sprite)
					ft_memdel((void**)&env->sectors[i].sprites[j].sprite);
				if (env->sectors[i].sprites[j].pos)
					ft_memdel((void**)&env->sectors[i].sprites[j].pos);
				if (env->sectors[i].sprites[j].scale)
					ft_memdel((void**)&env->sectors[i].sprites[j].scale);
				j++;
			}
		}
		free_events(env->sectors[i].walk_on_me_event,
		env->sectors[i].nb_walk_events);
		i++;
	}
	ft_memdel((void**)&env->sectors);
}

void		free_camera(t_camera *camera, t_env *env)
{
	int	i;
	int	j;

	(void)env;
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
		i = 0;
		while (i < camera->size)
		{
			if (camera->v[i])
			{
				j = 0;
				// Va poser probleme si sector_nb_vertices est NULL
				while (j < camera->sectors_size[i])
				{
					if (camera->v[i][j].sprite_scale)
						ft_memdel((void**)&camera->v[i][j].sprite_scale);
					if (camera->v[i][j].texture_scale)
						ft_memdel((void**)&camera->v[i][j].texture_scale);
					j++;
				}
				ft_memdel((void**)&camera->v[i]);
			}
			i++;
		}
		ft_memdel((void**)&camera->v);
	}
	if (camera->sectors_size)
		ft_memdel((void**)&camera->sectors_size);
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
	int 	i;
	t_list	*tmplst;

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
	if (env->sdl.fonts.lato20)
		TTF_CloseFont(env->sdl.fonts.lato20);
	if (env->sdl.fonts.bebasneue)
		TTF_CloseFont(env->sdl.fonts.bebasneue);
	free_camera(&env->player.camera, env);
	if (env->sectors)
		free_sectors(env);
	i = 0;
	// Leak peut etre si index 5 pas free
	while (i < 4)
	{
		if (env->skybox[i].texture_scale)
			ft_memdel((void**)&env->skybox[i].texture_scale);
		i++;
	};
	if (env->vertices)
		ft_memdel((void**)&env->vertices);
	if (env->objects)
		ft_memdel((void**)&env->objects);
	if (env->save_file)
		ft_strdel(&env->save_file);
	if (env->sound.background)
		Mix_FreeMusic(env->sound.background);
	if (env->sound.footstep)
		Mix_FreeChunk(env->sound.footstep);
	if (env->sound.jump)
		Mix_FreeChunk(env->sound.jump);
	if (env->sector_list)
		ft_memdel((void**)&env->sector_list);
	if (env->events)
			ft_lstdelfront(&env->events);
	if (env->queued_values)
			ft_lstdelfront(&env->queued_values);
	if (env->res[0])
		ft_strdel(&env->res[0]);
	if (env->res[1])
		ft_strdel(&env->res[1]);
	if (env->res[2])
		ft_strdel(&env->res[2]);
	if (env->input_box.str)
		ft_strdel(&env->input_box.str);
	i = 0;
	while (i < NB_WEAPONS)
	{
		if (env->weapons[i].empty)
			Mix_FreeChunk(env->weapons[i].empty);
		if (env->weapons[i].sound)
			Mix_FreeChunk(env->weapons[i].sound);
		i++;
	}
	free_events(env->global_events, env->nb_global_events);
	if (env->projectiles)
	{
		while (env->projectiles)
		{
			tmplst = env->projectiles;
			tmplst = tmplst->next;
			free(env->projectiles);
			env->projectiles = tmplst;
		}
	}
	free_textures(env);
	TTF_Quit();
	Mix_CloseAudio();
	SDL_Quit();
	ft_printf("Exiting..\n");
}

int			crash(char *str, t_env *env)
{
	ft_dprintf(STDERR_FILENO, "%s", str);
	ft_printf("{red}[Critical error]{reset}\n");
	free_all(env);
	return (-1);
}
