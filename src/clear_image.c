/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   clear_image.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lnicosia <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/04/03 15:54:43 by lnicosia		  #+#	#+#			 */
/*   Updated: 2019/09/18 13:27:44 by lnicosia		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "env.h"

void	clear_image(t_env *env)
{
	int	i;
	int	max;
	Uint32	*pixels;
	double	*zbuffer;

	i = 0;
	max = env->w * env->h;
	pixels = env->sdl.texture_pixels;
	zbuffer = env->zbuffer;
	while (i < max)
	{
		pixels[i] = 0xFF000000;
		zbuffer[i] = 999999999;
		i++;
	}
}
