/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshannak <wshannak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 21:14:15 by wshannak          #+#    #+#             */
/*   Updated: 2024/09/01 20:01:30 by wshannak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if (src > dest)
		ft_memcpy(dest, src, n);
	else
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	return (dest);
}

// void    *ft_memmove(void *dest, const void *src, size_t n)
// {
//         unsigned char   *holder;

//         holder = malloc(n);
//         ft_memcpy(holder, src, n);
//         ft_memcpy(dest, holder, n);
//         free(holder);
//         return (dest);
// }
