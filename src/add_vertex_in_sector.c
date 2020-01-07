/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_vertex_in_sector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 11:43:33 by sipatry           #+#    #+#             */
/*   Updated: 2019/11/29 16:42:15 by sipatry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"
#include "add_vertex.h"
#include "collision.h"

int		*get_sectors_list(t_env *env, int v1, int v2)
{
	int	*sectors;
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 1;
	if (!(sectors = (int *)malloc(sizeof(int) * 2)))
		return (0);
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			if (((j > 0 && env->sectors[i].vertices[j] == v1 && (env->sectors[i].vertices[j - 1] == v2
			|| env->sectors[i].vertices[j + 1] == v2)))
			|| (env->sectors[i].vertices[j] == v1 && j == 0
			&& (env->sectors[i].vertices[env->sectors[i].nb_vertices - 1] == v2
			|| env->sectors[i].vertices[j + 1] == v2)))
			{
				if (!(sectors = (int *)ft_realloc(sectors, sizeof(int) * k, sizeof(int) * (k + 1))))
					return (0);
				sectors[k] = i;
				k++;
			}
			j++;
		}
		i++;
	}
	sectors[0] = k - 1;
    if (k != 1)
	    return (sectors);
    return (NULL);
}

int		is_mouse_on_a_wall(t_env *env)
{
	int		i;
	int		j;
	t_v2	v1;
	t_v2	v2;
	t_v2	mouse;

	i = 0;
	while (i < env->nb_sectors)
	{
		j = 0;
		while (j < env->sectors[i].nb_vertices)
		{
			v1 = new_v2(env->vertices[env->sectors[i].vertices[j]].x, env->vertices[env->sectors[i].vertices[j]].y);
			v2 = new_v2(env->vertices[env->sectors[i].vertices[j + 1]].x, env->vertices[env->sectors[i].vertices[j + 1]].y);
			mouse = new_v2(round((env->sdl.mx - env->editor.center.x) / env->editor.scale),
			round((env->sdl.my - env->editor.center.y) / env->editor.scale));
			if (get_existing_vertex(env) == -1)
			{
				if (hitbox_collision(v1, v2, mouse, 0.5))
				{
					env->editor.add.v1 = env->sectors[i].vertices[j];
					env->editor.add.v2 = env->sectors[i].vertices[j + 1];
					return (1);
				}
			}
			else
			{
				ft_printf("a vertex already exist at this position\n");
				return (0);
			}
			j++;
		}
		i++;
	}
/*	ft_printf("nb_vertices: %d| i: %d\n", env->sectors[i].nb_vertices, i);
	v1 = new_v2(env->vertices[env->sectors[i].vertices[j]].x, env->vertices[env->sectors[i].vertices[j]].y);
	v2 = new_v2(env->vertices[env->sectors[i].vertices[j]].x, env->vertices[env->sectors[i].vertices[j]].y);
	mouse = new_v2(round((env->sdl.mx - env->editor.center.x) / env->editor.scale),
	round((env->sdl.my - env->editor.center.y) / env->editor.scale));
	if (hitbox_collision(v1, v2, mouse, 0.5))
		return (1);*/
	/*if (env->editor.select_vertex_on_going)
	{
		if (env->editor.add.v1 == -1)
	        env->editor.add.v1 = env->editor.selected_vertex;
		else if(env->editor.selected_vertex != env->editor.add.v1 && env->editor.add.v2 == -1)
		{
	        env->editor.add.v2 = env->editor.selected_vertex;
			env->editor.select_vertex_on_going = 0;
		}
	}
	if (env->editor.add.v1 != -1 && env->editor.add.v2 != -1)
    	return (1);*/
	ft_printf("mouse isn't on a wall\n");
	return (0);
}

int		modify_vertices_in_sector(t_env *env, int index, int sector)
{
	int	i;

	if (!(env->sectors[sector].vertices = (short *)ft_realloc(env->sectors[sector].vertices, sizeof(short)
	* (env->sectors[sector].nb_vertices + 1), sizeof(short) * (env->sectors[sector].nb_vertices + 2))))
		return (ft_perror("Could not realloc vertices"));
	env->sectors[sector].nb_vertices++;
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		env->sectors[sector].vertices[i] = 	env->sectors[sector].vertices[i - 1];
		i--;
	}
	env->sectors[sector].vertices[i] = env->vertices[env->nb_vertices - 1].num;
	env->sectors[sector].vertices[env->sectors[sector].nb_vertices] = env->sectors[sector].vertices[0];
	return (0);
}

