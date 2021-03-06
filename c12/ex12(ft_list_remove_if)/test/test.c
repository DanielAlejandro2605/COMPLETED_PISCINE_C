/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/17 01:22:48 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************************************************ */
/*                                                                                                              */
/*              Команда для компиляции кода и одновременного запуска программы с аргументами:                   */
/*                                                                                                              */
/*   gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out 'one' 'two' 'three' 'four' 'five' 'six'    */
/*                                                                                                              */
/* ************************************************************************************************************ */

#include <unistd.h>						/* Подключаем библиотеку содержащую функцию "write" */
#include <stdlib.h>						/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) и функцию для
										** подсчета размера (sizeof) и функцию(free) для освобождения выделеной памяти */
#include "ft_list.h"					/* Подключаем заголовочный файл содержащий нужную нам структуру */


/* ************************************************************************** */

void		ft_putchar(char c)			/* Функция печати символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */

void		ft_putstr(char *str)		/* Функция печатает строку */
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
}

/* ************************************************************************** */

void		ft_put_list(t_list *list)	/* Функция печати связанных между собой экземпляров структуры типа 't_list' */
{
	while (list)
	{
		ft_putstr((char *)list->data);
		ft_putchar(' ');
		list = list->next;
	}
}

/* ************************************************************************** */

t_list		*ft_create_elem(void *data)	/* Функция создает экземпляр структуры типа t_list, заполняет его данными - адрес из указателя data
										** в первый элемент экземпляра структуры, нулевой адрес во второй элемент экземпляра структуры. И в 
										** конце функция его возвращает адрес созданого экземпляра структуры типа t_list*/
{
	t_list	*tmp;						/* Обьявляем указатель структуры типа t_list для хранения там адреса экземпляра структуры типа t_list */

	if ((tmp = (t_list *)malloc(sizeof(t_list))) == ((void *)0))/* Инициализируем указатель, сохраняя туда адрес выделеной под экземпляр памяти */
		return ((void *)0);										/* Если память не выделилась то завершаем функцию и возвращаем нулевой указатель */
	tmp->next = ((void *)0);			/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры нулевой указатель */
	tmp->data = data;					/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры адрес принятого
										** в аргументах элемента неизвестного типа */
	return (tmp);						/* Завершаем функцию и возвращаем адрес созданного нами экземпляра структуры типа t_list */
}

/* ************************************************************************** */

int			ft_strcmp(char *s1, char *s2)	/* Функция сравнивает две строки и возвращает разницу между ними */
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	free_fct(void *data)			/* Функция принимает адресс, а потом освобождает память и стирает данные на которые указывае принятый 
										** в аргументах адрес */ 
{
	free(data);							/* Освобождаем память и стираем данные с некоторыми данными на которые ссылается указатель 'data' */
}

