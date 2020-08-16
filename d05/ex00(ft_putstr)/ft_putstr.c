/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* - Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую */

/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Create a function that displays a string of characters on the standard output.
Создайте функцию, которая отображает строку символов в стандартном выводе.


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


/* ************************************************************************** */

void    ft_putchar(char c);

/* ************************************************************************** */

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
}

/* ************************************************************************** */

void	ft_putstr(char *str)		
{
	int	i;						

	i = 0;						
	while (str[i] != '\0')		
	{
		ft_putchar(str[i]);		
		i++;					
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putstr(char *str)
{
	while (*str)
		ft_putchar(*str++);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}




/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void		ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putstr(char *str)
{
	int con;
	int n;

	con = 1;
	n = 0;
	while (con)
	{
		if (str[n] == '\0')
		{
			con = 0;
		}
		else
		{
			ft_putchar(str[n]);
		}
		n++;
	}
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
