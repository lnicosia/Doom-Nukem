/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_sprite_remover.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:01:20 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 14:10:41 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_SPRITE_REMOVER_H
# define WALL_SPRITE_REMOVER_H

typedef struct		s_wall_sprite_remover
{
	int				sector;
	int				wall;
	int				sprite;
}					t_wall_sprite_remover;

typedef struct		s_floor_sprite_remover
{
	int				sector;
	int				sprite;
}					t_floor_sprite_remover;

#endif
