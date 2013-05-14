#ifndef GETUSERINFO
#define GETUSERINFO
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#define URL "https://api.renren.com/restserver.do"
#define OPTURL "v=1.0&access_token=234283%7C6.d33d4719c2359c91abe4c7d19a9339b5.2592000.1371092400-252633228&format=JSON&call_id=1.0&method=users.getInfo&fields=name,sex,uid"
int GetUserInfo();
static size_t write_data(char *ptr,size_t size,size_t nmemb,void *userdata);
#endif