/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 11:57:06 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/09 14:22:56 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "draw.h"

void	draw_line(t_cast cast, t_env *env)
{
	while (cast.start <= cast.end)
	{
		env->sdl.img_str[cast.currentx + env->w * cast.start] = cast.color;
		cast.start++;
	}
}

void	draw(t_env *env)
{
	t_sector	current;
	t_cast		cast;
	int			i;

	map_brute(env);
	current = env->sectors[env->player.sector];
	i = 0;
	(void)cast;
	while (i < current.nbvertices)
	{
		// Rendre chaque mur present dans le champ de vision du joueur
		// = raycasting?
		// Afficher sol + plafond
		i++;
	}

}
