#include "GetUserInfo.h"
#include "AccessToken.h"
#include <string.h>
int GetUserInfo(char *access_token)
    {
        CURL *curl;
        curl_global_init(CURL_GLOBAL_ALL);
        curl = curl_easy_init();
        FILE *filename;
        char *str;
        str = (char*)malloc(sizeof(char)*CHARACTER_SIZE);
        str = strcpy(str,USERINFOURL);
        str = strcat(str,access_token);
        str = strcat(str,"&format=JSON&call_id=1.0&method=users.getInfo&fields=uid,sex,name,hometown_location");
        filename = fopen("userinfo.json","w");

        curl_easy_setopt(curl,CURLOPT_URL,URL);
        curl_easy_setopt(curl,CURLOPT_POST,1L);
        curl_easy_setopt(curl,CURLOPT_POSTFIELDS,str);
        curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1);
        curl_easy_setopt(curl,CURLOPT_VERBOSE,0L);
        curl_easy_setopt(curl,CURLOPT_HEADER,0L);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,filename);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(filename);
        return 0;
    }
static size_t write_data(char *ptr,size_t size,size_t nmemb,void *userdata)
    {
        FILE *file = (FILE*)userdata;
        return fwrite(ptr,size,nmemb,file);
    }