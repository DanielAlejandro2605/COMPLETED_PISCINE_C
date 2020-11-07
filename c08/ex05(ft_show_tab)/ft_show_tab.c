/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/19 13:37:41 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex05/
**  Файлы для сдачи: ft_show_tab.c	
**  Разрешенные функции: write
**
** ************************************************************************** **
**
** 
**  - Создайте функцию, которая отображает содержимое массива, созданного 
**  предыдущей функцией.
**  
**  
**  -  Ваша функция должна быть объявлена ​​следующим образом :
--------------------------------------------------------------------------------

                                    void	ft_show_tab(structs_stock_str *par);

--------------------------------------------------------------------------------
**
**  - Структура будет такой же, как и в предыдущем упражнении, и будет определена
**  в файле "ft_stock_str.h" .
**
**  - Для каждого элемента  массива экземпляров структуры мы будем отображать:
**
**      * строку, за которой следует символ перехода новую строку('\n'); 
**      * размер аргумента, за которой следует символ перехода новую строку('\n'); 
**      * копию строки, за которой следует символ перехода новую строку('\n');.
** 
** 
**  - Мы проверим вашу функцию с помощью нашего ft_strs_to_tab(предыдущее упражнение).
**  Примите соответствующие меры, cделайте так, чтобы это работало!
**
**
** ************************************************************************** **
**
**  Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую
**
** ************************************************************************** */
/* ************************************************************************** */


#include "ft_stock_str.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putnbr(int nb)
{
	int	temp;
	int	size;

	size = 1;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb == -2147483648)
	{	
		ft_putchar('2');
		nb = 147483648;
	}
	temp = nb;
	while ((temp /= 10) > 0)
		size *= 10;
	temp = nb;
	while (size)
	{
		ft_putchar((char)((temp / size)) + 48);
		temp %= size;
		size /= 10;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	int	j;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}



/* ************************************************************************** */
/* ************************************************************************** */