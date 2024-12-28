#include "cub3.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	n--;
	while (n-- && *s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

char	*ft_strdup(char *src)
{
	int		i;
	int		j;	
	char	*new_str;

	if (src == 0)
		return (0);
	i = 0;
	while (src[i] != '\0')
	{
		i++;
	}
	new_str = (char *)malloc((i + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	j = 0;
	while (src[j] != '\0')
	{
		new_str[j] = src[j];
		j++;
	}
	new_str[j] = '\0';
	return (new_str);
}

static int	ft_free(char **str, int size)
{
	while (size--)
		free(str[size]);
	return (-1);
}

static int	count_words(const char *str, char charset)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == charset || str[i + 1] == '\0')
			&& (str[i] == charset || str [i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

static void	w_word(char *dest, const char *from, char charset)
{
	int	i;

	i = 0;
	while (!(from[i] == charset || from [i] == '\0'))
	{
		dest[i] = from[i];
		i++;
	}
	dest[i] = '\0';
}

static int	w_split(char **split, const char *str, char charset)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == charset || str[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((str[i + j] == charset || str[i + j] == '\0') == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (split[word] == NULL)
				return (ft_free(split, word - 1));
			w_word(split[word], str + i, charset);
			i += j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		words;

	words = count_words(str, c);
	res = (char **)malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	res[words] = 0;
	if (w_split(res, str, c) == -1)
		return (NULL);
	return (res);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		if (str[i + 1] == '+' || str [i + 1] == '-')
			return (0);
		i++;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		if ((result == 214748364) && (str[i] == '8') && (sign % 2 == 1))
			return (-2147483648);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}