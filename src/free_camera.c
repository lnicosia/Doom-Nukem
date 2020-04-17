#include "env.h"

void		free_camera_sectors_size(t_camera *camera, int i)
{
	int	j;

	j = 0;
	while (j < camera->sectors_size[i])
	{
		if (camera->v[i][j].sprite_scale)
			ft_memdel((void**)&camera->v[i][j].sprite_scale);
		if (camera->v[i][j].texture_scale)
			ft_memdel((void**)&camera->v[i][j].texture_scale);
		if (camera->v[i][j].texture_align)
			ft_memdel((void**)&camera->v[i][j].texture_align);
		j++;
	}
	ft_memdel((void**)&camera->v[i]);
}

void		free_camera2(t_camera *camera)
{
	int	i;

	i = 0;
	if (camera->v)
	{
		while (i < camera->size)
		{
			if (camera->v[i])
		  		free_camera_sectors_size(camera, i);
			i++;
		}
		ft_memdel((void**)&camera->v);
	}
	if (camera->sectors_size)
		ft_memdel((void**)&camera->sectors_size);
}


void		free_camera(t_camera *camera)
{
	if (camera->screen_sectors)
		ft_memdel((void**)&camera->screen_sectors);
	if (camera->screen_pos)
		ft_memdel((void**)&camera->screen_pos);
	if (camera->rendered_sectors)
		ft_memdel((void**)&camera->rendered_sectors);
	if (camera->xmin)
		ft_memdel((void**)&camera->xmin);
	if (camera->xmax)
		ft_memdel((void**)&camera->xmax);
	if (camera->feet_y)
		ft_memdel((void**)&camera->feet_y);
	if (camera->head_y)
		ft_memdel((void**)&camera->head_y);
	if (camera->sector_computed)
		ft_memdel((void**)&camera->sector_computed);
	free_camera2(camera);
}
