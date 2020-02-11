/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
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


int		ft_putchar(char c)
{
	write(1, &c, 1);

	return (0);
}

/* Раш это функция которая рисует квадрат из нужных нам символов за счет
 * поочередной печати  шапки, сердцевины и основания.  то есть программма
 * берет 2 строки которые мы написали в функции rush и печатает их тогда
 * когда мы ей скажем.
 * 
 * Программма берет 2 именно строки по тому что шапка и основание идентичны. 
 * По этому мы используем один и тот же набро символов для печати шапки и 
 * основания а для середины другой набор символо */

/* Например у нас вызов rush(5,4); */
/* значит мы должны напечатать 4 строки */
/* А каждая строка будет шириной в 5 символов */
/* 
  ВОТ ТАК 

  строка №1   o---o    шапка       (5 символов)           
  строка №2   |   |    сердцевина  (5 символов)
  строка №3   |   |    сердцевина  (5 символов)
  строка №4   o---o    основание   (5 символов)

  Итого: 4 строки 

*/

/* Вычислять то какую строку сейчас нужно печатать(шапку или середину) будет функция rush */

/* А вычислять какой символ и когда ставить будет функция ft_print_line */

/* для этого мы инициаизируем счетчик и будем его сравнивать с переменной 'y' которая задает количество строк(высоту печати); */

/*

    в                                            ширина
    ы    o---o                                   o---o    шапки
    с    |   |                                   |   |    
    о    |   |                                   |   |    
    т    o---o                                   o---o    основания
    а

*/




/* ШАГ 2 */

/* Эта функция печатает строку, выбирая в какой момент напечатать крайний символ, а в какой момент промежуточный символ, чтобы получилость вот так "o---o" если сейчас 
 * передали в аргументы именно эти символы и такую длинну. Или так "|   |" если сейчас передали в аргументы именно эти символы и такую длинну*/

void	ft_print_line(int width, char begin_and_end_symbol, char middle_symbol) /* принимаем (x - длинна в символах,  крайний символ,  промежуточный символ) */
{
	int		i;									/* для подсчета того какой сейчас перед нами символ первый последний или промежуточный обьявляем счетчик */

	i = 1;										/* иницилизируем его единицей чтобы начать печать с первого символа */
	while(i <= width)							
	{
		if(i == 1 || i == width)				/* Проверяем является ли печатаемый символ первым или последним */ 
			ft_putchar(begin_and_end_symbol);	/* Если i равен 1 или i равен width значит сейчас надо печатать крайний символ */

		else									/* Если любое из прошлых условий ложно значит что перед нами середина */
			ft_putchar(middle_symbol);			/* Значит Печатаем середину */
		i++;
	}
}




/* ШАГ 1 */

/* 'x' - это ширина печатаемой шапки, сердцевины и основания в ширину задаваемое колчеством символо */
/* 'y' - это высота задаваемая с помощью количества строк строк */
void	rush(int x, int y)			
{
	int		i;								/* для подсчета того какую строку печатать нужно( первую среднюю или последню ) обьявляем счетчик */

	i = 1;									/* иницилизируем его единицей чтобы начать печать с первой строки */
	while(i <= y)							/* проверяем не вышел ли счетчик за край нужного нам диапазона если все норм запускаем цикл */
	{
		if (i == 1 || i == y)				/* Проверяем является ли печатаемая строка первой или последней */ 
			ft_print_line(x, 'o', '-');		/* Если любое из этих условий правдиво то печатаем строку "шапка/основание" */
											/* передаем в функцию (x - длинна в символах,  крайний символ,  промежуточный символ)*/
											/* И в этой функции формируется строка в зависимости от размера 'x' */

		else								/* Если любое из прошлых условий не сработало значит что перед нами середина */
			ft_print_line(x, '|', ' ');		/* Значит Печатаем середину */ /* передаем в функцию (x - длинна в символах,  крайний символ,  промежуточный символ) */
											/* И в этой функции формируется строка в зависимости от размера 'x' */

		ft_putchar('\n');					/* в конце выводим перенос строки чтобы начать с новой строки следующую печать */
		i++;								/* увеличиваем счетчик на единицу указывая на след позицию */
	}
}

/* В итоге мы просто выборочно мечатаем нужную строку */ 

int		main(void)
{
	rush(5, 4);
	
	return (0);
}

