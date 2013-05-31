#include "GetMultipleIcon.h"
#define USERINFOURL "v=1.0&access_token="
void GetMultipleIcon(int n)
    {
        CURL *curl;
        
        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();
        char *str = NULL;
        size_t n1 = strlen(USERINFOURL);
        str = (char*)malloc(n1 + 1);
        strncpy(str,USERINFOURL,n1);
        str = strcat(str,ACCESS_TOKEN);
        str = strcat(str,"&format=JSON&call_id=1.0&method=users.getInfo&uids=");
        FILE *filename = NULL;
        char number[20];
        char *error = NULL;
        sprintf(number,"%d",n);
        str = strcat(str,number);
        str = strcat(str,"&fields=mainurl");
        filename = fopen("icon.json","w");
        puts(str);
    }
static size_t write_data(char *ptr,size_t size,size_t nmemb,void *userdata)
{
    FILE *file = (FILE*)userdata;
    return fwrite(ptr,size,nmemb,file);
}