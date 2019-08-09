#include <stdio.h>


void			ft_bin(int a ,int l)
{
	int i;
	i = 1;
	while (i <= l)
	{
		if (a >> (l - i) & 1)
			printf("1");
		else
			printf("0");
		i++;
	}
}

int main()
{
	ft_bin(5, 4);
	return 0;
}
