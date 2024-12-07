/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_verify_input.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaisne <achaisne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:16:42 by achaisne          #+#    #+#             */
/*   Updated: 2024/12/07 17:10:42 by achaisne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_integer(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	if (s[i] == '-')
	{
		i++;
		if (s[i] == '\0')
			return (0);
	}
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	if (s[0] == '-' && ((i > 11)
			|| (i == 11 && ft_strncmp(s, "-2147483648", 11) > 0)))
		return (0);
	else if (s[0] != '-' && ((i > 10)
			|| (i == 10 && ft_strncmp(s, "2147483647", 10) > 0)))
		return (0);
	return (1);
}

int	is_integers(char **s, int size)
{
	int	i;
	int	j;

	if (!s)
		return (0);
	j = 0;
	while (j < size)
	{
		if (!is_integer(s[j]))
			return (0);
		j++;
	}
	return (1);
}

int	is_double(char **s, int size)
{
	int	i;
	int	j;

	if (!s)
		return (0);
	j = 0;
	while (j < size - 1)
	{
		i = j + 1;
		while (i < size)
		{
			if (atoi(s[j]) == atoi(s[i]))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

int	is_verified_input(char **s, int size)
{
	if (!s)
		return (0);
	if (!is_integers(s, size) || is_double(s, size))
		return (0);
	return (1);
}
