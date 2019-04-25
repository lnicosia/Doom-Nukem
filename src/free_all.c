/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:39:19 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/25 12:30:16 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

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
		if (env->sectors[i].neighbors)
			ft_memdel((void**)&env->sectors[i].neighbors);
		i++;
	}
	free(env->sectors);
	env->sectors = NULL;
}

void		free_all(t_env *env)
{
	ft_printf("freeing all..\n");
	if (env->sdl.window)
		SDL_DestroyWindow(env->sdl.window);
	if (env->sdl.renderer)
		SDL_DestroyRenderer(env->sdl.renderer);
	if (env->sdl.texture)
		SDL_DestroyTexture(env->sdl.texture);
	if (env->sdl.surface)
		SDL_FreeSurface(env->sdl.surface);
	if (env->sdl.font)
		TTF_CloseFont(env->sdl.font);
	if (env->sectors)
		free_sectors(env);
	if (env->vertices)
		ft_memdel((void**)&env->vertices);
	TTF_Quit();
	SDL_Quit();
	ft_printf("Exiting..\n");
	exit(1);
}

void		crash(char *str, t_env *env)
{
	ft_dprintf(STDERR_FILENO, "%s", str);
	free_all(env);
}
