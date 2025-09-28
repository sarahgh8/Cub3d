/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wshannak <wshannak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:23:52 by wshannak          #+#    #+#             */
/*   Updated: 2024/09/11 19:39:06 by wshannak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_counter(int n)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_zero(void)
{
	char	*str;

	str = malloc(2);
	if (str == NULL)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

static char	*spliter(int len, int n, char *str, int neg)
{
	str[len--] = '\0';
	if (n == 0)
		str[len--] = '0';
	while (n > 0)
	{
		str[len--] = n % 10 + '0';
		n /= 10;
	}
	if (neg)
		str[len] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	char	*str;

	len = 0;
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_zero());
	if (n < 0)
	{
		neg = 1;
		n = -n;
		len++;
	}
	len = len + ft_counter(n);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	return (spliter(len, n, str, neg));
}
