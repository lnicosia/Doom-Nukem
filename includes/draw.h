/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:20:37 by lnicosia          #+#    #+#             */
/*   Updated: 2019/04/09 17:20:29 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H
# define MAX_SECTORS_TO_RENDER 32

typedef struct		s_render
{
	int				x1;
	int				x2;
	int				num;
}					t_render;

typedef struct		s_line
{
	int				start;
	int				end;
	int				x;
	unsigned int	color;
}					t_line;

void				map_brute(t_env *env);

#endif
