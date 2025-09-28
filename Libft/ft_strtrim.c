/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshannak <wshannak@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:23:19 by wshannak          #+#    #+#             */
/*   Updated: 2024/09/04 22:48:16 by wshannak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	b;
	size_t	e;

	b = 0;
	e = ft_strlen(s1);
	while (b < e && ft_strchr((char *)set, (char)s1[b]))
	{
		b++;
	}
	while (e > b && ft_strchr((char *)set, (char)s1[e - 1]))
		e--;
	return (ft_substr(s1, b, e - b));
}
