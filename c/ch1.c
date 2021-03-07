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
         const gint32 *value,
         gboolean *userdata)
{
    g_print("Key: %s Value: %d Bool: %d\n", key, *value, *userdata);
    if (*value > 1)
    {
        *userdata = TRUE;
    }
}

gboolean all_unique(GString *input)
{
    GHashTable *ht = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
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
        g_string_free(current, TRUE);
    }
    gboolean result = FALSE;
    g_hash_table_foreach(ht, (GHFunc)print_kv, (gpointer)&result);
    g_hash_table_remove_all(ht);
    g_hash_table_unref(ht);
    return result;
}

int main()
{
    /* https://developer.gnome.org/glib/stable/glib-Strings.html#g-string-new */
    GString *input_a = g_string_new("abcdefghijjj");
    gboolean result_a = all_unique(input_a);
    if (!result_a)
    {
        g_print("All Characters are unique %s\n", input_a->str);
    }
    else
    {
        g_print("All Characters are not unique %s\n", input_a->str);
    }
    GString *input = g_string_new("abcdefghij");
    gboolean result = all_unique(input);
    if (!result)
    {
        g_print("All Characters are unique %s\n", input->str);
    }
    else
    {
        g_print("All Characters are not unique %s\n", input->str);
    }
    g_string_free(input_a, TRUE);
    g_string_free(input, TRUE);
    return 0;
}
