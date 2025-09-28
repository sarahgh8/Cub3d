/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshannak <wshannak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:11:51 by wshannak          #+#    #+#             */
/*   Updated: 2024/09/11 03:23:40 by wshannak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	substr_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	substr_len = ft_strlen(s) - start;
	if (len < substr_len)
		substr_len = len;
	new = ft_calloc(substr_len + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	ft_memcpy(new, s + start, substr_len);
	return (new);
}
