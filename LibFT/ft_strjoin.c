/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chon <chon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:41:10 by chon              #+#    #+#             */
/*   Updated: 2023/12/05 14:49:29 by chon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	str = malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	ft_memcpy(str, s1, ft_strlen(s1));
	i += ft_strlen(s1);
	ft_memcpy(str + i, s2, ft_strlen(s2));
	i += ft_strlen(s2);
	str[i] = '\0';
	return (str);
}
