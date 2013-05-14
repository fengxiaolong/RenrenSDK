#include "GetAccessToken.h"
int GetAccessToken()
    {
        CURL *curl;
        curl = curl_easy_init();
        FILE *filename;
        filename = fopen("result.html","w");
 
        curl_easy_setopt(curl,CURLOPT_URL,OPTURL);
        curl_easy_setopt(curl,CURLOPT_POST,1L);
        curl_easy_setopt(curl,CURLOPT_POSTFIELDS,ADDURL);
        curl_easy_setopt(curl,CURLOPT_FOLLOWLOCATION,1);
        curl_easy_setopt(curl,CURLOPT_VERBOSE,0L);
        curl_easy_setopt(curl,CURLOPT_HEADER,0L);
        curl_easy_setopt(curl,CURLOPT_WRITEFUNCTION,write_data);
        curl_easy_setopt(curl,CURLOPT_WRITEDATA,filename);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        return 0;
    }
size_t write_data(char *ptr,size_t size,size_t nmemb,void *userdata)
    {
        FILE *file = (FILE*)userdata;
        return fwrite(ptr,size,nmemb,file);
    }


//234283%7C6.d33d4719c2359c91abe4c7d19a9339b5.2592000.1371092400-252633228
//234283%7C6.d33d4719c2359c91abe4c7d19a9339b5.2592000.1371092400-252633228