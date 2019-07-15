/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:39:19 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/10 16:18:33 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
		if (env->sectors[i].neighbors)
			ft_memdel((void**)&env->sectors[i].neighbors);
		i++;
	}
	ft_memdel((void**)&env->sectors);
}

void		free_all(t_env *env)
{
	int i;

	ft_printf("Freeing data..\n");
	if (!env)
		exit(0);
	if (env->sdl.window)
		SDL_DestroyWindow(env->sdl.window);
	if (env->sdl.renderer)
		SDL_DestroyRenderer(env->sdl.renderer);
	if (env->sdl.surface)
		SDL_FreeSurface(env->sdl.surface);
	if (env->sdl.fonts.amazdoom50)
		TTF_CloseFont(env->sdl.fonts.amazdoom50);
	if (env->sdl.fonts.amazdoom20)
		TTF_CloseFont(env->sdl.fonts.amazdoom20);
	if (env->sdl.fonts.alice)
		TTF_CloseFont(env->sdl.fonts.alice);
	if (env->sdl.fonts.bebasneue)
		TTF_CloseFont(env->sdl.fonts.bebasneue);
	if (env->sectors)
		free_sectors(env);
	if (env->sdl.texture_pixels)
		ft_memdel((void**)&env->sdl.texture_pixels);
	if (env->vertices)
		ft_memdel((void**)&env->vertices);
	if (env->xmin)
		ft_memdel((void**)&env->xmin);
	if (env->xmax)
		ft_memdel((void**)&env->xmax);
	if (env->screen_sectors)
		ft_memdel((void**)&env->screen_sectors);
	if (env->rendered_sectors)
		ft_memdel((void**)&env->rendered_sectors);
	if (env->depth_array)
		ft_memdel((void**)&env->depth_array);
	if (env->sound.background)
		Mix_FreeMusic(env->sound.background);
	if (env->sound.footstep)
		Mix_FreeChunk(env->sound.footstep);
	if (env->sound.footstep)
		Mix_FreeChunk(env->sound.jump);
	if (env->sector_list)
		free(env->sector_list);
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
