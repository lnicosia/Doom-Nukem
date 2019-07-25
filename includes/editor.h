/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:21:53 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/25 17:11:59 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EDITOR_H
# define EDITOR_H

# include "utils.h"

typedef struct	s_editor
{
	int			menu;
	int			select_mode;
	int			nb_vertex;
	t_point		center;
	double		scale;
	t_list		*vertices;
	t_list		*current_vertices;
	t_list		*sectors;
	int			current_sector_start;
	int			vertex_count;
	int			sector_done;
}				t_editor;

#endif
