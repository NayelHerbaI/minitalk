/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:04:18 by naherbal          #+#    #+#             */
/*   Updated: 2024/01/08 16:20:27 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	fct_add_zero(int add_zero, int pid) // magic
{
	while (add_zero > 0)
	{
		kill(pid, SIGUSR1);
		usleep(100);
		add_zero--;
	}
	return (add_zero);
}

void	fct_mess_len(char **tab, int pid, int k, int l) //magic
{
	if (tab[k][l] == '0')
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
	usleep(100);
}

void	send_signal(char **tab, int pid) // magic again
{
	int	i;
	int	k;
	int	l;
	int	mess_len;
	int	add_zero;

	k = 0;
	i = 8;
	while (tab[k])
	{
		l = 0;
		mess_len = ft_strlen(tab[k]);
		add_zero = 8 - mess_len;
		fct_add_zero(add_zero, pid);
		while (mess_len > 0)
		{
			fct_mess_len(tab, pid, k, l);
			l++;
			mess_len--;
		}
		k++;
	}
}

char	**create_tab(char *str) // creating my tab where I put all the binary numbers
{
	char	**tab;
	int		i;

	i = 0;
	tab = malloc(10000);
	while (str[i])
	{
		tab[i] = ft_convert_base(ft_itoa(str[i]));
		printf("tab[%d] == %s\n", i, tab[i]);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

int	main(int ac, char **av)
{
	char	**tab;
	int		pid;
	int		i;

	i = 0;
	if (ac != 3)
		return (write(1, "Invalid instructions\n", 21));
	pid = atoi(av[1]); // get the PID
	tab = create_tab(av[2]); // create an array to grab the sentence that i want to write
	send_signal(tab, atoi(av[1]));// sending signals to the server so it can write the message
	while (tab[i]) // just freeing my tab
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
