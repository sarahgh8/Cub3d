/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshannak <wshannak@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 23:12:12 by wshannak          #+#    #+#             */
/*   Updated: 2024/09/03 18:37:45 by wshannak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	ptr1;

	ptr = (unsigned char *)s;
	ptr1 = (unsigned char)c;
	while (n--)
	{
		if (*ptr == ptr1)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
