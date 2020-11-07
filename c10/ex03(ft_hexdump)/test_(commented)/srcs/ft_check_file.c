/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/29 18:50:29 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_lib.h"

int		ft_check_file(char *argv)
{
	int		fd;								/* Обьявляем переменную которая будет хранить идентификатор файлового потока(дескриптор файла) нашего файла.
											** (Файловый дескриптор — это неотрицательное число, которое является идентификатором
											** какого-либо потока ввода-вывода, который может быть связан с файлами, каталогами или сокетами.
											** Сами дескрипторы файлов привязаны к идентификатору процесса. Самые известные файловые дескрипторы - это 0, 1, 2.
											** Нулю соответствует STDIN(стандартный поток ввода), еденице соответствует STDOUT(стандартный поток вывода),
											** а двойке соответствует STDERR(стандартный поток ошибок). У каждой програмы есть все три этих системных потока.) */
	char	buffer;							/* Обьявляем переменную для временного хранения данных при чтениии из файла */
	int		result;							/* Обьявляем переменную для отображения состояния проверки файла */
	int		r;								/* Обьявляем переменную для получения размера считанных из файла в буфер данных или же для хранения ошибок чтения файла */

	result = 0;								/* Инициализируем нулем переменную для подсчета количества найденых в файле байт данных */
	if ((fd = open(argv, O_RDONLY)) == -1)	/* Отправляем в функцию 'open' строку с именем и путем до файла, а также флаг 'O_RDONLY'.
											** Благодраря пути до файла и флагу 'O_RDONLY' функция сразу из условия откроет поток для чтения из файла 
											** и вернет нам идентификатор этого потока (файловый дескриптор) который мы сохраним в 'fd'.
											** Как только мы получили результат работы функции мы сразу проверияем все ли прошло хорошо, сверяя
											** содержимое переменной 'fd', в котором должен быть дескриптор файла.
											** ЕСЛИ что то пойшло не так и функция может открыть поток до файла, то она вернет номер ошибки '-1' */
	{
		ft_display_custom_error(errno, argv);/* Если функция вернула '-1', мы запускаем функцию для печати подробной ошибки, отправляя ей в
											** аргументы содержимое переменной 'errno' хранящей номер последней ошибки программы и адрес
											** строки, с которой была связана ошибка, а после игнорирует остальной код и завершаем функцию */
	}
	else									/* ЕСЛИ все прошло хорошо и мы получили в переменную 'fd' идентификатор потока (файловый дескриптор) 
											** то мы запускаем код, который считает из файла данные и напечатает их через стандартный поток вывода */
	{
		if ((r = read(fd, &buffer, 1)))		/* Запускаем условие, функции 'read', сразу из условия которая, считает однин байт данныхдля проверки читабельности
											** файла используя дескриптор файла(идентификатор потока к файлу), адресс перменной 'buffer' и размер буфера.
											** При неудачном чтении  файла мы завершим функцию и вернем ноль, в знак того что чтение файла не удалось */
		{
			if (r == -1)					/* Проверяем число которое нам вернула функция 'read'. Если это число равно '-1' значит у нас произошла ошибка чтения */
				ft_display_custom_error(errno, argv);	/* Если функция вернула '-1', мы запускаем функцию для печати подробной ошибки, отправляя ей в
											** аргументы содержимое переменной 'errno' хранящей номер последней ошибки программы и адрес
											** строки, с которой была связана ошибка, а после игнорирует остальной код и завершаем функцию */
			else
				result = 1;
		}
		if (close(fd) == -1)				/* Закрываем файловый поток с помощью функции 'close' и дескриптора файла(идентификатора файлового потока).
											** И проверяем число которое нам вернула функция. Если это число равно '-1' значит у нас произошла ошибка 
											** закрытия файлового потока */
			ft_display_custom_error(errno, argv);	/* Если функция 'close' вернула '-1', то мы запускаем функцию для печати подробной ошибки, отправляя ей в
											** аргументы содержимое переменной 'errno' хранящей номер последней ошибки программы и адрес
											** строки, с которой была связана ошибка, а после игнорирует остальной код и завершаем функцию */
		
	}
	return (result);						/* Завершаем функцию и возвращаем полученный нами размер файла */
}