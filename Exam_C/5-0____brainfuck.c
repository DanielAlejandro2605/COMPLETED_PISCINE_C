/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brainfuck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <RTFM@42.fr>                          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : brainfuck
Expected files   : *.c, *.h
Allowed functions: write, malloc, free
--------------------------------------------------------------------------------

Напишите программу интерпретатора "Brainfuck".
Исходный код будет указан в качестве первого параметра.
Код всегда будет действительным, не более 4096 операций.
"Brainfuck" - это минималистский язык. Он состоит из массива байтов(в нашем случае,
скажем, 2048 байтов), инициализированных нулем, и указателя на его первый байт.

Каждый оператор состоит из одного символа:
- '>' увеличить указатель;
- «<» уменьшить указатель;
- '+' увеличить указанный байт;
- '-' уменьшить указанный байт;
- '.' вывести указанный байт на стандартный вывод;
- '[' перейти к соответствующему ']', если указанный байт равен 0 (при запуске);
- ']' перейти к соответствующему '[', если указанный байт не равен 0 (в конце).

Любой другой персонаж - это комментарий.

Примеры:


$>./brainfuck "++++++++++[>+++++++>++++++++++>+++>+<<<<-]
>++.>+.+++++++..+++.>++.<<+++++++++++++++.>.+++.------.--------.>+.>." | cat -e
Hello World!$
$>./brainfuck "+++++[>++++[>++++H>+++++i<<-]>>>++\n<<<<-]>>--------.>+++++.>." | cat -e
Hi$
$>./brainfuck | cat -e
$


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>

#define BUFF_SIZE 2048

int			main(int argc, const char *argv[])
{
	int		i;
	int		loop;
	char	*pointer;

	if (argc == 2)
	{
		i = 0;
		if (!(pointer = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
			return (-1);
		while (i <= BUFF_SIZE)
			pointer[i++] = '\0';
		i = 0;
		while (argv[1][i])
		{
			argv[1][i] == '<' ? pointer += 1 : pointer;
			argv[1][i] == '>' ? pointer -= 1 : pointer;
			argv[1][i] == '+' ? *pointer += 1 : *pointer;
			argv[1][i] == '-' ? *pointer -= 1 : *pointer;
			if (argv[1][i] == '.')
				write(1, &*pointer, 1);
			if (argv[1][i] == '[' && !*pointer)
			{
				loop = 1;
				while (loop)
				{
					i += 1;
					argv[1][i] == '[' ? loop += 1 : loop;
					argv[1][i] == ']' ? loop -= 1 : loop;
				}
			}
			if (argv[1][i] == ']' && *pointer)
			{
				loop = 1;
				while (loop)
				{
					i -= 1;
					argv[1][i] == '[' ? loop -= 1 : loop;
					argv[1][i] == ']' ? loop += 1 : loop;
				}
			}
			i += 1;
		}
	}
	else
		write(1, "\n", 1);
	return (0);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		find_next(char *str)
{
	int		count;
	int		i;

	i = 1;
	count = 0;
	while (str[i])
	{
		if (str[i] == '[')
			count++;
		else if (str[i] == ']')
		{
			if (count == 0)
				return (i);
			else
				count--;
		}
		i++;
	}
	return (0);
}

int		find_previous(char *str)
{
	int		count;
	int		i;

	i = -1;
	count = 0;
	while (str[i])
	{
		if (str[i] == ']')
			count++;
		else if (str[i] == '[')
		{
			if (count == 0)
				return (i);
			else
				count--;
		}
		i--;
	}
	return (0);
}

void	brainfuck(char *str)
{
	char	ptr[2048];
	int		i;
	int		j;

	j = 0;
	while (j < 2048)
		ptr[j++] = '\0';
	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '>')
			j++;
		else if (str[i] == '<')
			j--;
		else if (str[i] == '+')
			ptr[j]++;
		else if (str[i] == '-')
			ptr[j]--;
		else if (str[i] == '.')
			ft_putchar(ptr[j]);
		if (str[i] == '[' && ptr[j] == 0)
			i += find_next(str + i);
		else if (str[i] == ']' && ptr[j] != 0)
			i += find_previous(str + i);
		else
			i++;
	}
}

int		main(int ac, char **av)
{
	if (ac != 2)
		ft_putchar('\n');
	else
		brainfuck(av[1]);
	return (0);
}



