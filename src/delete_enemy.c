/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   delete_enemy.c									 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: sipatry <marvin@42.fr>					 +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/05 16:47:13 by sipatry		   #+#	#+#			 */
/*   Updated: 2019/09/06 16:36:41 by sipatry		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "env.h"

int	delete_enemy(t_env *env, int enemy)
{
	env->enemies = ft_delindex(env->enemies,
			sizeof(t_enemies) * env->nb_enemies,
			sizeof(t_enemies),
			sizeof(t_enemies) * enemy);
	env->nb_enemies--;
	env->selected_enemy = -1;
	return (0);
}
