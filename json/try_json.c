#include <stdio.h>
//#include <json/json.h>
#include <stdlib.h>
#include <string.h>
#include <glib.h>
#include <glib-object.h>
#include <json-glib/json-glib.h>

int main(int arg,char **argv)
    {
        JsonParser *parser;
        GError *error;
        //        g_type_init();
        parser = json_parser_new();
        json_parser_load_from_file(parser,"userinfo.json",&error);
        if(error)
            {
                g_print("error is %s\n",error->message);
                g_error_free(error);
                g_objec [1;5Bt_unref] (parser);
                return EXIT_FAILURE;
            }
        JsonNode *root;
        root = json_parser_get_root(parser);
        gboolean nodetype;
        nodetype = JSON_NODE_TYPE(root);
        printf("node type is %d\n",nodetype);
        JsonObject *jsonobject;
        jsonobject = json_object_new();
        gboolean hasmember;
        jsonobject = json_node_get_object(root);
        guint cc;
        cc = json_object_get_size(jsonobject);
        g_printf("this object size is %d\n",cc);
        if(JSON_NODE_OBJECT == nodetype)
            {
                puts("object\n");
                hasmember = json_object_has_member(jsonobject,"name");
                if(hasmember)

                {
                    puts("has member\n");
                    JsonNode *newnode = json_object_get_member(jsonobject,"name");
                    g_print("the internal data type is %d\n",JSON_NODE_TYPE(newnode));
                    g_print("name is :%s\n",json_node_get_string(newnode));
                }
                else
                    puts("has no member\n");
            }
        if(JSON_NODE_ARRAY == nodetype)
            {
                puts("array\n");
            }
        return 0;
    }