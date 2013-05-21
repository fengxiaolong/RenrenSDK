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
        g_type_init();
        parser = json_parser_new();
        json_parser_load_from_file(parser,"userinfo.json",&error);
        if(error)
            {
                g_printf("error is %s\n",error->message);
                g_error_free(error);
                g_object_unref(parser);
                return EXIT_FAILURE;
            }
        JsonNode *root;
        root = json_parser_get_root(parser);
        
        
        
        
        return 0;
    }