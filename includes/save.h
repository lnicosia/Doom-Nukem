/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:48:26 by lnicosia          #+#    #+#             */
/*   Updated: 2020/03/03 16:19:55 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_H
# define SAVE_H
# include "env.h"

void	write_vertices(int fd, t_env *env);
void	write_sectors(int fd, t_env *env);
void	write_objects(int fd, t_env *env);
void	write_player(int fd, t_env *env);
void	write_enemies(int fd, t_env *env);
void	write_events(int fd, t_env *env);
void	write_music_choices(int fd, t_env *env);
void	write_events_links(int fd, t_env *env);
void	write_current_wall_sprites_events(int fd, t_sector sector,
void (*writers[])(int, t_event), int i);
void	write_sector_events(int fd, int num, t_sector sector,
void (*writers[])(int, t_event));
void	write_event(int fd, t_event event, void (*writers[])(int, t_event));
int		write_textures(int fd, t_env *env);
void	write_sector_portals(int fd, t_sector sector);
void	write_sector_neighbors(int fd, t_sector sector);
void	write_sector_vertices(int fd, t_sector sector);
void	write_sector_textures(int fd, t_sector sector);
void	write_sector_ceiling_sprites(int fd, t_sector sector, t_env *env);
void	write_sector_floor_sprites(int fd, t_sector sector, t_env *env);
void	write_sector_wall_sprites(int fd, t_sector sector, t_env *env);

#endif
