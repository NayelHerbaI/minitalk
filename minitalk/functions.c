/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:50:57 by naherbal          #+#    #+#             */
/*   Updated: 2023/09/28 13:23:32 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	convert_to_base(int nbr, char *str)
{
	int	base_len;
	int	i;

	i = 0;
	base_len = 2;
	while (nbr > 0)
	{
		str[i] = nbr % base_len + 48;
		i++;
		nbr = nbr / base_len;
	}
	str[i] = '\0';
	ft_strrev(str);
}

char	*ft_convert_base(char *nbr)
{
	char	*str;

	str = malloc(sizeof(char) * 1000);
	convert_to_base(atoi(nbr), str);
	return (str);
}

int	ft_count(int nbr)
{
	int	digit;

	digit = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= -1;
		digit++;
	}
	while (nbr > 0)
	{
		digit++;
		nbr /= 10;
	}
	return (digit);
}

char	*ft_xneg(char *dest, char *src)
{
	int	i;

	dest = malloc(12 * sizeof(char));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < 11)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		digit;
	int		nb;

	str = NULL;
	if (n == -2147483648)
		return (ft_xneg(str, "-2147483648"));
	nb = n;
	digit = ft_count(nb);
	if (n < 0)
		nb *= -1;
	str = malloc((digit + 1) * sizeof(char));
	if (str == NULL)
		return (0);
	str[digit] = '\0';
	while (digit > 0)
	{
		str[digit - 1] = (nb % 10) + 48;
		nb /= 10;
		digit--;
	}
	if (n < 0)
		str[digit] = '-';
	return (str);
}
