#ifndef GETUSERINFO
#define GETUSERINFO
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#define URL "https://api.renren.com/restserver.do"
#define USERINFOURL "v=1.0&access_token="
int GetUserInfo(char *access_token);
static size_t write_data(char *ptr,size_t size,size_t nmemb,void *userdata);
#endif