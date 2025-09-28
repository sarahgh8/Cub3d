/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshannak <wshannak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 23:12:54 by wshannak          #+#    #+#             */
/*   Updated: 2024/09/11 03:21:46 by wshannak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s1, ft_strlen(s1));
	new[ft_strlen(s1)] = '\0';
	ft_strlcat(new, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (new);
}
