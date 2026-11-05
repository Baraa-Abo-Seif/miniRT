/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bablo <bablo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 11:38:03 by babo-sai          #+#    #+#             */
/*   Updated: 2026/10/19 17:02:19 by bablo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

/*int main(void)
{
    t_list *head = NULL;
    t_list *new_node = ft_lstnew("First Node");

    ft_lstadd_front(&head, new_node);
    printf("First node content: %s\n", (char *)head->content);

    new_node = ft_lstnew("Second Node");
    ft_lstadd_front(&head, new_node);
    printf("New first node content: %s\n", (char *)head->content);
}*/
