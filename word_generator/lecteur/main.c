#include "libft.h"
#include "lecteur.h"

void ft_leng(char *str, t_lec *e)
{
	unsigned long long int i;

	i = 0;
	while(str[i] && str[i] != ' ' && str[i] != '\n')
		i++;
	if(i <= 3)
		return;
	if(i <= 4)
		e->alph[26]++;
	if(i == 5)
		e->alph[27]++;
	if(i == 6)
		e->alph[28]++;
	if(i == 7)
		e->alph[29]++;
	if(i == 8)
		e->alph[30]++;
	if(i >= 9)
		e->alph[31]++;
	e->alph[33]++;
}

void ft_lecture(char *str, t_lec *e)
{
	unsigned long long int i;

	i = 0;
	ft_memset(e->alph,0, 50);
	while(str[i])
	{
		if(str[i] == 'a' || str[i] == 'A')
			e->alph[0]++;
		if(str[i] == 'b' || str[i] == 'B')
			e->alph[1]++;
		if(str[i] == 'c' || str[i] == 'C')
			e->alph[2]++;
		if(str[i] == 'd'|| str[i] == 'D')
			e->alph[3]++;
		if(str[i] == 'e' || str[i] == 'E')
			e->alph[4]++;
		if(str[i] == 'f'|| str[i] == 'F')
			e->alph[5]++;
		if(str[i] == 'g' || str[i] == 'G')
			e->alph[6]++;
		if(str[i] == 'h' || str[i] == 'H')
			e->alph[7]++;
		if(str[i] == 'i' || str[i] == 'I')
			e->alph[8]++;
		if(str[i] == 'j' || str[i] == 'J')
			e->alph[9]++;
		if(str[i] == 'h' || str[i] == 'K')
			e->alph[10]++;
		if(str[i] == 'l' || str[i] == 'L')
			e->alph[11]++;
		if(str[i] == 'm' || str[i] == 'M')
			e->alph[12]++;
		if(str[i] == 'n' || str[i] == 'N')
			e->alph[13]++;
		if(str[i] == 'o' || str[i] == 'O')
			e->alph[14]++;
		if(str[i] == 'p' || str[i] == 'P')
			e->alph[15]++;
		if(str[i] == 'q' || str[i] == 'Q')
			e->alph[16]++;
		if(str[i] == 'r' || str[i] == 'R')
			e->alph[17]++;
		if(str[i] == 's' || str[i] == 'S')
			e->alph[18]++;
		if(str[i] == 't' || str[i] == 'T')
			e->alph[19]++;
		if(str[i] == 'u' || str[i] == 'U')
			e->alph[20]++;
		if(str[i] == 'v' || str[i] == 'V')
			e->alph[21]++;
		if(str[i] == 'w' || str[i] == 'W')
			e->alph[22]++;
		if(str[i] == 'x' || str[i] == 'X')
			e->alph[23]++;
		if(str[i] == 'y' || str[i] == 'Y')
			e->alph[24]++;
		if(str[i] == 'z' || str[i] == 'Z')
			e->alph[25]++;
		if (ft_isalpha(str[i]))
			e->alph[32]++;
		if(str[i] == ' ' || str[i] == '\n')
			ft_leng(&str[i + 1], e);
		i++;
	}
}

void ft_print(t_lec *e)
{
	unsigned long long int i;
	char c;

	i = 0;
	c = 'a';
	while(i < 26)
	{
		ft_putstr("nb of ");
		ft_putchar(c);
		ft_putstr(" : ");
		ft_putstr(ft_ftoa(((float)e->alph[i] * (float)100) / (float)e->alph[32], -1));
		ft_putchar('\n');
		c++;
		i++;
	}
	c = 4;
	while (i <= 31)
	{
		ft_putstr("leng of word ");
		ft_putnbr(c);
		ft_putstr(" : ");
		ft_putstr(ft_ftoa(((float)e->alph[i] * (float)100) / (float)e->alph[33], -1));
		ft_putchar('\n');
		c++;
		i++;
	}
	ft_putstr("leng of char : ");
	ft_putnbr(e->alph[i]);
	ft_putchar('\n');

}

static void	ft_joinfree(char *s1, char *s2, int mode)
{
	if (s1 && mode == 0)
		ft_strdel(&s1);
	if (s2 && mode == 1)
		ft_strdel(&s2);
	if (s1 && s2 && mode == 2)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
}

char		*ft_strjoin_free_leaks(t_lec *e, char *s2, int mode)
{
	char	*str;
	unsigned long long int i;
	char	*temp_str;

	if (e->str == NULL || s2 == NULL)
		return (NULL);
	i = (ft_strlen(e->str) + ft_strlen(s2));
	if (!(str = (char *)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	temp_str = str;
	while (*e->str != '\0')
		*temp_str++ = *e->str++;
	while (*s2 != '\0')
		*temp_str++ = *s2++;
	*temp_str++ = '\0';
	//free(e->str);
	return (str);
}


int main(int argc, char **argv)
{
	int fd;
	char *str;
	char tmp[3356284];
	char *billy;
	t_lec e;

	if (argc != 2)
		return (0);
	ft_bzero(tmp, 3356284);
	e.str = ft_strdup("");
	if((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	while(read(fd, &tmp, 3356283) > 0)
	{
		billy = e.str;
		if(!(e.str = ft_strjoin_free_leaks(&e, tmp, 0)))
			return (0);
		//free(billy);
		ft_bzero(tmp, 100);
	}
	//printf("%s\n", );
	ft_lecture(e.str, &e);
	ft_print(&e);

//	ft_putstr(str);
//	printf("-->%d\n", e.alph[0]);
}