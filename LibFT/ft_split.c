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
	// if (ft_strlen(s) < 1)
	// 	return (1);
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

	if (s == NULL)
		return (NULL);
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
	// printf("str_ct:%i i:%i\n", str_ct, i);
	return (array);
}

// int	main(void)
// {
// 	int i = 0;
// 	char **tab = ft_split("", 'z');
// 	// char **tab = ft_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", '.');
// 	// while (i < 10)
// 	// 	printf("%s;\n", tab[i++]);
// }