int		modify_textures(t_env *env, int index, int sector)
{
	int	i;

	i = 0;
	if (!(env->sectors[sector].textures = (short *)ft_realloc(env->sectors[sector].textures, sizeof(short)
	* env->sectors[sector].nb_vertices, sizeof(short) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc textures"));
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		env->sectors[sector].textures[i] = env->sectors[sector].textures[i - 1];
		i--;
	}
	env->sectors[sector].textures[i] = env->sectors[sector].textures[i - 1];
	return (0);
}

int		modify_double_tab_in_sector(t_env *env, int index, int sector, double **tab)
{
	int	i;

	if (!(*tab = (double *)ft_realloc(*tab, sizeof(double)
	* env->sectors[sector].nb_vertices, sizeof(double) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc double tab"));
	i = 0;
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		(*tab)[i] = (*tab)[i - 1];
		i--;
	}
	(*tab)[i] = (*tab)[i - 1];
	return (0);
}

int		modify_short_tab_in_sector(t_env *env, int index, int sector, short **tab)
{
	int	i;

	if (!(*tab = (short*)ft_realloc(*tab, sizeof(short)
	* env->sectors[sector].nb_vertices, sizeof(short) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc short tab"));
	i = 0;
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		(*tab)[i] = (*tab)[i - 1];
		i--;
	}
	(*tab)[i] = (*tab)[i - 1];
	return (0);
}

int		modify_t_v2_tab_in_sector(t_env *env, int index, int sector,t_v2 **tab)
{
	int	i;

	if (!(*tab = (t_v2*)ft_realloc(*tab, sizeof(t_v2)
	* env->sectors[sector].nb_vertices, sizeof(t_v2) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc short tab"));
	i = 0;
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		(*tab)[i] = (*tab)[i - 1];
		i--;
	}
	(*tab)[i] = (*tab)[i - 1];
	return (0);
}

int		modify_t_wall_sprites_tab_in_sector(t_env *env, int index, int sector,t_wall_sprites **tab)
{
	int	i;

	if (!(*tab = (t_wall_sprites*)ft_realloc(*tab, sizeof(t_wall_sprites)
	* env->sectors[sector].nb_vertices, sizeof(t_wall_sprites) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc short tab"));
	i = 0;
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		(*tab)[i] = (*tab)[i - 1];
		i--;
	}
	(*tab)[i] = (*tab)[i - 1];
	return (0);
}

int		modify_walls_map_lvl(t_env *env, int sector)
{
	int	j;

	j = 0;
	while (j < env->sectors[sector].nb_vertices - 1)
	{
		if (env->sectors[sector].walls_map_lvl[j])
			ft_memdel((void**)&env->sectors[sector].walls_map_lvl[j]);
		j++;
	}
	ft_memdel((void**)&env->sectors[sector].walls_map_lvl);
	j = 0;
	if (!(env->sectors[sector].walls_map_lvl = (double **)ft_realloc(env->sectors[sector].walls_map_lvl, sizeof(double*)
	* env->sectors[sector].nb_vertices, sizeof(double*) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc walls_map_lvl"));
	while(j < env->sectors[sector].nb_vertices)
	{
		set_sector_wall_map_array(&env->sectors[sector], env->wall_textures[env->sectors[sector].textures[j]], j, env);
		j++;
	}
	return (0);
}

int		modify_neighbors(t_env *env, int index, int sector)
{
	int	i;

	if (!(env->sectors[sector].neighbors = (short *)ft_realloc(env->sectors[sector].neighbors, sizeof(short)
	* env->sectors[sector].nb_vertices, sizeof(short) * (env->sectors[sector].nb_vertices + 1))))
		return (ft_perror("Could not realloc neighbors"));
	i = env->sectors[sector].nb_vertices;
	while (i > index + 1)
	{
		env->sectors[sector].neighbors[i] = env->sectors[sector].neighbors[i - 1];
		i--;
	}
	env->sectors[sector].neighbors[i] = env->sectors[sector].neighbors[i - 1];
	return (0);
}

int     modify_sector(t_env *env, int sector)
{
    int j;

    j = 0;
    while (j < env->sectors[sector].nb_vertices)
    {
        if (env->sectors[sector].vertices[j] == env->editor.add.v1 || env->sectors[sector].vertices[j] == env->editor.add.v2)
		{
			if ((env->editor.add.v1 == env->sectors[sector].vertices[0]
			&& env->editor.add.v2 == env->sectors[sector].vertices[env->sectors[sector].nb_vertices - 1])
			|| (env->editor.add.v2 == env->sectors[sector].vertices[0]
			&& env->editor.add.v1 == env->sectors[sector].vertices[env->sectors[sector].nb_vertices - 1]))
				j = env->sectors[sector].nb_vertices - 1;
			if (modify_vertices_in_sector(env, j, sector))
				return (-1);
			if (modify_textures(env, j, sector))
				return (-1);
			if (modify_neighbors(env, j, sector))
				return (-1);
			/*if (modify_short_tab_in_sector(env, j, sector, &env->sectors[sector].nb_sprites))
				return (-1);*/
			if (modify_short_tab_in_sector(env, j, sector, &env->sectors[sector].selected))
				return (-1);
			if (modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].floors))
				return (-1);
			if (modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].ceilings))
				return (-1);
			if (modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].clipped_floors1))
				return (-1);
			if (modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].clipped_ceilings1))
				return (-1);
			if (modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].clipped_ceilings2))
				return (-1);
			if (modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].clipped_floors2))
				return (-1);
			if (modify_double_tab_in_sector(env, j, sector, &env->sectors[sector].wall_width))
				return (-1);
			if (modify_t_v2_tab_in_sector(env, j, sector, &env->sectors[sector].scale))
				return (-1);
			if (modify_t_v2_tab_in_sector(env, j, sector, &env->sectors[sector].align))
				return (-1);
			if (modify_t_wall_sprites_tab_in_sector(env, j, sector, &env->sectors[sector].wall_sprites))
				return (-1);
			if (modify_walls_map_lvl(env, sector))
				return (-1);
			break;
		}
        j++;
    }
	return (0);
}

int		modify_vertices(t_env *env)
{
/*	double min;
	double max;*/

	if (!(env->vertices = (t_vertex *)ft_realloc(env->vertices, sizeof(t_vertex)
			* env->nb_vertices, sizeof(t_vertex) * (env->nb_vertices + 1))))
		return (ft_perror("Could not realloc env vertices"));
	env->nb_vertices++;
/*	min = env->vertices[env->editor.add.v1].x < env->vertices[env->editor.add.v2].x ?
	env->vertices[env->editor.add.v1].x : env->vertices[env->editor.add.v2].x;
	max = env->vertices[env->editor.add.v1].x > env->vertices[env->editor.add.v2].x ?
	env->vertices[env->editor.add.v1].x : env->vertices[env->editor.add.v2].x;
	env->vertices[env->nb_vertices - 1].x =	round(min + ((max - min) / 2));
	min = env->vertices[env->editor.add.v1].y < env->vertices[env->editor.add.v2].y ?
	env->vertices[env->editor.add.v1].y : env->vertices[env->editor.add.v2].y;
	max = env->vertices[env->editor.add.v1].y > env->vertices[env->editor.add.v2].y ?
	env->vertices[env->editor.add.v1].y : env->vertices[env->editor.add.v2].y;
	env->vertices[env->nb_vertices - 1].y = round(min + ((max - min) / 2));*/
	env->vertices[env->nb_vertices - 1].x = round((env->sdl.mx - env->editor.center.x) / env->editor.scale);
	env->vertices[env->nb_vertices - 1].y = round((env->sdl.my - env->editor.center.y) / env->editor.scale);
	env->vertices[env->nb_vertices - 1].num = env->nb_vertices - 1;
	return (0);
}

int     add_vertex_in_sector(t_env *env)
{
    int             i;

	i = 1;
    if (!(env->editor.add.sector_list = get_sectors_list(env, env->editor.add.v1, env->editor.add.v2)))
         return (1);
	if (modify_vertices(env))
		return (-1);
	i = 1;
	while (i <= env->editor.add.sector_list[0])
		{
    		if (modify_sector(env, env->editor.add.sector_list[i]))
		   return (-1);
			i++;
		}
	env->editor.add.v1 = -1;
	env->editor.add.v2 = -1;
    return (0);
}
