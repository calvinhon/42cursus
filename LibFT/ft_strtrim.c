/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:41:31 by chon              #+#    #+#             */
/*   Updated: 2023/11/16 14:45:34 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		count;
	int		i;
	int		j;
	char	*str;

	count = 0;
	i = 0;
	j = 0;
	while (s1[i])
		if (ft_strchr(set, s1[i++]) == NULL)
			count++;
	i = 0;
	str = malloc(count * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]) == NULL)
			str[j++] = *(s1 + i);
		i++;
	}
	str[j] = '\0';
	return (str);
}

// int main(void)
// {
//     printf("%s;\n", ft_strtrim("", ""));
// }