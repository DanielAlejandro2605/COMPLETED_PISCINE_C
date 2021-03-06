/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/19 13:37:27 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex04/
**  Файлы для сдачи: ft_strs_to_tab.c
**  Разрешенные функции: malloc, free
**
** ************************************************************************** **
**
** 
**  - Создайте функцию, которая принимает в качестве аргумента массив строк и
**  размер этого массива строк.
**  
**  
**  -  Ваша функция должна быть объявлена ​​следующим образом :
--------------------------------------------------------------------------------

                      struct s_stock_par	*ft_strs_to_tab(int ac, char **av);

--------------------------------------------------------------------------------
**
**  - Он превратит каждый элемент массива строк "av" в структуру.
**
**  
**  - Структура будет определена в файле "ft_stock_str.h", который мы предоставим,
**  с таким же содержимым ка тут:
--------------------------------------------------------------------------------

    typedef	struct		s_stock_str
    {
        int		size;
        char	*str;
        char	*copy;
    }					t_stock_str;

--------------------------------------------------------------------------------
**      * 'size' - это длина строки. 
** 
**      * 'str' - указатель хранящий начало строки.
** 
**      * 'copy' - указатель хранящий начало копии строки.
** 
** 
**  - Функция должна соблюдать порядок строк массива 'av'.
** 
**  - Возвращаемый массив должен быть размещен в памяти, а его последний 
**  элемент "str" должен быть установлен в '0', это будет отмечать конец массива.
** 
**  - При возникновении ошибки он должен вернуть нулевой указатель(NULL).
**
**  - Мы протестируем вашу функцию с помощью нашего 'ft_show_tab' (следующее 
**  упражнение). Примите соответствующие меры, cделайте так, чтобы это работало!
**
**
** ************************************************************************** **
**
**  Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую
**
** ************************************************************************** */
/* ************************************************************************** */


#include "ft_stock_par.h"
#include <stdlib.h>

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_par	*ret;

	if ((ret = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1))) == ((void *)0))
		return ((void *)0);
	i = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			j++;
		ret[i].size_param = j;
		ret[i].str = av[i];
		if((ret[i].copy = (char *)malloc(sizeof(char) * (ret[i].size_param + 1))) == ((void *)0))
			return ((void *)0);
		j = 0;
		while (j < ret[i].size_param)
		{
			ret[i].copy[j] = av[i][j];
			j++;
		}
		ret[i].copy[j] = '\0';
		ret[i].tab = ft_split_whitespaces(av[i]);
		i++;
	}
	ret[i].str = 0;
	return (ret);
}


/* ************************************************************************** */
/* ************************************************************************** */


#include "ft_stock_par.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int i;

	i = 0;
	while(*str++)
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	int				i;
	char			*dst;

	i = 0;
	while (src[i])
		i++;
	if ((dst = (char *)malloc(sizeof(char) * (i + 1))) == ((void *)0))
		return ((void *)0);
	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int				i;
	t_stock_par		*stk;

	if ((stk = (t_stock_par *)malloc(sizeof(t_stock_par) * (ac + 1))) == ((void *)0))
		return ((void *)0);
	i = 0;
	while (i < ac)
	{
		stk[i].size_param = ft_strlen(av[i]);
		stk[i].str = av[i];
		stk[i].copy = ft_strdup(av[i]);
		i++;
	}
	stk[i].str = 0;
	return (stk);
}


/* ************************************************************************** */
/* ************************************************************************** */
