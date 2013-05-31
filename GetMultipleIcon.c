#include "GetMultipleIcon.h"
#define USERINFOURL "v=1.0&access_token="
void GetMultipleIcon(int n)
    {
        CURL *curl;
        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();
        FILE *filename;
        char str[200];
        sprintf(str,"v=1.0&access_token=%s&format=JSON&call_id=1.0&method=users.getInfo&uids=%d&fields=mainurl",ACCESS_TOKEN,n);
        filename = fopen("icon.json","w+");
        puts(str);
        curl_easy_setopt(curl,CURLOPT_URL,URL);
        curl_easy_setopt(curl,CURLOPT_POST,1L);
        curl_easy_setopt(curl,CURLOPT_NOPROGRESS,0L);
        //        curl_easy_setopt(curl,CURLOPT_PROGRESSFUNCTION,progress);
        //        curl_easy_setopt(curl,CURLOPT_PROGRESSDATA,stderr);
        curl_easy_setopt(curl,CURLOPT_POSTFIELDS,str);
        curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1);
        curl_easy_setopt(curl,CURLOPT_VERBOSE,0L);
        curl_easy_setopt(curl,CURLOPT_HEADER,0L);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,filename);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        fclose(filename);
    }
static size_t write_data(char *ptr,size_t size,size_t nmemb,void *userdata)
{
    FILE *file = (FILE*)userdata;
    return fwrite(ptr,size,nmemb,file);
}