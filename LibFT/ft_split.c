/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:33:36 by chon              #+#    #+#             */
/*   Updated: 2023/11/16 16:09:29 by chon             ###   ########.fr       */
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
		if (s[i] == c)
			count++;
		i++;
	}
	if (count == (int)ft_strlen(s))
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1])
			count++;
		i++;
	}
	if (count == 0)
		count = 1;
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		str_ct;
	int		i;
	int		j;

	str_ct = str_count(s, c);
	printf("strs: %i\n", str_ct);
	array = malloc((str_ct + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	if (str_ct == 0)
		{
			array[0] = NULL;
			return (array);
		}
	j = 0;
	while (s[j] == c)
		j++;
	i = 0;
	while (str_ct > 0)
	{
		array[i++] = ft_substr(s, j, ft_strchr(s + j, c) - (s + j));
		j += ft_strchr(s + j, c) - (s + j);
		while (s[j] == c)
			j++;
		str_ct--;
	}
	array[i] = NULL;
	return (array);
}

int	main(void)
{
	char **array = ft_split("chinimala", ' ');
	int i = 0;

	while (i < 1)
	{
		printf("%s;\n", array[0]);
		i++;
	}
}