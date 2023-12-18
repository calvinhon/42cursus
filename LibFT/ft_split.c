/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:33:36 by chon              #+#    #+#             */
/*   Updated: 2023/12/08 10:16:18 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
			i++;
		count++;
	}
	if (s[i - 1] == c)
		return (count - 1);
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		str_ct;
	int		i;
	int		j;

	str_ct = str_count(s, c);
	array = malloc((str_ct + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (str_ct > 0)
	{
		while (s[j] == c)
			j++;
		array[i++] = ft_substr(s, j, ft_strchr(s + j, c) - (s + j));
		if (ft_strchr(s + j, c) == NULL)
			break ;
		j += ft_strchr(s + j, c) - (s + j);
		str_ct--;
	}
	array[i] = NULL;
	return (array);
}
