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

/*
**	Editor save functions
*/

int		write_resources(int fd, t_env *env);
int		write_sounds(int fd, t_env *env);
int		write_sound(int file, int fd, char *name);
int		write_textures1(int fd);
int		write_textures2(int fd);
int		write_textures3(int fd);
int		write_sprites1(int fd);
int		write_sprites2(int fd);
int		write_sprites3(int fd);
int		write_skybox1(int fd, int file);
int		write_skybox2(int fd, int file);
int		write_skybox3(int fd, int file);
int		write_fonts1(int fd, int file);
int		write_fonts2(int fd, int file);
int		write_hud1(int fd, int file);
int		write_hud2(int fd, int file);
int		write_hud3(int fd, int file);
int		write_hud4(int fd, int file);
int		write_hud5(int fd, int file);
int		write_hud6(int fd, int file);
int		write_hud7(int fd, int file);
int		write_hud8(int fd, int file);
int		write_hud9(int fd, int file);
int		writing_bmp(int file, int fd, char *name);
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
