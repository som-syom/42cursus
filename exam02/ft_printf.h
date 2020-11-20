#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct      s_flags
{
    int     width;
    int     dot;
    int     precision;
    char    type;
}                   t_flags;

int     ft_printf(const char *format, ...);

#endif