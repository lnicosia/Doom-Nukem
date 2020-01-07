/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_sprite_remover.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:01:20 by lnicosia          #+#    #+#             */
/*   Updated: 2019/12/04 18:01:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_SPRITE_REMOVER
# define WALL_SPRITE_REMOVER

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
