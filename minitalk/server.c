/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:04:27 by naherbal          #+#    #+#             */
/*   Updated: 2023/10/10 17:38:18 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(char c) // you know this one
{
	write(1, &c, 1);
}

void	sig_handler1(int count)  // this is where I convert the signals to binary  and I print it. This is literal magic to me I think you should just do yours
{
	static int	bit;
	static int	c;

	if (count == SIGUSR2)
	{
		c += 1 << (8 - bit);
		bit++;
	}
	else if (count == SIGUSR1)
		bit++;
	if (bit == 8)
	{
		ft_putchar(c / 2);
		bit = 0;
		c = 0;
	}
}

void	ft_putnbr(int n) // you know that
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + 48);
}

int	main(void)
{
	struct sigaction	act1; // create sigaction struct because you need to
	struct sigaction	act2;

	bzero(&act1, sizeof(act1)); // set every variable of act1 and act2 at 0 so nothing goes wrong
	bzero(&act2, sizeof(act2));
	act1.sa_handler = &sig_handler1; // set act1 and act2 signal_handler (sa_handler) to call the function
	act2.sa_handler = &sig_handler1; // void sig_handler(int count) (at the top) whenever you receive a signal
	sigaction(SIGUSR1, &act1, NULL); // look at the man of sigaction i think its to set act1.sa_handler to behave with SIGUSR1 and SIGUSR2 for act2
	sigaction(SIGUSR2, &act2, NULL);
	ft_putnbr(getpid()); // print the PID in the terminal so you can use it for the client
	ft_putchar('\n');
	while (1)
	{
		pause();
	}
	return (0);
}
