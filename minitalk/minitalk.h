/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naherbal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 17:52:56 by naherbal          #+#    #+#             */
/*   Updated: 2023/09/28 13:19:46 by naherbal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

int		ft_strlen(char *str);
char	**create_tab(char *str);
void	ft_strrev(char *str);
char	*ft_itoa(int n);
char	*ft_xneg(char *dest, char *src);
int		ft_count(int nbr);
char	*ft_convert_base(char *nbr);
void	convert_to_base(int nbr, char *str);
void	ft_putnbr(int n);

#endif
