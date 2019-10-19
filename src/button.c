/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   button.c										   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lnicosia <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/02 15:43:06 by lnicosia		  #+#	#+#			 */
/*   Updated: 2019/09/03 18:50:04 by sipatry		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "env.h"

t_button	new_button(t_rectangle up, t_rectangle pressed, t_rectangle down)
{
	t_button	new;

	new.up = up;
	new.pressed = pressed;
	new.down = down;
	new.state = 0;
	new.pos = new_point(0, 0);
	new.size = new_point(0, 0);
	return (new);
}

void	draw_button(t_env *env, t_button b)
{
	if (!b.state)
		draw_rectangle(env, b.up, b.pos, b.size);
	else if (b.state == 1)
		draw_rectangle(env, b.pressed, b.pos, b.size);
	else if (b.state == 2)
		draw_rectangle(env, b.down, b.pos, b.size);
}
