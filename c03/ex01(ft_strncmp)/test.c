/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/10/08 18:29:27 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */



#include <unistd.h>

/* ************************************************************************** */
/* ************************************************************************** */


void	ft_putchar(char c)			/* функция вывода символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */
/* ************************************************************************** */

void	ft_putstr(char *str)		/* функция печати строки */
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
}

/* ************************************************************************** */
/* ************************************************************************** */

/* Функция побайтно сравнивает коды символов двух строк, на которые указывают аргументы
 * функции. Сравнение продолжается до встречи первого отличающегося символа или пока не
 * будут проверены все символы строк или пока не дойдет до n.
 * Если все символы строк совпали, то возвращается 0. */
int	ft_strncmp(char *s1, char *s2, unsigned int n)	/* Принимаем адреса двух строк для сравнения и количество символов для проверки*/
{
	unsigned int	i;								/* Обьявим счетчик для перемещения по ячейкам */

	i = 0;											/* Инициализируем счетчик нулем чтоб начать с нулевой ячейки */
	while ((s1[i] || s2[i]) && (i < n))				/* Если не встретился символ конца строки в массивах и пока счетчик не дошел до n. */
	{
		if (s1[i] < s2[i])							/* Если строки отличаются и код первого отличающегося символа в
													 * строке s1 меньше кода символа на той же позиции в строке s2.*/
			return (-1);							/* то завершаем функцию и возвращаем отрицательное число */
		if (s1[i] > s2[i])							/* Если строки отличаются и код первого отличающегося символа в
 													 * строке s1 больше кода символа на той же позиции в строке s2. */
			return (1);								/* то завершаем функцию и возвращаем положительное число */
		i++;										/* Если отличий нет то увеличиваем счетчик для перехода к след ячейкам массива */
	}
	return (0);										/* Если отличий не найдено то завершаем функцию и возвращаем 0 */
}

/* ************************************************************************** */
/* ************************************************************************** */

int 	main(void)
{
   /* Сравниваемые строки */
   char str1[] = {"1234567890"};
   char str2[] = {"1234467890"};
  
   /* Сравниваем первые пять символов двух строк */
   if (ft_strncmp(str1, str2, 5) == 0)
      ft_putstr("Первые пять символов строк идентичны");
   else
      ft_putstr("Первые пять символов строк отличаются");

   return (0);
}

