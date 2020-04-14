/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Create a function that returns 1 if the string given as a parameter contains 
only printable characters, and 0 if it contains any other character.
Создайте функцию, которая возвращает 1, если строка, заданная в качестве 
параметра, содержит только печатные символы, и 0, если она содержит любой 
другой символ.


It should return 1 if str is empty.
Функция должна возвращать 1, если str пуст(не содержит др символов).


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= ' ') && (str[i] <= '~')))
			return (0);
		i++;
	}
	return (1);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */



int	iss_printable(char c)
{
	if ((c >= 32) && (c <= 126))
		return (1);
	return (0);
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(iss_printable(str[i])))
			return (0);
		i++;
	}
	return (1);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int	i;
	int	b;

	b = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= ' ' && str[i] <= '~')
			b = 1;
		else
			return (0);
		i++;
	}
	return (b);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


int		ft_str_is_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 126))
			return (0);
		i++;
	}
	return (1);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
