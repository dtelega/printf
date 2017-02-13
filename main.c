/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtelega <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:10:20 by dtelega           #+#    #+#             */
/*   Updated: 2017/02/13 15:47:26 by dtelega          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ftprintf.h"

int		main(int ac, char **av)
{
	int		ft_p = 0;
	int		p;
	p = 0;
	char    *s;
	s = "hello world\n";
	long int li;
	li = 9000000000;
		
	if (ac == 0 || av == 0)
		return (0);
	int i;
	i = -1009987;

	ft_p = ft_printf("%-+ #010d\n", 100);
	p =       printf("%-10d\n", 100);
	printf("ft_p = %i\n   p = %i\n", ft_p, p);

/*	

	ft_printf ("1. Вывод простой строки\n");

	ft_printf ("\n2. Вывод целых чисел\n");

	ft_printf ("2.1 Вывод числа 123 с форматом по умолчанию:\n");
	{ int d1=123;
		ft_p = ft_printf ("%d\n",d1);
		p = printf ("%d\n",d1);
		ft_printf("ft_p[%d], p[%d]", ft_p, p);
	}
	ft_printf ("\n2.2 Вывод чисел c выравниванием по правому краю:\n");
	{ int d1=123, d2=42, d3=1543;
		ft_p = ft_printf ("%6d\n%6d\n%6d\n",d1,d2,d3);
		p = printf ("%6d\n%6d\n%6d\n",d1,d2,d3);
		ft_printf("ft_p[%d], p[%d]", ft_p, p);
	}
	ft_printf ("\n2.3 Вывод чисел c выравниванием по левому краю:\n");
	{ int d1=123, d2=42, d3=1543;
		ft_p = ft_printf ("%-6d\n%-6d\n%-6d\n",d1,d2,d3);
		p = printf ("%-6d\n%-6d\n%-6d\n",d1,d2,d3);
		ft_printf("ft_p[%d], p[%d]", ft_p, p);
	}
	ft_printf ("\n2.4 Вывод числа с выводом 0 в недостающих символах:\n");
	{ int d1=-123;
		ft_p = ft_printf ("%06d\n",d1);
		p = printf ("%06d\n",d1);
		ft_printf("ft_p[%d], p[%d]", ft_p, p);
	}
	ft_printf ("\n2.5 Вывод числа 123 с заданной шириной 6 символов:\n");
	{ int d1=123;
		ft_p = ft_printf ("%6d\n",d1);
		p = printf ("%6d\n",d1);
		ft_printf("ft_p[%d], p[%d]", ft_p, p);
	}
	ft_printf ("\n2.6 Вывод числа 123 с заданной точностью 6 символов:\n");
	{ int d1=123;
		ft_p = ft_printf ("%.6d\n",d1);
		p = printf ("%.6d\n",d1);
		ft_printf("ft_p[%d], p[%d]", ft_p, p);
	}
	ft_printf ("\n2.7 Вывод числа типа char:\n");
	{ char d1=123;
		ft_p = ft_printf ("%hhd\n",d1);
		p = printf ("%hhd\n",d1);
		ft_printf("ft_p[%d], p[%d]", ft_p, p);
	}
	printf ("\n2.8 Вывод числа типа short int:\n");
	{ short int d1=123;
		ft_p = ft_printf ("%hd\n",d1);
		p = printf ("%hd\n",d1);
		ft_printf("ft_p[%d], p[%d]", ft_p, p);
	}
	printf ("\n2.9 Вывод числа типа long int:\n");
	{ long int d1=123;
		ft_p = ft_printf ("%ld\n",d1);
		p = printf ("%ld\n",d1);
		ft_printf("ft_p[%d], p[%d]", ft_p, p);
	}
	printf ("\n2.10 Вывод числа типа long long int:\n");
	{ long long int d1=123;
		ft_p = ft_printf ("%lld\n",d1);
		p = printf ("%lld\n",d1);
		ft_printf("ft_p[%d], p[%d]", ft_p, p);
	}
	printf ("\n2.11 Вывод целого без знакового числа:\n");
	{ unsigned int d1=123;
		ft_p = ft_printf ("%u\n",d1);
		p = printf ("%u\n",d1);
		ft_printf("ft_p[%d], p[%d]", ft_p, p);
	}
	printf ("\n2.12 Вывод целого числа в восьмеричном формате:\n");
	{ unsigned int d1=123;
		ft_p = ft_printf ("%o\n",d1);
		p = printf ("%o\n",d1);
		ft_printf("ft_p[%d], p[%d]", ft_p, p);
	}
	printf ("\n2.13 Вывод целого числа в шестнадцатеричном формате:\n");
	{ unsigned int d1=123;
		ft_p = ft_printf ("%x\n",d1);
		p = printf ("%x\n",d1);
		ft_printf("ft_p[%d], p[%d]", ft_p, p);
	}
	printf ("\n2.14 Вывод целого числа в шестнадцатеричном формате:\n");
	{ unsigned int d1=123;
		ft_p = ft_printf ("%#x\n",d1);
		p = printf ("%#x\n",d1);
		ft_printf("ft_p[%d], p[%d]", ft_p, p);
	}
	printf ("\n3. Вывод чисел c плавающей точкой\n");
	printf ("3.1 Вывод числа 123.456 с форматом по умолчанию:\n");
	{ double d1=123.456;
		ft_printf ("%f\n",d1);
		printf ("%f\n",d1);
	}
	printf ("\n3.2 Вывод числа 123.456 с точностью 2:\n");
	{ double d1=123.456;
		ft_printf ("%.2f\n",d1);
		printf ("%.2f\n",d1);
	}
	printf ("\n3.3 Вывод числа 123.456 в экспоненциальной форме:\n");
	{ double d1=123.456;
		ft_printf ("%e\n",d1);
		printf ("%e\n",d1);
	}
	printf ("\n3.4 Использование преобразователя g:\n");
	{ double d1=123.4567, d2=1234567.34567;
		ft_printf ("%g\n%g\n",d1,d2);
		printf ("%g\n%g\n",d1,d2);
	}
	printf ("\n3.5 Вывод числа 123.456 в шестнадцатеричной форме:\n");
	{ double d1=123.456;
		ft_printf ("%a\n",d1);
		printf ("%a\n",d1);
	}
	printf ("\n4. Вывод символа 'k':\n");
	{ char d1='k';
		ft_printf ("%c\n",d1);
		printf ("%c\n",d1);
	}
	printf ("\n5. Вывод строки 'abc':\n");
	{ char d1[4]="abc";
		ft_printf ("%s\n",d1);
		printf ("%s\n",d1);
	}
	printf ("\n6. Вывод указателя:\n");
	{ char d1[4]="abc";
		ft_printf ("%p\n",d1);
		printf ("%p\n",d1);
	}
	printf ("\n7. Подсчет выведенных символов:\n");
	{ int d1=0;
		fflush (stdout);
		printf ("Derived characters:%n",&d1);
		printf (" %d\n",d1);
		fflush (stdout);
		ft_printf ("Derived characters:%n",&d1);
		ft_printf (" %d\n",d1);
	}

	//Принудительный вывод строки не дожидаясь заполнения буфера
	printf ("\n8. Вывод буферизированной строки\n");
	{ char d1[4]="abc";
		printf ("%s",d1);
		fflush (stdout);
		ft_printf ("%s",d1);
		fflush (stdout);
		}*/
	return 0;

}
