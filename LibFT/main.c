/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:34:49 by chon              #+#    #+#             */
/*   Updated: 2023/12/08 10:34:50 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int	main(void)
// {
// 	char **array = ft_split("Tripouille ", ' ');
// 	int i = 0;

// 	while (i < 4)
// 	{
// 		printf("%s;\n", array[i]);
// 		i++;
// 	}
// }

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s
{
    char *content;
    int   i;
    struct s *next;
}   list;

void	ft_lstclear(list **lst)
{
	list	**tmp;

	if (lst == NULL || *lst == NULL)
		return ;
	tmp = &((*lst)->next);
    printf("freeing: %i\n", (*lst)->i);
	free((*lst)->content);
	free(*lst);
	*lst = NULL;
	lst = tmp;
	ft_lstclear(tmp);
}

int main()
{
    int num = 0;
    list    **l;
    l = (list **)calloc(sizeof(list *), 1);

    list    *head = NULL;
    list    *cur = head;

    for (int i = 0; i < num; i++)
    {
        list *temp = (list *)calloc(sizeof(list), 1);
        temp->content = (char *)calloc(sizeof(char), 6);
        strcpy(temp->content, "Hello");
        temp->i = i;
        temp->next = NULL;
        if (head == NULL)
            head = temp;
        else
            cur->next = temp;
        cur = temp;
    }

    *l = head;
    cur = *l;

    for (int i = 0; i < num; i++)
    {
        printf("%i: %s\n", cur->i, cur->content);
        cur = cur->next;
    }

    ft_lstclear(l);
}