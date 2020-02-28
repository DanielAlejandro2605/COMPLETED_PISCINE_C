/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <evgenkarlson@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by exam              #+#    #+#             */
/*   Created: 2020/02/14 12:33:14 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


Assignment name  : wdmatch
Expected files   : wdmatch.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program that takes two strings and checks whether it's possible to
write the first string with characters from the second string, while respecting
the order in which these characters appear in the second string.
Напишите программу, которая принимает две строки и проверяет, можно ли написать 
первую строку с символами из второй строки, соблюдая порядок, в котором эти символы
появляются во второй строке.

If it's possible, the program displays the string, followed by a \n, otherwise
it simply displays a \n.
Если это возможно, программа отображает строку, за которой следует \ n, в противном 
случае просто отображается \ n.

If the number of arguments is not 2, the program displays a \n.
Если количество аргументов не равно 2, программа отображает \ n.

Examples:
Примеры:


$>./wdmatch "faya" "fgvvfdxcacpolhyghbreda" | cat -e
faya$
$>./wdmatch "faya" "fgvvfdxcacpolhyghbred" | cat -e
$
$>./wdmatch "quarante deux" "qfqfsudf arzgsayns tsregfdgs sjytdekuoixq " | cat -e
quarante deux$
$>./wdmatch "error" rrerrrfiiljdfxjyuifrrvcoojh | cat -e
$
$>./wdmatch | cat -e
$


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


#include <unistd.h>


void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_wdmatch(char *s1, char *s2)	/* принимаем адреса двух строк */
{
	int		i;							/* Обьявляем счетчик i для первой строки */
	int		j;							/* Обьявляем счетчик j для второй строки */

	i = 0;								/* Инициализируем счетчик i нулем */
	j = 0;								/* Инициализируем счетчик j нулем */
	while (s2[j] && i < ft_strlen(s1))	/* запускаем цикл работающий до тех пор пока счетчик i 
										 * не дойдет до конца первой строки или пока счетчик j
										 * не дойдем до конца второй строки */
	{
		if (s2[j] == s1[i])				/* если символ из второй строки такой же как и символ из
										 * первой строки то переходим к след символу первой строки
										 * и сравниваем его с символом второй строки  и так далее
										 * пока не дойдем до конца первой строки */
			i++;						/* увеличение счетчика для перехода к след ячейке первой строки */
		j++;							/* увеличение счетчика для перехода к след ячейке второй строки */
	}
	if (i == ft_strlen(s1))				/* если дошли до конца первой строки значит каждый из символов
										 * присутствует во второй строке в том же порядке хоть и не последовательно */
		ft_putstr(s1);					/* значит печатаем первую строку */
}

int main(int argc, char **argv)
{
	if (argc == 3)
		ft_wdmatch(argv[1],argv[2]);
	write(1, "\n", 1);
	return (0);
}



/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */


#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}

	int i = 0;
	int j = 0;

	while (argv[2][j] != '\0' && i < ft_strlen(argv[1]))
	{
		if (argv[2][j] == argv[1][i])
			i++;
		j++;
	}
	if (i == ft_strlen(argv[1]))
	{
		ft_putstr(argv[1]);
		write(1, "\n", 1);
	}
	else
		write(1, "\n", 1);
	return (0);
}



/* ************************************************************************** */
/* ********************************_OR_THAT_:)******************************* */
/* ************************************************************************** */



#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}

int		main(int argc, char *argv[])
{
	int		i;
	int		j;

	if (argc == 3)
	{
		i = 0;
		j = 0;
		while (argv[2][j])
			if (argv[2][j++] == argv[1][i])
				i += 1;
		if (!argv[1][i])
			ft_putstr(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
