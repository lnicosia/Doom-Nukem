/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 15:39:51 by lnicosia          #+#    #+#             */
/*   Updated: 2020/05/01 15:39:52 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H
# include "env.h"

void	free_current_vertices(t_env *env);
void	free_camera(t_camera *camera);
void	free_all(t_env *env);
void	free_all_sdl_relative(t_env *env);
void	free_screen_sectors(t_env *env);
void	free_sector(t_sector *sector);
void	free_wall_sprites(t_wall_sprites *wall);
void	free_event(t_event *event);
void	free_events(t_event *event, size_t size);
void	free_map(t_env *env);
void	free_enemies(t_env *env);
void	free_objects(t_env *env);
void	free_sectors(t_env *env);
void	free_textures(t_env *env);
void	free_fonts(t_env *env);
void	free_audio(t_env *env, int i);

#endif
