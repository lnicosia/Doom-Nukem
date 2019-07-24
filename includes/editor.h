/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipatry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:21:53 by sipatry           #+#    #+#             */
/*   Updated: 2019/07/24 17:34:27 by sipatry          ###   ########.fr       */
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
}				t_editor;

#endif
