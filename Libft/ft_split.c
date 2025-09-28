/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshannak <wshannak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 03:24:30 by wshannak          #+#    #+#             */
/*   Updated: 2024/09/14 20:44:39 by wshannak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(char const *s, char c)
{
	int	counter;
	int	i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			counter++;
		i++;
	}
	return (counter);
}

static void	*ft_free(char **arr, int j)
{
	while (j--)
	{
		free(arr[j]);
	}
	free(arr);
	return (NULL);
}

static char	**ft_substring(char const *s, char c, char **arr)
{
	int	start;
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			arr[j] = ft_substr(s, start, i - start);
			if (arr[j++] == NULL)
				return (ft_free(arr, j));
		}
		else
			i++;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	int		counter;
	char	**arr;

	counter = ft_counter(s, c);
	arr = (char **)ft_calloc(counter + 1, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	return (ft_substring(s, c, arr));
}
