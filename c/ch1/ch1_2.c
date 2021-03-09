/*
gcc -g -O0 --std=c89 ./ch1_2.c `pkg-config --cflags --libs glib-2.0` -o ch1_2.elf
./ch1_2.elf
valgrind --tool=memcheck --leak-check=yes --show-reachable=no --num-callers=1 --track-fds=no ./ch1_2.elf
*/

#include <glib.h>

void reverse(gchar arr[], gsize start, gsize end)
{
    if (start < end)
    {
        gchar temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        reverse(arr, start + 1, end - 1);
    }
}

int main()
{
    gchar str[] = "hello world\0";
    g_print("String   = %s\n", str);
    reverse(str, 0, strlen(str) - 1);
    g_print("Reversed = %s\n", str);
    return 0;
}
