#include <glib.h>
#include <gmodule.h>

gchar *reverse(gchar *input)
{
    return "";
}

int main()
{
    gchar *input = "hell world";
    gchar *result = reverse(input);
    g_print("String %s\n", input);
    g_print("String %s\n", result);
    g_string_free(input, TRUE);
    return 0;
}