/* Функция 'ft_list_remove_if' c помощью другой функций(адрес которой мы получили в аргументах) ищет среди цепи связанных между 
** собой экземпляров структур(адрес которых мы получили в аргументах функции) тот экземпляр структуры, который содержит такие же 
** данные, как и данные, которые содержатся по адресу, который мы получили с аргументами в указатель *data_ref.
** Если функция находит экземпляр структуры с таким же содержимым, как и содержимое по адресу указателя *data_ref, то она и удаляет
** его из этой цепи экземпляр структуры, который содержит такие же данные, как и данные, которые содержатся по адресу,
** который мы получили с аргументами в указатель *data_ref.*/
void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*last;						/* Обьявим указатель для хранения адреса предыдущего экземпляра структуры цепи связанных между собой структур */
	t_list	*current;					/* Обьявим указатель для хранения адреса текущего экземпляра структуры цепи связанных между собой структур */

	last = ((void *)0);					/* Инициализируем нулевым адресом указатель для хранения адреса предыдущего экземпляра структуры */
	current = *begin_list;				/* Инициализируем указатель для хранения адреса текущего экземпляра адресом первого экземпляра структуры, 
										** цепи связанных между собой структур */
	while (current)						/* Запускаем цикл, который будет работать до тех пор пока не дойдет до конца цепи связанных между собой структур */
	{
		if ((*cmp)(current->data, data_ref) == 0)	/* Если содержимое текущей струтуры такое же как и содержимое по адресу указателя *data_ref */
		{
			if (current == *begin_list)				/* Если найденый экземпляр структуры расположен первым в цепи связанных между собой экземпляров */
				*begin_list = current->next;		/* То перезаписываем указатель хранящий адрес текущего экземпляра цепи на адрес следующего экземпляра цепи */ 
			else									/* Если найденый экземпляр структуры не первый в цепи связанных между собой экземпляров */
				last->next = current->next;			/* То перезаписываем указатель хранящий адрес текущего экземпляра цепи на адрес следующего экземпляра цепи */
			last = current;				/* Сохраняем в указателе 'last' адрес экземпляра структуры для освобождения памяти, который мы хотим удалить */
			current = current->next;	/* Перезаписываем указатель 'current', хранящий адрес текущего экзепляра структуры, на адрес следующего экзепляра
										** структуры для работы в след итерации цикла со следующим экзепляром структуры */
										/* А теперь, когда мы избавились от зависимости цепи последующих экземпляров от текущего экземпляра, мы освобождаем
										** память от экземпляра структуры найденого и удаленного нами из списка и данных на которые этот экземпляр ссылается */
			free_fct(last->data);
			free(last);
		}
		else							/* Если содержимое текущей струтуры не такое же как и содержимое по адресу указателя *data_ref */
		{
			last = current;				/* То мы сохраняем адрес текущей структуры в указателе 'last' и */
			current = current->next;	/* Перезаписываем указатель хранящий адрес текущего экзепляра структуры адрес следующего экзепляра структуры
										** для работы в след итерации цикла со следующим экзепляром структуры */
		}
	}
}

/* ************************************************************************** */

char	*ft_clone_str(char *str)
{
	char	*clone;
	int		i;

	i = 0;
	while (*(str + i))
		i++;
	if ((clone = (char *)malloc((sizeof(char) * i) + 1)) == ((void *)0))
		return ((void *)0);
	i = 0;
	while (*(str + i))
	{
		*(clone + i) = *(str + i);
		i++;
	}
	*(clone + i) = '\0';
	return (clone);
}

/* ************************************************************************** */



int			main(int argc, char **argv)
{
	t_list	*list;						/* Обьявим указатель структуры типа t_list для хранения адреса экземпляра структуры типа t_list */
	char	*str;
	
	if (argc == 7)
	{
		str = ft_clone_str(argv[1]);
		list = ft_create_elem(str);		/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
											* данных которыем мы ей отправим) и вернет адресс этого экземпляра структуры типа t_list,
											* который мы сохраним в указателе на экземпляр структуры типа t_list */
		list->next = ft_create_elem(ft_clone_str(argv[2]));/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
											* данных которыем мы ей отправим) и вернет адресс этого экземпляра структуры типа t_list 
											* И сохранит этот адресс в указателе на экземпляр структуры типа t_list, который хранится в одном из элементов 
											* текущего экземпляра структуры, адрес которой хранится в указателе 'list' */

		/* И создадим еще дополнительно несколько экземпляров структуры, которые свяжем между собой и с предыдущим экземпляром */
		list->next->next = ft_create_elem(ft_clone_str(argv[3]));
		list->next->next->next = ft_create_elem(ft_clone_str(argv[4]));
		list->next->next->next->next = ft_create_elem(ft_clone_str(argv[5]));
		list->next->next->next->next->next = ft_create_elem(ft_clone_str(argv[6]));

		ft_put_list(list);					/* Печатаем все связанные между собой структуры */
		ft_putstr("\t: no removed");
		ft_putchar('\n');					/* Печатаем символ переноса строки для кореектного отображения вывода */

		ft_list_remove_if(&list, (void *)"three", &ft_strcmp, &free_fct);	/* Ищем в текущей цепи связанных между собой экземпляров структур нужный 
															** нам экземпляр с такой же строкой внутри и удаляем его из этой цепи */
		ft_put_list(list);					/* Снова пробуем напечатать все связанные между собой структуры */
		ft_putstr("\t\t: removed");
		ft_putchar('\n');					/* Печатаем символ переноса строки для кореектного отображения вывода */
	}

	
	return (0);							/* Завершаем функцию и возвращаем ноль */
}