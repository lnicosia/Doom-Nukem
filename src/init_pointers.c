/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   init_pointers.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gaerhard <gaerhard@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/04/25 13:25:06 by lnicosia		  #+#	#+#			 */
/*   Updated: 2019/09/24 14:46:31 by gaerhard		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "env.h"

void	init_pointers(t_env *env)
{
	int	i;

	ft_printf("Initializing pointers..\n");
	env->sectors = NULL;
	env->vertices = NULL;
	env->objects = NULL;
	env->sprites = NULL;
	env->sdl.window = NULL;
	env->sdl.renderer = NULL;
	env->sdl.texture = NULL;
	env->sdl.texture_pixels = NULL;
	env->zbuffer = NULL;
	env->player.camera.rendered_sectors = NULL;
	env->player.camera.screen_sectors = NULL;
	env->player.camera.screen_pos = NULL;
	env->player.camera.xmin = NULL;
	env->player.camera.xmax = NULL;
	env->sdl.fonts.amazdoom20 = NULL;
	env->sdl.fonts.amazdoom50 = NULL;
	env->sdl.fonts.bebasneue = NULL;
	env->sdl.fonts.alice30 = NULL;
	env->sdl.fonts.alice70 = NULL;
	env->sound.background = NULL;
	env->sound.footstep = NULL;
	env->sound.jump = NULL;
	env->sector_list = NULL;
	env->res[0] = NULL;
	env->res[1] = NULL;
	env->res[2] = NULL;
	i = 0;
	while (i < MAX_TEXTURE)
	{
		env->textures[i].surface = NULL;
		env->textures[i].str = NULL;
		i++;
	}
	i = 0;
	while (i < NB_WEAPONS)
	{
		env->weapons[i].sound = NULL;
		env->weapons[i].empty = NULL;
		i++;
	}
	env->player.health = 100;
}
