#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#define OPTURL "https://graph.renren.com/oauth/authorize"
#define ADDURL "client_id=2cc79d04e5264b928d4be870072ed56f&redirect_uri=http://graph.renren.com/oauth/login_success.html&response_type=token"
size_t write_data(char *ptr,size_t size,size_t nmemb,void *userdata);
int main(int argc,char **argv)
    {
        CURL *curl;
        curl = curl_easy_init();
        FILE *filename;
        filename = fopen("hello.html","w");

        curl_easy_setopt(curl,CURLOPT_URL,OPTURL);
        curl_easy_setopt(curl,CURLOPT_POSTFIELDS,ADDURL);
        curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1L);
        curl_easy_setopt(curl,CURLOPT_VERBOSE,1);
        curl_easy_setopt(curl,CURLOPT_HEADER,0);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,filename);

        curl_easy_cleanup(curl);
        return 0;
    }
size_t write_data(char *ptr,size_t size,size_t nmemb,void *userdata)
    {
        FILE *file = (FILE*)userdata;
        return fwrite(ptr,size,nmemb,file);
    }