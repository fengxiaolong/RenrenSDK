#include "GetUserIcon.h"
int Getusericon(int from,int to)
{
    CURL *curl;
    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();
    FILE *filename = NULL;
    filename = fopen("headicon.icv","w+");
    while(from < to)
    {
        curl_easy_reset(curl);
        char *str;
        //str = g_strdup_printf("http://www.renren.com/%d/profile?portal=",from);
        str = g_strdup_printf("http://fenghelong.renren.com");
        puts(str);
        curl_easy_setopt(curl,CURLOPT_URL,str);
        curl_easy_setopt(curl,CURLOPT_HTTPGET,1L);
        curl_easy_setopt(curl,CURLOPT_NOPROGRESS,0L);
        curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,0L);
        curl_easy_setopt(curl,CURLOPT_VERBOSE,0L);
        curl_easy_setopt(curl,CURLOPT_HEADER,0L);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,filename);
        curl_easy_perform(curl);
        g_free(str);
        from++;
    }
    curl_easy_cleanup(curl);
        curl_global_cleanup();
    fclose(filename);
        return 0;
    }

static size_t write_data(char *ptr,size_t size,size_t nmemb,void *userdata)
    {
        FILE *file = (FILE*)userdata;
        return fwrite(ptr,size,nmemb,file);
    }