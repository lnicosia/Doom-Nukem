/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:39:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/02 16:47:52 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	free_textures(t_env *env)
{
	int	i;

	i = 0;
	while (i < MAX_TEXTURES)
	{
		if (env->sprite_textures[i].surface)
			SDL_FreeSurface(env->sprite_textures[i].surface);
		i++;
	}
}

void		free_event(t_event *event)
{
	/*if (event->check_param)
		ft_memdel((void**)&event->check_param);
	if (event->exec_param)
		ft_memdel((void**)&event->exec_param);
	if (event->update_param)
		ft_memdel((void**)&event->update_param);*/
	if (event->exec_param)
		ft_memdel((void**)&event->exec_param);
	if (event->launch_conditions)
		ft_memdel((void**)&event->launch_conditions);
	if (event->exec_conditions)
		ft_memdel((void**)&event->exec_conditions);
}

void		free_events(t_event	*events, size_t size)
{
	size_t	j;

	j = 0;
	while (j < size)
	{
		free_event(&events[j]);
		j++;
	}
	if (events)
		ft_memdel((void**)&events);
}

static void	free_sectors(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_sectors)
	{
		free_sector(&env->sectors[i]);
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
					if (camera->v[i][j].texture_align)
						ft_memdel((void**)&camera->v[i][j].texture_align);
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
	if (env->ymin)
		ft_memdel((void**)&env->ymin);
	if (env->ymax)
		ft_memdel((void**)&env->ymax);
}

void		free_audio(t_env *env, int i)
{
	while (i < NB_WEAPONS)
	{
		FMOD_Sound_Release(env->weapons[i].shot);
		i++;
	}
	i = 0;
	FMOD_Sound_Release(env->sound.footstep);
	while (i < NB_MUSICS)
	{
		FMOD_Sound_Release(env->sound.musics[i].music);
		i++;
	}
	FMOD_System_Close(env->sound.system);
	FMOD_System_Release(env->sound.system);
}

void		free_objects(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_objects)
	{
		if (env->objects[i].nb_collision_events > 0
			&& env->objects[i].collision_events)
			free_events(env->objects[i].collision_events,
			env->objects[i].nb_collision_events);
		i++;
	}
	ft_memdel((void**)&env->objects);
}

void		free_enemies(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->nb_enemies)
	{
		if (env->enemies[i].nb_death_events > 0
			&& env->enemies[i].death_events)
			free_events(env->enemies[i].death_events,
			env->enemies[i].nb_death_events);
		if (env->enemies[i].nb_collision_events > 0
			&& env->enemies[i].collision_events)
			free_events(env->enemies[i].collision_events,
			env->enemies[i].nb_collision_events);
		i++;
	}
	ft_memdel((void**)&env->enemies);
}

void		free_parser(t_env *env)
{
	if (env->parser.tmp)
		ft_strdel(&(env->parser.tmp));
	if (env->parser.resource_name)
		ft_strdel(&(env->parser.resource_name));
	if (env->parser.line)
		ft_strdel(&(env->parser.line));
}

void		free_all(t_env *env)
{
	int 	i;
	t_list	*tmplst;

	ft_printf("Freeing data..\n");
	if (!env)
		return ;
	free_parser(env);
	if (env->editor.creating_event)
	{
		if (env->editor.event_panel.selected_event != -1)
			save_event(env);
		else
			create_event(env);
	}
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
	if (env->sdl.fonts.lato10)
		TTF_CloseFont(env->sdl.fonts.lato10);
	if (env->sdl.fonts.lato15)
		TTF_CloseFont(env->sdl.fonts.lato15);
	if (env->sdl.fonts.lato20)
		TTF_CloseFont(env->sdl.fonts.lato20);
	if (env->sdl.fonts.lato25)
		TTF_CloseFont(env->sdl.fonts.lato25);
	if (env->sdl.fonts.lato30)
		TTF_CloseFont(env->sdl.fonts.lato30);
	if (env->sdl.fonts.lato35)
		TTF_CloseFont(env->sdl.fonts.lato35);
	if (env->sdl.fonts.lato40)
		TTF_CloseFont(env->sdl.fonts.lato40);
	if (env->sdl.fonts.lato45)
		TTF_CloseFont(env->sdl.fonts.lato45);
	if (env->sdl.fonts.lato50)
		TTF_CloseFont(env->sdl.fonts.lato50);
	if (env->sdl.fonts.lato_black10)
		TTF_CloseFont(env->sdl.fonts.lato_black10);
	if (env->sdl.fonts.lato_black15)
		TTF_CloseFont(env->sdl.fonts.lato_black15);
	if (env->sdl.fonts.lato_black20)
		TTF_CloseFont(env->sdl.fonts.lato_black20);
	if (env->sdl.fonts.lato_black25)
		TTF_CloseFont(env->sdl.fonts.lato_black25);
	if (env->sdl.fonts.lato_black30)
		TTF_CloseFont(env->sdl.fonts.lato_black30);
	if (env->sdl.fonts.lato_black35)
		TTF_CloseFont(env->sdl.fonts.lato_black35);
	if (env->sdl.fonts.lato_black40)
		TTF_CloseFont(env->sdl.fonts.lato_black40);
	if (env->sdl.fonts.lato_black45)
		TTF_CloseFont(env->sdl.fonts.lato_black45);
	if (env->sdl.fonts.lato_black50)
		TTF_CloseFont(env->sdl.fonts.lato_black50);
	if (env->sdl.fonts.lato_bold10)
		TTF_CloseFont(env->sdl.fonts.lato_bold10);
	if (env->sdl.fonts.lato_bold15)
		TTF_CloseFont(env->sdl.fonts.lato_bold15);
	if (env->sdl.fonts.lato_bold20)
		TTF_CloseFont(env->sdl.fonts.lato_bold20);
	if (env->sdl.fonts.lato_bold25)
		TTF_CloseFont(env->sdl.fonts.lato_bold25);
	if (env->sdl.fonts.lato_bold30)
		TTF_CloseFont(env->sdl.fonts.lato_bold30);
	if (env->sdl.fonts.lato_bold35)
		TTF_CloseFont(env->sdl.fonts.lato_bold35);
	if (env->sdl.fonts.lato_bold40)
		TTF_CloseFont(env->sdl.fonts.lato_bold40);
	if (env->sdl.fonts.lato_bold45)
		TTF_CloseFont(env->sdl.fonts.lato_bold45);
	if (env->sdl.fonts.lato_bold50)
		TTF_CloseFont(env->sdl.fonts.lato_bold50);
	if (env->sdl.fonts.bebasneue)
		TTF_CloseFont(env->sdl.fonts.bebasneue);
	if (env->enemies)
		free_enemies(env);
	if (env->objects)
		free_objects(env);
	if (env->player.colliding_objects)
		ft_memdel((void**)&env->player.colliding_objects);
	if (env->player.colliding_enemies)
		ft_memdel((void**)&env->player.colliding_enemies);
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
	if (env->snprintf)
		ft_strdel(&env->snprintf);
	i = 0;
	free_events(env->global_events, env->nb_global_events);
	free_events(env->wall_bullet_holes_events,
	env->nb_wall_bullet_holes_events);
	free_events(env->floor_bullet_holes_events,
	env->nb_floor_bullet_holes_events);
	free_events(env->ceiling_bullet_holes_events,
	env->nb_ceiling_bullet_holes_events);
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
	free_audio(env, 0);
	free_textures(env);
	TTF_Quit();
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
