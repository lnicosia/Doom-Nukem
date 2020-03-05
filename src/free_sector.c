/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <sipatry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 10:08:19 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/05 09:46:05 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h" 

void		free_wall_sprites(t_wall_sprites *wall)
{
	int		i;

	i = 0;
	while (i < wall->nb_sprites)
	{
		if (wall->nb_shoot_events && wall->nb_shoot_events[i] > 0
			&& wall->shoot_events && wall->shoot_events[i])
			free_events(wall->shoot_events[i], wall->nb_shoot_events[i]);
		if (wall->nb_press_events && wall->nb_press_events[i] > 0
			&& wall->press_events && wall->press_events[i])
			free_events(wall->press_events[i], wall->nb_press_events[i]);
		i++;
	}
	if (wall->sprite)
		ft_memdel((void**)&wall->sprite);
	if (wall->pos)
		ft_memdel((void**)&wall->pos);
	if (wall->scale)
		ft_memdel((void**)&wall->scale);
	if (wall->nb_press_events)
		ft_memdel((void**)&wall->nb_press_events);
	if (wall->nb_shoot_events)
		ft_memdel((void**)&wall->nb_shoot_events);
	if (wall->press_events)
		ft_memdel((void**)&wall->press_events);
	if (wall->shoot_events)
		ft_memdel((void**)&wall->shoot_events);
}

void		free_sector(t_sector *sector)
{
	//int	i;
	int	j;

	if (sector->vertices)
		ft_memdel((void**)&sector->vertices);
	if (sector->neighbors)
		ft_memdel((void**)&sector->neighbors);
	if (sector->textures)
		ft_memdel((void**)&sector->textures);
	if (sector->ceilings)
		ft_memdel((void**)&sector->ceilings);
	if (sector->floors)
		ft_memdel((void**)&sector->floors);
	if (sector->clipped_ceilings1)
		ft_memdel((void**)&sector->clipped_ceilings1);
	if (sector->clipped_floors1)
		ft_memdel((void**)&sector->clipped_floors1);
	if (sector->clipped_ceilings2)
		ft_memdel((void**)&sector->clipped_ceilings2);
	if (sector->clipped_floors2)
		ft_memdel((void**)&sector->clipped_floors2);
	if (sector->wall_width)
		ft_memdel((void**)&sector->wall_width);
	if (sector->align)
		ft_memdel((void**)&sector->align);
	if (sector->scale)
		ft_memdel((void**)&sector->scale);
	if (sector->portals)
		ft_memdel((void**)&sector->portals);
	if (sector->floor_map_lvl)
		ft_memdel((void**)&sector->floor_map_lvl);
	if (sector->ceiling_map_lvl)
		ft_memdel((void**)&sector->ceiling_map_lvl);
	if (sector->floor_align)
		ft_memdel((void**)&sector->floor_align);
	if (sector->floor_scale)
		ft_memdel((void**)&sector->floor_scale);
	if (sector->ceiling_align)
		ft_memdel((void**)&sector->ceiling_align);
	if (sector->ceiling_scale)
		ft_memdel((void**)&sector->ceiling_scale);
	if (sector->selected)
		ft_memdel((void**)&sector->selected);
	if (sector->walls_map_lvl)
	{
		j = 0;
		while (j <= sector->nb_vertices)
		{
			if (sector->walls_map_lvl[j])
				ft_memdel((void**)&sector->walls_map_lvl[j]);
			j++;
		}
		ft_memdel((void**)&sector->walls_map_lvl);
	}
	free_wall_sprites(&sector->floor_sprites);
	free_wall_sprites(&sector->ceiling_sprites);
	if (sector->wall_sprites)
	{
		j = 0;
		while (j < sector->nb_vertices)
		{
			/*if (sector->wall_sprites[j].sprite)
				ft_memdel((void**)&sector->wall_sprites[j].sprite);
			if (sector->wall_sprites[j].pos)
				ft_memdel((void**)&sector->wall_sprites[j].pos);
			if (sector->wall_sprites[j].scale)
				ft_memdel((void**)&sector->wall_sprites[j].scale);
			if (sector->wall_sprites[j].shoot_events)
			{
				i = 0;
				while (i < sector->wall_sprites[j].nb_sprites)
				{
					if (sector->wall_sprites[j].shoot_events[i])
						ft_memdel((void**)&sector->wall_sprites[j].shoot_events[i]);
					i++;
				}
			}
			if (sector->wall_sprites[j].press_events)
			{
				i = 0;
				while (i < sector->wall_sprites[j].nb_sprites)
				{
					if (sector->wall_sprites[j].press_events[i])
						ft_memdel((void**)&sector->wall_sprites[j].press_events[i]);
					i++;
				}
			}
			if (sector->wall_sprites[j].nb_shoot_events)
				ft_memdel((void**)&sector->wall_sprites[j].nb_shoot_events);
			if (sector->wall_sprites[j].nb_press_events)
				ft_memdel((void**)&sector->wall_sprites[j].nb_press_events);*/
			free_wall_sprites(&sector->wall_sprites[j]);
			j++;
		}
		ft_memdel((void**)&sector->wall_sprites);
	}
	if (sector->ceiling_sprites_scale)
		ft_memdel((void**)&sector->ceiling_sprites_scale);
	if (sector->floor_sprites_scale)
		ft_memdel((void**)&sector->floor_sprites_scale);
	if (sector->ceiling_sprites.sprite)
		ft_memdel((void**)&sector->ceiling_sprites.sprite);
	if (sector->ceiling_sprites.scale)
		ft_memdel((void**)&sector->ceiling_sprites.scale);
	if (sector->ceiling_sprites.pos)
		ft_memdel((void**)&sector->ceiling_sprites.pos);
	if (sector->floor_sprites.sprite)
		ft_memdel((void**)&sector->floor_sprites.sprite);
	if (sector->floor_sprites.scale)
		ft_memdel((void**)&sector->floor_sprites.scale);
	if (sector->floor_sprites.pos)
		ft_memdel((void**)&sector->floor_sprites.pos);
	if (sector->wall_bullet_holes)
	{
		j = 0;
		while (j <= sector->nb_vertices)
		{
			ft_lstdelfront(&sector->wall_bullet_holes[j]);
			j++;
		}
		ft_memdel((void**)&sector->wall_bullet_holes);
	}
	free_events(sector->stand_events,
			sector->nb_stand_events);
	free_events(sector->walk_in_events,
			sector->nb_walk_in_events);
	free_events(sector->walk_out_events,
			sector->nb_walk_out_events);
}
