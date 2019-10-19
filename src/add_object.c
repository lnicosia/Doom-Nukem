/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   add_object.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sipatry <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/07/30 10:24:50 by sipatry		   #+#	#+#			 */
/*   Updated: 2019/09/09 16:58:03 by sipatry		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "env.h"

int	add_object(t_env *env)
{
	t_object	object;

	object.num = env->nb_objects;
	object.pos.x = (env->sdl.mx - env->editor.center.x) / env->editor.scale;
	object.pos.y = (env->sdl.my - env->editor.center.y) / env->editor.scale;
	object.sprite = 0;
	object.scale = 50;
	object.angle = 0;
	object.exists = 1;
	object.sector = get_sector_no_z(env, new_v3(object.pos.x, object.pos.y, 0));
	object.pos.z = env->sectors[object.sector].floor;
	if (object.sector != -1)
	{
		object.light_color = env->sectors[object.sector].light_color;
		object.brightness = env->sectors[object.sector].brightness;
	}
	else
	{
		object.light_color = 0xFFFFFFFF;
		object.brightness = 128;
	}
	if (!(env->objects = (t_object*)ft_realloc(env->objects, sizeof(t_object) * env->nb_objects, sizeof(t_object) * (env->nb_objects + 1))))
		return (ft_printf("Could not realloc objects\n"));
	env->objects[env->nb_objects] = object;
	return (0);
}
