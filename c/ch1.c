/* https://developer.gnome.org/glib/stable/glib-compiling.html */

/* glib */
/* pkg-config --cflags glib-2.0 */
/* pkg-config --libs glib-2.0 */
/* gobject */
/* pkg-config --cflags --libs gobject-2.0 */
/* gmodules */
/* pkg-config --cflags --libs gmodule-no-export-2.0 */
/* pkg-config --cflags --libs gmodule-2.0 */
/* gcc ./ch1.c `pkg-config --cflags --libs glib-2.0` -o ch1 */

#include <glib.h>
#include <gmodule.h>

static void
print_kv(const gchar *key,
         const gint32 *value)
{
    g_print("Key: %s Value: %d\n", key, *value);
    g_print("Key: %d Value: %d\n", key, value);
}

gboolean all_unique(GString *input)
{
    GHashTable *ht = g_hash_table_new(g_str_hash, g_str_equal);
    gchar *input_str = input->str;
    size_t i = 0;
    for (i = 0; i < input->len; i++)
    {
        GString *current = g_string_new(input_str + i);
        current->str[1] = '\0';
        g_print("%s\n", current->str);
        gint32 *entry = g_hash_table_lookup(ht, current->str);
        if (entry == 0)
        {
            g_print("Vacant\n");
            gint32 *val = g_new(gint32, 1);
            *val = 1;
            g_hash_table_insert(ht, g_strdup(current->str), val);
        }
        else
        {
            g_print("Occupied: %d\n", *entry);
            *entry = *entry + 1;
        }
    }
    g_hash_table_foreach(ht, (GHFunc)print_kv, NULL);
    g_print("%s\n", input_str);
    return TRUE;
}

int main()
{
    /* https://developer.gnome.org/glib/stable/glib-Strings.html#g-string-new */
    GString *input = g_string_new("zazzzzzzzzzzz a");
    all_unique(input);
    g_string_free(input, TRUE);
    return 0;
}
