#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <glib-object.h>
#include <json-glib/json-glib.h>
int main(int argc,char **argv)
    {
        JsonParser *parser;
        GError *error;
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
        //get the first node of json stream
        root = json_parser_get_root(parser);
        //judge the type of root
        if(JSON_NODE_HOLDS_ARRAY(root))
            {
                puts("hold array\n");
                JsonArray *array;
                //array = json_array_new();
                //get the array stored in the node
                array = json_node_get_array(root);
                g_print("the length of the array is %d\n",json_array_get_length(array));
                root = json_array_get_element(array,0);
                if(JSON_NODE_HOLDS_OBJECT(root))
                    puts("hold object\n");
                if(JSON_NODE_HOLDS_ARRAY(root))
                    puts("hold array\n");
                
            }
        else
            g_print("error\n");
        return EXIT_SUCCESS;
    }