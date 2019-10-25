/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   fps.c											  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lnicosia <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/04/17 11:07:32 by lnicosia		  #+#	#+#			 */
/*   Updated: 2019/07/24 14:58:11 by sipatry		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "env.h"

void	fps(t_env *env)
{
	int			new_time;
	double			fps;

	new_time = SDL_GetTicks();
	fps = 1000 / (new_time - env->sdl.time);
	env->fps = ft_sitoa(fps);
	if (new_time > 2000)
	{
		if (env->options.p)
		{
			if (!env->avrg_fps)
				env->avrg_fps = fps;
			if (fps > env->max_fps)
				env->max_fps = fps;
			if (fps < env->min_fps)
				env->min_fps = fps;
			env->avrg_fps = (env->avrg_fps + fps) / 2;
		}
		else
		{
			if (!env->avrg_fps2)
				env->avrg_fps2 = fps;
			if (fps > env->max_fps2)
				env->max_fps2 = fps;
			if (fps < env->min_fps2)
				env->min_fps2 = fps;
			env->avrg_fps2 = (env->avrg_fps2 + fps) / 2;
		}
	}
	if (new_time - env->render_swap_time > 1000)
	{
	//	env->options.p = env->options.p ? 0 : 1;
		env->render_swap_time = new_time;
	}
	if (env->options.show_fps)
	{
		print_text(new_point(0, 10), new_printable_text(
					env->fps,
					env->sdl.fonts.amazdoom50,
					0xFFFFFFFF,
					65),
				env);
	}
	env->sdl.time = new_time;
}
