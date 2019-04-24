/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 15:39:19 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/24 17:37:50 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_all(t_env *env)
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
	TTF_Quit();
	SDL_Quit();
	exit(1);
}
