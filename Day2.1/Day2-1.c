#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	int		len;
	int		i;
	char	deci[25];
	long	nb;

	len = 0;
	i = 0;
	nb = nbr;
	if (nb == 0)
		ft_putchar('0');
	while (nb > 0)
	{
		deci[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	i--;
	while (i >= 0)
		ft_putchar(deci[i--]);
	write(1, "\n", 1);
}

void	ft_putstr(char *str)
{
	int i;
	i = 0;

	while (str[i])
		ft_putchar(str[i++]);
}

int ft_atoi(char *str)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (str[++i])
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + (str[i] - '0');
	return (res);
}

int	ft_isDigit(char c)
{
	if (c >= '0' && c <= '9')
		return 1;
	return 0;
}

int main (int argc, char **argv)
{
	int array[2001];
	int fd;
	int ret;
	char c[1];
	char nb1[3000][10];
	int i, j, h, d;

	d = 0;
	i = 0;
	j = 0;
	h = 0;
	ret = 1;
	fd = open("Day2Data.txt", O_RDONLY);
	while (ret != 0)
	{
		ret = read(fd, c, 1);
		if (ret < 0 || fd < 0)
			return 0;
		if (c[0] != '\n')
				nb1[i][j++] = c[0];
		else
		{
			j = 0;
			i++;
		}
	}
	i = 0;
	j = 0;
	while (i < 1000 && nb1[i])
	{
		while (nb1[i][j])
		{
			if (ft_isDigit(nb1[i][j]))
				break ;
			j++;
		}
		if (nb1[i][0] == 'f')
			h += nb1[i][j] - 48;
		else if (nb1[i][0] == 'd')
			d += nb1[i][j] - 48;
		else if (nb1[i][0] == 'u')
			d -= nb1[i][j] - 48;
		j = 0;
		i++;		
	}
	h = h * d;
	write(1, "Total: ", 7);
	ft_putnbr(h);
	return 1;
}
