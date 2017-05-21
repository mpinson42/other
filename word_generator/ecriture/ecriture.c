#include "libft.h"
#include "lecteur.h"

#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

float	ft_atof(char *str)
{
	int i;
	float rendu;
	float rest;
	int test;
	char *no;

	i = 0;
	rendu = ft_atoi(str);
	while(str[i] != '.')
		i++;
	i++;
	rest = ft_atoi(&str[i]);
	test = ft_strlen(&str[i]);
	while(test)
	{
		rest = rest / 10;
		test--;
	}
	rendu = rendu + rest;
	return(rendu);
}

void ft_prting(t_write *e)
{
	int i;
	char *str;
	int rend;
	int diff;
	int leng;
	int save;
	int save_diff;
	int der;

	srand (time (NULL)); 
	i = 0;
	while(i < 32)
	{
		e->alph[i] = e->alph[i]  * 10;
		e->alph[i] = e->alph[i]  * 10;
		e->data[i] = e->alph[i];
		i++;
	}


	save_diff = 0;
	rend = ((int)(rand() % 10000)) + 1;
	i = 26;
	save = 26;
	der = 0;
	printf("--->%d\n", e->data[26]);
	while(i < 32)
	{
		if(save_diff <= rend && e->data[i] + save_diff > rend)
		{
			//save_diff = diff;
			save = i;
		}
		printf("%d <= %d && %d > %d      i == %d\n", save_diff, rend, e->data[i] + save_diff, rend,i);
		save_diff = save_diff + e->data[i];
		i++;
	}
	printf("----->%d\n", save);
	if(save == 26)
	{
		str = malloc(sizeof(char) * 5);
		save = 4;
	}
	if(save == 27)
	{
		save = 5;
		str = malloc(sizeof(char) * 6);
	}
	if(save == 28)
	{
		save = 6;
		str = malloc(sizeof(char) * 7);
	}
	if(save == 29)
	{
		save = 7;
		str = malloc(sizeof(char) * 8);
	}
	if(save == 30)
	{
		save = 8;
		str = malloc(sizeof(char) * 9);
	}
	if(save == 31)
	{
		save = 9;
		str = malloc(sizeof(char) * 10);
	}

	leng = 0;
	while (leng < save)
	{
		rend = ((int)(rand() % 10000)) + 1;
		i = 0;
		save_diff = 0;
		while(i < 26)
		{
			if(save_diff <= rend && e->data[i] + save_diff > rend)
			{
				str[leng] = i + 97;
				//printf("non\n");
			}
			//printf("%d >= %d && %d < %d      i == %d     leng == %d\n", save_diff, rend, e->data[i] + save_diff, rend,i, leng);
			save_diff = save_diff + e->data[i];
			i++;
		}

		leng++;
	}
	str[leng] = 0;
	printf("%d\n", str[1]);
	ft_putstr(str);
	ft_putchar('\n');
	//printf("%d\n", rend);




}

int main(int argc, char **argv)
{
	char *str;
	t_write e;
	char c;
	int i;

	i = 0;
	c = 'a';
/*	str = ft_strjoin("./", argv[1]);
	str = ft_strjoin(str, " ");
	str = ft_strjoin(str, argv[2]);
	printf("%s\n", str);
	system(str);*/
	ft_bzero(e.alph,50);
	ft_bzero(e.data,50);
	while(get_next_line(0, &str) > 0)
	{
		i = 0;
		c = 'a';
		ft_putstr(str);
		ft_putchar('\n');
		while(i < 26)
		{
			if(ft_strlen(str) >= 6 && str[6] == c)
				e.alph[i] = ft_atof(&str[10]);
			i++;
			c++;
		}
		if(ft_strncmp(str, "leng of word 4 : ", 17) == 0)
			e.alph[26] = ft_atof(&str[17]);
		if(ft_strncmp(str, "leng of word 5 : ", 17) == 0)
			e.alph[27] = ft_atof(&str[17]);
		if(ft_strncmp(str, "leng of word 6 : ", 17) == 0)
			e.alph[28] = ft_atof(&str[17]);
		if(ft_strncmp(str, "leng of word 7 : ", 17) == 0)
			e.alph[29] = ft_atof(&str[17]);
		if(ft_strncmp(str, "leng of word 8 : ", 17) == 0)
			e.alph[30] = ft_atof(&str[17]);
		if(ft_strncmp(str, "leng of word 9 : ", 17) == 0)
			e.alph[31] = ft_atof(&str[17]);
	}
	ft_prting(&e);
	i = 0;
	while(i <= 31)
	{
		//printf("%f\n", e.alph[i]);
		i++;
	}
	return(0);
}