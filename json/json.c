#include <stdio.h>
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
        g_object_unref(parser);
        return EXIT_SUCCESS;
    }