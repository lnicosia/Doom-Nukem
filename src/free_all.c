/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:39:19 by lnicosia          #+#    #+#             */
/*   Updated: 2019/09/20 10:22:33 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

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
}

int			crash(char *str, t_env *env)
{
	ft_dprintf(STDERR_FILENO, "%s", str);
	ft_printf("{red}[Critical error]{reset}\n");
	free_all(env);
	return (-1);
}
