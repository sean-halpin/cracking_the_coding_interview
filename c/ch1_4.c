/*
    gcc -g -O0 --std=c89 ./ch1_4.c `pkg-config --cflags --libs glib-2.0` -o ch1_4.elf
    valgrind --tool=memcheck --leak-check=yes --show-reachable=no --num-callers=1 --track-fds=no ./ch1_4.elf
*/

#include <glib.h>

gboolean anagram(GString *str1, GString *str2)
{
    if (str1->len != str2->len)
    {
        return FALSE;
    }
    gint unique_chars = 0;
    gint char_counts[256];
    memset(char_counts, 0, sizeof(char_counts));
    gsize i;
    for (i = 0; i < str1->len; i++)
    {
        gchar current = str1->str[i];
        gint entry = char_counts[current];
        if (entry == 0)
            unique_chars++;
        char_counts[current]++;
    }
    gsize j;
    gint chars_checked = 0;
    for (j = 0; j < str2->len; j++)
    {
        gchar current = str2->str[j];
        gint entry = char_counts[current];
        if (entry == 0)
            return FALSE;
        char_counts[current]--;
        if (char_counts[current] == 0)
        {
            chars_checked++;
            if (chars_checked == unique_chars)
            {
                return j == (str2->len - 1);
            }
        }
    }
    return FALSE;
}

int main()
{
    GString *string1 = g_string_new("kayak");
    GString *string2 = g_string_new("kaayk");
    gboolean result = anagram(string1, string2);
    g_print("%d\n", result);
    g_string_free(string1, TRUE);
    g_string_free(string2, TRUE);
}