#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <error.h>
#include <glib-object.h>
#include <json-glib/json-glib.h>
#include <json-glib/json-gobject.h>
int main(int argc,char **argv)
    {
        JsonParser *parser;
        GError *error;
        g_type_init();
        error = NULL;
        parser = json_parser_new();
        json_parser_load_from_file(parser,"info.json",&error);
        if(error)
            {
                g_print("error is %s\n",error->message);
                g_error_free(error);
                g_object_unref(parser);
                return EXIT_FAILURE;
            }
        JsonNode *root;
        root = json_parser_get_root(parser);
        if(JSON_NODE_HOLDS_ARRAY(root))
            {
                puts("hold array\n");
                JsonArray *array;
                array = json_array_new();
                array = json_node_get_array(root);
                g_print("the length of the array is %d\n",json_array_get_length(array));
                root = json_array_get_element(array,0);
                if(JSON_NODE_HOLDS_OBJECT(root))
                    {
                        JsonObject *newobj;
                        newobj = json_node_get_object(root);
                        guint a;
                        a = json_object_get_size(newobj);
                        printf("the size of this object is %d\n",a);
                        const gchar *str;
                        str = json_object_get_string_member(newobj,"birthday");
                        g_print("birthday is %s \n",str);
                    }
       
            }
        return EXIT_SUCCESS;
    }