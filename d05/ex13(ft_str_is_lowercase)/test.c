/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


#include <unistd.h>

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


void	ft_putchar(char c)			/* функция вывода символа */
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)		/* функция печати строки */
{
	while (*str)
		ft_putchar(*str++);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)	/* функция проверки строки на наличие только букв нижнего регистра */
{
	int	i;							/* Обьявляем целочисленную переменную для счетчика */

	i = 0;							/* Инициализируем переменную для счетчика нулем чтобы начать с нулевой ячейки массива*/
	while (str[i])					/* Если эта ячейка массива не хранит символ конца массива то запускаем цикл */
	{
		if (!((str[i] >= 'a') && (str[i] <= 'z')))	/* если встретился любой символ не являющийся буквой в нижнем регистре */
			return (0);								/* то завершаем функцию и возвращаем 0 */
		i++;						/* Иначе увеличиваем счетчик для перехода к след ячейке массива */
	}
	return (1);						/* Если цикл завершился значит в строке только буквы нижнего регистра - мы завершаем функцию и возвращаем 1 */
}

int 	main(void)
{
	char	r[] = {"sdsdf"};											/* создадим строку(массив символов) для теста */
	
    if ((ft_str_is_lowercase(r)) == 1)									/* передадим в функцию адресс строки и проверим строку(массив символов) */
		ft_putstr("строка содержит только строчные буквенные символы");	/* если в строке только буквы нижнего регистра то выведем этот текст */
	else
		ft_putstr("строка содержит и другие символы");					/* если в строке есть другие символы то выведем этот текст */
	return 0;
}
