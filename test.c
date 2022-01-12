#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

int power(int num, int power)
{
	int res;
	res = num;
	if (power == 0)
		return (1);
	while (power > 1)
	{
		res = res * num;
		power--;
	}
	return (res);
}

char *char_to_binary(char c)
{
	char *bin;
	int i;

	i = 0;
	bin = malloc(sizeof(char) * 9);
	while (i <= 7)
	{
		if (c >= power(2, 7 - i))
		{
			bin[i] = '1';
			c = c - power(2, 7 - i);
		}
		else
			bin[i] = '0';
		i++;
	}
	bin[i] = '\0';
	return (bin);
}

char **str_to_byte(char *str)
{
	char **binstr;
	int i;
	int len;

	len = ft_strlen(str);
	i = 0;
	binstr = malloc(sizeof(char *) * len + 1);
	while (i < len)
	{
		binstr[i] = char_to_binary(str[i]);
		i++;
	}
	binstr[i] = '\0';
	return (binstr);
}

int main()
{
	char *str = "hello";
	char **binstr = str_to_byte(str);
	int i = 0;
	

	while (str[i])
	{
		printf("%s\n", binstr[i]);
		i++;
	}
	return (0);
}