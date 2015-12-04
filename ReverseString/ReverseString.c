#include <stdio.h>

char Stack[1024];
int pEsp;

void Push(char ch)
{
	if(pEsp == 1023)
	{
		printf("Out of Resource!\n");
		return ;
	}

	Stack[pEsp] = ch;
	pEsp++;
}

char Pop(void)
{
	char ch;

	if(pEsp < 0)
	{
		printf("Invalid Data!\n");
		return 1;
	}

	pEsp--;
	ch = Stack[pEsp];

	return ch;
}

int main(void)
{
	char Str[1024];
	int i,j;
//Using fgets to avoid the warning of using gets.
	fgets(Str, sizeof(char)*1024, stdin);
//	gets(Str);

	pEsp = 0;
	i = 0;
	while(Str[i] != '\0')
	{
		Push(Str[i]);
		i++;
	}

	j = 0;
	while(i > 0)
	{
		Str[j] = Pop();
		j++;
		i--;
	}
	Str[j] = '\0';

//	fputs(Str, stdout);
	puts(Str);

	return 0;
}
