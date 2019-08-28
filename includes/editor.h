/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:21:53 by sipatry           #+#    #+#             */
/*   Updated: 2019/08/26 12:00:39 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "utils.h"

typedef	struct	s_button
{
	t_point		start;
	t_point		end;
}				t_button;

typedef struct	s_hud
{
	int			draw_hud;
	int			x;
	int			y;
	t_button	plr;
}				t_hud;


typedef struct	s_plr
{
	double		x;
	double		y;
	double		z;
	double		angle;
	int			sector;
}				t_plr;

typedef struct	s_editor
{
	int			selected_sector;
	int			selected_object;
	int			selected_player;
	int			selected_vertex;
	int			start_vertex;
	int			nb_vertex;
	int			new_player;
	t_point		center;
	double		scale;
	t_list		*vertices;
	t_hud		hud;
	t_plr		player;
	t_list		*current_vertices;
	int			reverted;
	int			in_game;
}				t_editor;

#endif
