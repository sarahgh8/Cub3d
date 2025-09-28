/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshannak <wshannak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 20:03:22 by wshannak          #+#    #+#             */
/*   Updated: 2024/09/11 03:22:36 by wshannak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	copy_len;

	copy_len = size - 1;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (src_len < copy_len)
	{
		copy_len = src_len;
	}
	ft_memcpy(dst, src, copy_len);
	dst[copy_len] = '\0';
	return (ft_strlen(src));
}
