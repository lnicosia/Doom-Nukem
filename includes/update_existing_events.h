/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_existing_events.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 14:05:17 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 14:05:18 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UPDATE_EXISTING_EVENTS_H
# define UPDATE_EXISTING_EVENTS_H

typedef enum	e_update_types
{
	SECTOR_DELETED,
	VERTEX_DELETED,
	ENEMY_DELETED,
	OBJECT_DELETED
}				t_update_types;

#endif
