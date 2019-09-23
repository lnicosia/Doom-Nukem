/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicosia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/21 21:50:02 by lnicosia          #+#    #+#             */
/*   Updated: 2018/11/09 16:26:49 by lnicosia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nbr_of_words(char const *str, char charset)
{
	int		nbr;
	int		i;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] == charset)
			i++;
		else if (str[i] < ' ' || str[i] > '~')
			return (0);
		else
		{
			nbr++;
			while (str[i] && str[i] != charset)
			{
				i++;
			}
		}
	}
	return (nbr);
}

static int		ft_allocate_words(char const *str, char **res, char charset)
{
	int		nbr;
	int		i;
	int		size;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] == charset)
			i++;
		else
		{
			size = 0;
			while (str[i] && str[i] != charset)
			{
				size++;
				i++;
			}
			if (!(res[nbr] = (char*)malloc(sizeof(*str) * (size + 1))))
				return (0);
			nbr++;
		}
	}
	return (1);
}

static void		ft_fill_res(char const *str, char **res, char charset)
{
	int		nbr;
	int		i;
	int		j;

	i = 0;
	nbr = 0;
	while (str[i])
	{
		if (str[i] == charset)
			i++;
		else
		{
			j = 0;
			while (str[i] && str[i] != charset)
			{
				res[nbr][j] = str[i];
				j++;
				i++;
			}
			res[nbr][j] = '\0';
			nbr++;
		}
	}
}

char			**ft_strsplit(char const *str, char charset)
{
	int		words;
	char	**res;

	if (str == NULL || charset == '\0')
	{
		if (!(res = (char**)malloc(sizeof(char*))))
			return (0);
		res[0] = 0;
		return (res);
	}
	words = ft_nbr_of_words(str, charset);
	if (!(res = (char**)malloc(sizeof(char*) * (words + 1))))
		return (0);
	if (!(ft_allocate_words(str, res, charset)))
		return (0);
	ft_fill_res(str, res, charset);
	res[words] = 0;
	return (res);
}
