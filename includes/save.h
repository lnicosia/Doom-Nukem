/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 11:48:26 by lnicosia          #+#    #+#             */
/*   Updated: 2019/07/30 11:49:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SAVE_H
# define SAVE_H
# include "env.h"

void	write_vertices(int fd, t_env *env);
void	write_sectors(int fd, t_env *env);
void	write_objects(int fd, t_env *env);
void	write_player(int fd, t_env *env);

#endif