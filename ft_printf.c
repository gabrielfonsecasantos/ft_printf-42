#include "ft_printf.h"

int ft_strlen(char  *s)
{
  int counter;

  counter = 0;
  while (s[counter])
    counter++;
  return (counter);
}

int ft_printf(const char *str, ...)
{
  va_list list;
  char  c;
  char  *s;

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
      if (*str == 'd')
      {
        c = va_arg(list, int) + '0';
        write(1, &c, 1);  
      }
      // checks if is necessary to print a % sign
      if (*str == '%')
      {
        write (1, "%", 1);
      }
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
  ft_printf("%s, %c, %d, %%.", "alou", 'a', 1);
  return (0);
}