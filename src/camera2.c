/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/29 14:53:48 by lnicosia          #+#    #+#             */
/*   Updated: 2020/04/29 14:53:58 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

/*
**	Update camera position (save some computings)
*/

void	update_camera_position(t_camera *camera)
{
	camera->near_pos.x = camera->pos.x + camera->angle_cos * camera->near_z;
	camera->near_pos.y = camera->pos.y + camera->angle_sin * camera->near_z;
	camera->near_left_pos.x = camera->pos.x + (camera->angle_cos
	* camera->near_z - camera->angle_sin * camera->near_left);
	camera->near_left_pos.y = camera->pos.y + (camera->angle_sin
	* camera->near_z + camera->angle_cos * camera->near_left);
	camera->near_right_pos.x = camera->pos.x + (camera->angle_cos
	* camera->near_z - camera->angle_sin * camera->near_right);
	camera->near_right_pos.y = camera->pos.y + (camera->angle_sin
	* camera->near_z + camera->angle_cos * camera->near_right);
}

void	set_camera(t_camera *camera, t_env *env)
{
	camera->vfov = (180.0 / M_PI) * atan(tan((CONVERT_RADIANS
	* camera->hfov / 2)) / camera->ratio) * 2;
	camera->near_left = -tan(CONVERT_RADIANS * camera->hfov / 2)
	* camera->near_z;
	camera->near_right = tan(CONVERT_RADIANS * camera->hfov / 2)
	* camera->near_z;
	camera->range = camera->near_right - camera->near_left;
	camera->near_up = -tan(CONVERT_RADIANS * camera->vfov / 2)
	* camera->near_z;
	camera->near_down = tan(CONVERT_RADIANS * camera->vfov / 2)
	* camera->near_z;
	camera->far_left = -tan(CONVERT_RADIANS * camera->hfov / 2) * camera->far_z;
	camera->far_right = tan(CONVERT_RADIANS * camera->hfov / 2) * camera->far_z;
	camera->x1 = (camera->near_left / camera->near_z);
	camera->x2 = (camera->near_right / camera->near_z);
	camera->y1 = (camera->near_up / camera->near_z);
	camera->y2 = (camera->near_down / camera->near_z);
	camera->hscale = env->h_w / camera->x2;
	camera->vscale = env->h_h / camera->y2;
	camera->scale = camera->vscale;
}

int		set_camera_sprites_array(t_camera *camera, int i, int j, t_env *env)
{
	if (camera->v[i][j].sprite_scale)
		free(camera->v[i][j].sprite_scale);
	if (!(camera->v[i][j].sprite_scale = (t_v2*)ft_memalloc(sizeof(t_v2)
		* env->sectors[i].wall_sprites[j].nb_sprites)))
		return (ft_perror("Could not malloc camera sprites scales"));
	return (0);
}

int		set_camera_map_array(t_camera *camera, int i, int j, t_env *env)
{
	if (camera->v[i][j].texture_scale)
		free(camera->v[i][j].texture_scale);
	if (!(camera->v[i][j].texture_scale = (t_v2*)ft_memalloc(sizeof(t_v2)
		* env->wall_textures[env->sectors[i].textures[j]].nb_maps)))
		return (ft_perror("Could not malloc camera sprites scales"));
	if (camera->v[i][j].texture_align)
		free(camera->v[i][j].texture_align);
	if (!(camera->v[i][j].texture_align = (t_v2*)ft_memalloc(sizeof(t_v2)
		* env->wall_textures[env->sectors[i].textures[j]].nb_maps)))
		return (ft_perror("Could not malloc camera sprites scales"));
	return (0);
}
