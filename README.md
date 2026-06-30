*This project has been created as part
of the 42 curriculum by gviniciu*

## Description

# ft_printf

The goal of this project is to recode the classic C's printf() function. Doing so, the objetive is to learn about variadic functions, wich are functions with a variable number of arguments. 
 
### How it works: 

The function iterates over the format string. Plain characters are written directly to standard output. When it finds a % sign, it reads the next character to identify the conversion, then it consumes the matching argument from the variadic list, converts that argument to its text representation, and writes that text to standard output.

Return Value: it also returns the numbers of characters printed, just like printf().

### Supported conversions

| Specifier | Description |
|-----------|-------------|
| `%c` | A single character |
| `%s` | A string (C convention; `(null)` for a `NULL` pointer) |
| `%p` | A pointer address in hexadecimal, prefixed with `0x` (`(nil)` for `NULL`) |
| `%d` | A signed decimal (base 10) integer |
| `%i` | A signed integer in base 10 |
| `%u` | An unsigned decimal (base 10) integer |
| `%x` | An unsigned number in hexadecimal, lowercase |
| `%X` | An unsigned number in hexadecimal, uppercase |
| `%%` | A literal percent sign |

---

## Instructions

### Compilation

The project builds a static library named `libftprintf.a` at the root of the repository.

```bash
make        # builds libftprintf.a
make clean  # removes object files
make fclean # removes object files and the library
make re     # fclean + make
```

The library is compiled with `cc` and the flags `-Wall -Wextra -Werror`.

### Using it in your own code

Include the header and link against the library when compiling:

```c
#include "ft_printf.h"

int main(void)
{
    int len;

    len = ft_printf("Hello, %s! You are number %d.\n", "world", 42);
    ft_printf("%d characters were printed.\n", len);
    return (0);
}
```

```bash
cc main.c -L. -lftprintf -I. -o program
./program
```

---

## Usage examples

```c
ft_printf("char:    %c\n", 'A');             // char:    A
ft_printf("string:  %s\n", "forty-two");     // string:  forty-two
ft_printf("pointer: %p\n", (void *)&x);      // pointer: 0x7ffe...
ft_printf("int:     %d\n", -2147483648);     // int:     -2147483648
ft_printf("uint:    %u\n", 4294967295);      // uint:    4294967295
ft_printf("hex:     %x\n", 255);             // hex:     ff
ft_printf("HEX:     %X\n", 255);             // HEX:     FF
ft_printf("percent: %%\n");                  // percent: %
```
---

## Resources

Classic references used to understand the topic:

- `man 3 printf` — the reference behaviour this project reproduces.
- `man 3 stdarg` — the `va_start`, `va_arg`, `va_end` macros.

### Other references used:

### Geeksforgeeks
https://www.geeksforgeeks.org/c/variadic-functions-in-c/

### StackOverflow

https://stackoverflow.com/questions/7177956/convert-int-to-hexdecimal-without-using-printf-c-programming

## Chosen Algorithm and Data Structure

ft_printf is a function that accepts a variable number of arguments, wich was handled using the <stdarg.h> library:

- `va_start` to initiate a list of arguments.

- `va_arg` to access the next argument.

- `va_end` to clean all resources after the list was used.

There is **no heavy data structure** in this project, since the decision was to not implement the bonus part, wich would require a more robust solution. 

### Main loop

`ft_printf` walks the format string one character at a time:

- If the character is **not** `%`, it is written as-is.
- If it **is** `%`, the next character is read and passed to a dispatcher (`ft_formatter`) that decides which conversion function to call.

Each conversion function returns the **number of bytes it wrote**, and `ft_printf` accumulates that into a running counter, which becomes the return value. Every helper returns its own length wich keeps the character count correct without a separate counting pass.

### Error Handling

Every function call returns -1 when it fails, just like `printf()` does when it finds an error. 

### Number conversion by recursion

Decimal and hexadecimal output (`%d`, `%i`, `%u`, `%x`, `%X`, and the address part of `%p`) is produced **recursively**. The least significant digit is the easiest to extract (`n % base`), but it must be printed *last*. Recursion solves the ordering elegantly: the function recurses on `n / base` first (printing the high-order digits), then writes the current digit on the way back up. This avoids manually building and reversing a buffer.

## How AI was used

- Used to better understand how printf() really works.

- Used to structure this README.