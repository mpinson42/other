#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
void ft_putstr(char *str)
{
	write(1, str, strlen(str));
}

void ft_is_ok()
{
	char lpBuffer[20];

	ft_putstr("c'est ok ?(y/n)\n");
	fgets(lpBuffer, sizeof(lpBuffer), stdin);
	if(lpBuffer[0] == 'n')
		exit(0);

	ft_putstr("\n---------------------------\n\n");
}

int main() 
{
	char lpBuffer[20];
	ft_putstr("test 1 : auteur\n\n");
	ft_putstr("cat -e auteur : ");
	system("cat -e auteur");
	ft_putstr("whoami        : ");
	system("whoami");	
	ft_putstr("\n");
	ft_is_ok();

	ft_putstr("test 2 : header\n\n");
	/*ft_putstr("alias norminette : ");
	system("alias | grep norminette");
	ft_putstr("\n");
	ft_putstr("alias leaks      : ");
	system("echo perdu");
	ft_putstr("\n");
	ft_putstr("alias gcc        : ");
	system("alias | grep gcc");
	ft_putstr("\n");
	ft_is_ok();*/

	ft_putstr("cat **/**[.ch] | grep By:\n");
	system("cat **/**[.ch] | grep By:");
	system("whoami");
	ft_is_ok();

	ft_putstr("test 2 : norminette\n\n");
	ft_putstr("norminette **/**[.ch]\n");
	system("norminette **/**[.ch]");
	ft_is_ok();

	//make

	ft_putstr("test 3 : compile walcard\n\n");
	ft_putstr("cat Makefile | grep \"*\"\n");
	system("cat Makefile | grep \"*\"");
	ft_is_ok();


	ft_putstr("test 4 : compile\n\n");
	ft_putstr("make fclean && make && make && ls -l\n");
	system("make fclean && make && make && ls -l");
	ft_is_ok();

	//nm
	ft_putstr("test 5 : fonction interdit\n\n");
	ft_putstr("nm * | grep U\n");
	system("nm * | grep U");
	ft_is_ok();

	ft_putstr("lancer les commande suivant : \n");
	ft_putnbr("alias | grep norminette && alias | grep leaks && alias | grep gcc && alias | grep nm");

	return(0);
}
