#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void	ft_putnbr(int nbr)
{
	char deci[25];
	int i;

	i = 0;

	while(nbr > 0)
	{
		deci[i] = nbr % 10 + 48;
		nbr = nbr / 10;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar(deci[i--]);
	write(1, "\n", 1);
}

int main (int argc, char **argv)
{
	char str[2005][24];
	char c[1];
	int ret;
	int e, g, i, j, p;
	int fd;

	ret = 1;
	e = 0;
	g = 0;
	i = 0;
	j = 0;
	p = 1;
	fd = open("day3.txt", O_RDONLY);
	while (ret != 0)
	{
		ret = read(fd, c, 1);
		if (ret < 0)
			return 0;
		if (c[0] != '\n')
			str[i][j++] = c[0];
		else
		{
			j = 0;
			i++;
		}
	}
	i = 0;
	j = 11;
	ret = 0;
	while (j >= 0)
	{
		i = 0;
		ret = 0;
		while (i < 1000)
		{
			if (str[i][j] == '1')
				ret++;	
			i++;
		}
		if (ret > 500)
			e += p;
		else
			g += p;
		j--;
		ft_putnbr(ret);
		p *= 2;
	}
	ret = e * g;
	ft_putnbr(ret);
	return 1;
}
