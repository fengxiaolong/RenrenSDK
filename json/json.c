#include <stdio.h>
//#include <json/json.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <glib-object.h>
#include <json-glib/json-glib.h>
int main(int argc,char **argv)
    {
        JsonParser *parser;
        JsonNode *root;
        GError *error;
        error = NULL;
        g_type_init();
        parser = json_parser_new();
        json_parser_load_from_file(parser,"userinfo.json",&error);
        if(error)
            {
                g_print("Unable to parser,%s\n",error->message);
                g_error_free(error);
                g_object_unref(parser);
                return EXIT_FAILURE;
            }
        root = json_parser_get_root(parser);
        guint a;
        a = json_parser_get_current_line(parser);
        guint b;
        b = json_parser_get_current_pos(parser);
        printf("current_line is %d,current_pos is %d\n",a,b);

        printf("json node type is %d\n",JSON_NODE_TYPE(root));
        if(JSON_NODE_HOLDS_OBJECT(root))
            puts("holds object");
        if(JSON_NODE_HOLDS_ARRAY(root))
            puts("holds array");
        g_object_unref(parser);
        return EXIT_SUCCESS;
    }