/*
gcc -g -O0 --std=c89 ./ch1_3.c `pkg-config --cflags --libs glib-2.0` -o ch1_3.elf
./ch1_3.elf
valgrind --tool=memcheck --leak-check=yes --show-reachable=no --num-callers=1 --track-fds=no ./ch1_3.elf
*/

#include <glib.h>

void remove_deplicates(gchar arr[], gsize length)
{
    gsize lookback = 1;
    gsize i = 1;
    for (i; i < length; i++)
    {
        gsize j;
        for (j = 0; j < lookback; j++)
        {
            if (arr[i] == arr[j])
            {
                break;
            }
        }
        if (j == lookback)
        {
            arr[lookback] = arr[i];
            lookback++;
        }
    }
    arr[lookback] = 0;
}

int main()
{
    gchar str[] = "hello world";
    g_print("String   = %s\n", str);
    remove_deplicates(str, strlen(str));
    g_print("Dedupes = %s\n", str);
    return 0;
}