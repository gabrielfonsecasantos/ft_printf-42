#include "ft_printf.h"
#include <stdio.h>

int ft_strlen(char  *s)
{
  int counter;

  counter = 0;
  while (s[counter])
    counter++;
  return (counter);
}

void  ft_putnbr(int n)
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

void  ft_putfloat(float n)
{
  long  intPart;
  float  deciPart;
  long  temp;

  temp = n / 1;
  intPart = temp;
  deciPart = (n - temp);
  ft_putnbr(intPart);
  write(1, ".", 1);
  ft_putnbr(deciPart);
}

int ft_printf(const char *str, ...)
{
  va_list list;
  char  c;
  char  *s;
  float f;

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
      if (*str == 'i')
        ft_putnbr(va_arg(list, int)); 
      if (*str == 'u')
      {
        f = va_arg(list, double);
        ft_putfloat(f);
      } 
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
  ft_printf("%s, %c, %i, %u.", "alou", 'a', 2147483647, 1.50);
  printf("\n");
  printf("%s, %c, %i, %f.", "alou", 'a', 2147483647, 1.50);
  return (0);
}