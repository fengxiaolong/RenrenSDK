#ifndef GETACCESSTOKEN
#define GETACCESSTOKEN
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#define URL "https://graph.renren.com/oauth/authorize"
#define URLFILDS "client_id=2cc79d04e5264b928d4be870072ed56f&redirect_uri=http://graph.renren.com/oauth/login_success.html&response_type=token"
static size_t write_data(char *ptr,size_t size,size_t nmemb,void *userdata);
int GetAccessToken();
#endif