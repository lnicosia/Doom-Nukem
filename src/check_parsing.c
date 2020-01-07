/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   check_parsing.c									:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: gaerhard <gaerhard@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/04/11 13:27:24 by lnicosia		  #+#	#+#			 */
/*   Updated: 2019/09/18 11:17:12 by lnicosia		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "env.h"

void	check_parsing(t_env *env)
{
	int	i;
	int	j;

	ft_printf("{yellow}Vertex %d\n", env->nb_vertices);
	i = 0;
	while (i < env->nb_vertices)
	{
		ft_printf("vertex	%f %f\n", env->vertices[i].y, env->vertices[i].x);
		i++;
	}
	ft_printf("\nSector %d\n", env->nb_sectors);
	i = 0;
	while (i < env->nb_sectors)
	{
		ft_printf("sector	%f %f	", env->sectors[i].floor,
				env->sectors[i].ceiling);
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			ft_printf("%d ", env->sectors[i].vertices[j]);
			j++;
		}
		ft_printf("	");
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			ft_printf("%d ", env->sectors[i].neighbors[j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\nplayer	%f %f	%f %d\n{reset}", env->player.pos.y,
			env->player.pos.x, env->player.camera.angle, env->player.sector);
}
