/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_current_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 13:51:10 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/14 17:33:06 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int		get_current_map(int texture, t_render render, t_env *env)
{
	/*(void)texture;
	(void)render;
	return (0);*/
	int	res;
	t_point	haut_gauche;
	t_point	haut_droite;
	t_point	bas_gauche;
	t_point	bas_droite;
	t_render_vertex	v1;

	res = 0;
	(void)texture;
	v1 = render.camera->v[render.sector][render.i];
	haut_gauche = new_point(render.xstart, v1.c1);
	bas_droite = new_point(haut_gauche.x + render.texture_w,
	haut_gauche.y + render.texture_h);
	haut_droite = new_point(bas_droite.x, haut_gauche.y);
	bas_gauche = new_point(haut_gauche.x, bas_droite.y);
	/*end.y = v1.x -
	((env->sectors[render.sector].align[render.i].x - render.texture_h) * v1.vz)
	/ (v1.texture_scale.x * v1.zcomb
	+ (env->sectors[render.sector].align[render.i].x - render.texture_h) =
	* v1.zrange);*/
	//ft_printf("texture size on screen = [%d][%d] to [%d][%d]\n",
	//start.x, start.y, end.x, end.y);
	draw_line_free(haut_gauche, haut_droite, *env, 0xFFFF0000);
	draw_line_free(haut_droite, bas_droite, *env, 0xFFFF0000);
	draw_line_free(bas_gauche, bas_droite, *env, 0xFFFF0000);
	draw_line_free(haut_gauche, bas_gauche, *env, 0xFFFF0000);
	//ft_printf("distance from wall = %f\n", v1.vz);
	return (res);
}
