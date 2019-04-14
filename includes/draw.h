/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:20:37 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/14 20:20:21 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# define MAX_SECTORS_TO_RENDER 32
# define HFOV	0.73
# define VFOV	0.2
# include "utils.h"

typedef struct		s_line
{
	int				start;
	int				end;
	int				x;
	unsigned int	color;
}					t_line;

/*
**	Every variable needed for the rendering
*/

typedef struct		s_render
{
	t_line			line;
	int				xmin;
	int				xmax;
	int				ymin;
	int				ymax;
	t_v2			v1;
	t_v2			v2;
	double			vx1;
	double			vx2;
	double			vz1;
	double			vz2;
	int				currentx;
	int				floor1;
	int				floor2;
	int				ceiling1;
	int				ceiling2;
	int				x1;
	int				x2;
	int				xstart;
	int				xend;
	int				sector;
	int				father;
	int				light;
}					t_render;

#endif
