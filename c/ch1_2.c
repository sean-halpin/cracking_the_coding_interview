#include <glib.h>
#include <gmodule.h>

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
    gchar str[] = "hello world";
    g_print("String   = %s\n", str);
    reverse(str, 0, strlen(str) - 1);
    g_print("Reversed = %s\n", str);
    return 0;
}
