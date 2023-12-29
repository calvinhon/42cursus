/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:41:31 by chon              #+#    #+#             */
/*   Updated: 2023/12/23 11:46:17 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	trim_len(char const *s1, char const *set)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]) != NULL)
	{
		i++;
		count++;
	}
	if (i == (int)ft_strlen(s1))
		return (0);
	i = ft_strlen(s1) - 1;
	while (i > -1 && ft_strchr(set, s1[i]) != NULL)
	{
		i--;
		count++;
	}
	return (ft_strlen(s1) - count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		new_len;
	int		i;
	int		j;
	char	*str;

	new_len = trim_len(s1, set);
	i = 0;
	j = 0;
	str = malloc(new_len * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	while (ft_strchr(set, s1[i]) != NULL && s1[i])
		i++;
	while (new_len > 0)
	{
		str[j++] = *(s1 + i);
		i++;
		new_len--;
	}
	str[j] = '\0';
	return (str);
}
