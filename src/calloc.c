#include "../includes/so_long.h"


static  void    *ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n > 0)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
		n--;
	}
	return (s);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	result;

	result = nmemb * size;
	if (nmemb == 0 && size == 0)
		p = (void *)malloc(1);
	p = (void *)malloc(result);
	if (!p)
		return (0);
	p = ft_bzero(p, result);
	if (!p)
	{
		return (0);
	}
	return (p);
}