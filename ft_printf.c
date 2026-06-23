#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int ft_strlen(char  *s)
{
  int counter;

  counter = 0;
  while (s[counter])
    counter++;
  return (counter);
}

void  ft_putnbr(double n)
{
  long  num;

  num = n;
  if (num < 0)
  {
    num *= -1;
    write(1, "-", 1);
  }
  if (num >= 10)
    ft_putnbr(num / 10);
  num = (num % 10) + '0';
  write(1, &num, 1);
}

void  ft_putnbr_unsigned(unsigned int num)
{
  if (num >= 10)
    ft_putnbr(num / 10);
  num = (num % 10) + '0';
  write(1, &num, 1);
}

int ft_printf(const char *str, ...)
{
  va_list list;
  char  c;
  char  *s;
  double f;

  va_start(list, str);
  while(*str)
  {
    if (*str == '%')
    {
      str++;
      // checks if the conversion is to char
      if (*str == 'c')
      {
        c = va_arg(list, int);
        write(1, &c, 1);
      }
      //cheks if the conversion is to string
      if (*str == 's')
      {
        s = va_arg(list, char *);
        write(1, s, ft_strlen(s));
      }
      // checks if the conversion is to an int
      if (*str == 'i' || *str == 'd')
        ft_putnbr(va_arg(list, int));
       // checks if the conversion is to an unsigned int
      if (*str == 'u')
        ft_putnbr_unsigned(va_arg(list, unsigned int));
      // checks if is necessary to print a % sign
      if (*str == '%')
        write (1, "%", 1);
      str++;
    } else 
    {
      c = *str;
      write(1, &c, 1);
      str++;
    }
  }
  va_end(list);
  return (0);
}

int main(void)
{
  unsigned int a = 3000000000;

  ft_printf("%s, %c, %i, %u.", "alou", 'a', -214748364, a);
  printf("\n");
  printf("%s, %c, %i, %u.", "alou", 'a', -214748364, a);
  return (0);
}