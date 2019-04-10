/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:08:03 by lnicosia          #+#    #+#             */
/*   Updated: 2019/02/22 16:09:04 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_UTILS_H
# define BASE_UTILS_H

void			set_spaces_base(t_data *data);
void			set_zeros_base(t_data *data, unsigned long nb, int base_len);
unsigned long	cast_base(t_data *data);

#endif
