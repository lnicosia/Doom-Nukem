/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_sprites2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 11:39:25 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 11:39:25 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

void	update_enemy(t_env *env, int i)
{
	update_enemy_light(env, i);
	update_enemy_z(env, i);
}

void	update_object(t_env *env, int i)
{
	update_object_light(env, i);
	update_object_z(env, i);
}
