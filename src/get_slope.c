/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_slope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:04:57 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/22 12:38:53 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

t_v2	get_normal(t_v2 v1, t_v2 v2)
{
	t_v2	normal;
	double	norm;

	norm = sqrt(pow(v2.x - v1.x, 2) + pow(v2.y - v1.y, 2));
	normal.x = ((v2.x - v1.x) / norm);
	normal.y = ((v2.y - v1.y) / norm);
	return (normal);
}

t_v2	get_sector_floor_normal(t_sector sector, t_env *env)
{
	t_vertex	v1;
	t_vertex	v2;

	v1 = env->vertices[sector.vertices[0]];
	v2 = env->vertices[sector.vertices[1]];
	return (get_normal(new_v2(v1.x, v1.y), new_v2(v2.x, v2.y)));
}

void	get_slope(t_render *render, int vertex_nb, t_env *env)
{
	t_vertex	v0;
	t_vertex	vi;

	v0 = env->vertices[env->sectors[render->sector].vertices[0]];
	vi = env->vertices[env->sectors[render->sector].vertices[vertex_nb]];
	render->dist1 = sqrt(pow(vi.x - v0.x, 2) + pow(vi.y - v0.y, 2));
	render->dist2 = sqrt(pow(vi.x - v0.x, 2) + pow(vi.y - v0.y, 2));
}
