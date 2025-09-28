/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshannak <wshannak@student.42amman.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:00:06 by wshannak          #+#    #+#             */
/*   Updated: 2024/09/03 22:10:00 by wshannak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*new;

	new = ft_calloc(1, ft_strlen(s) + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s, ft_strlen(s) + 1);
	return (new);
}
