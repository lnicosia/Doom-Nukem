/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_slope.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 17:04:57 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/18 17:18:10 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "render.h"

void	get_slope(t_render *render, int vertex_nb, t_env *env)
{
	t_vertex	v0;
	t_vertex	vi;

	v0 = env->vertices[env->sectors[render->sector].vertices[0]];
	vi = env->vertices[env->sectors[render->sector].vertices[vertex_nb]];
	render->dist = sqrt(pow(vi.x - v0.x, 2) + pow(vi.y - v0.y, 2));
}
