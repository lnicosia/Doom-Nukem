/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaerhard <gaerhard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 16:29:22 by lnicosia          #+#    #+#             */
/*   Updated: 2019/11/13 17:14:04 by gaerhard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_list(t_list *list)
{
		while (list)
		{
				ft_printf("(%p)\t", list);
				ft_printf("%d\n", *(int*)list->content);
				list = list->next;
		}
}

void	func()
{
		t_list	*list;
		t_list	*tmp;
		int		nb;

		nb = 4;
		ft_lstpushback(&list, ft_lstnew(&nb, sizeof(nb)));
		nb = -45;
		ft_lstpushback(&list, ft_lstnew(&nb, sizeof(nb)));
		nb = 464;
		ft_lstpushback(&list, ft_lstnew(&nb, sizeof(nb)));
		nb = 0;
		ft_lstpushback(&list, ft_lstnew(&nb, sizeof(nb)));
		nb = 42;
		ft_lstpushback(&list, ft_lstnew(&nb, sizeof(nb)));
		print_list(list);
		tmp = list;
		ft_printf("{red}[DEL TEST]{reset}\n");
		while (tmp)
		{
				ft_printf("(%p)\t", tmp);
				ft_printf("%d\n", *(int*)tmp->content);
				if (*(int*)tmp->content == 42)
						tmp = ft_lstdelnode(&list, tmp);
				else
					tmp = tmp->next;
		}
		ft_printf("{green}[DEL OK]{reset}\n");
		print_list(list);
		ft_lstdelfront(&list);
}

int		main()
{
		func();
		while(1);
		return (0);
}
