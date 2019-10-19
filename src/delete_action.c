/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   delete_action.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: lnicosia <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/08/30 15:41:33 by lnicosia		  #+#	#+#			 */
/*   Updated: 2019/09/04 11:38:12 by sipatry		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "env.h"

int		delete_action(t_env *env)
{
	int	i;

	if (env->editor.selected_vertex != -1
			&& !current_vertices_contains(env, env->editor.selected_vertex))
	{
		i = 0;
		delete_vertex(env, env->editor.selected_vertex);
		delete_invalid_sectors(env);
		delete_invalid_vertices(env);
		env->editor.selected_vertex = -1;
		clear_portals(env);
		while (i < env->nb_sectors)
		{
			create_portals(env, env->sectors[i]);
			i++;
		}
	}
	if (env->editor.selected_sector != -1)
	{
		if (!env->confirmation_box.state)
		{
			env->confirmation_box.state = 1;
			if (!(env->confirmation_box.str = ft_strdup("Delete the selected sector?")))
				return (ft_perror("Could not malloc confirmation box str"));
			new_confirmation_box(&env->confirmation_box, env);
		}
	}
	if (env->editor.selected_object != -1)
	{
		delete_object(env, env->editor.selected_object);
		env->editor.selected_object = -1;
	}
	if (env->editor.selected_player != -1)
	{
		env->editor.new_player = 0;
		env->editor.selected_player = -1;
	}
	env->inputs.del = 0;
	return (0);
}
