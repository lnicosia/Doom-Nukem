/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   delete_object.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gaerhard <gaerhard@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/08/26 15:39:31 by lnicosia		  #+#	#+#			 */
/*   Updated: 2020/02/04 10:16:40 by lnicosia         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "env.h"

int	delete_object(void *param)
{
	t_env	*env;
	int		object;

	env = (t_env*)param;
	object = env->selected_object;
	env->objects = ft_delindex(env->objects,
			sizeof(t_object) * env->nb_objects,
			sizeof(t_object),
			sizeof(t_object) * object);
	env->nb_objects--;
	env->selected_object = -1;
	return (0);
}
