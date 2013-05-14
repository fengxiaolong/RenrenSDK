#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#define OPTURL "https://graph.renren.com/oauth/authorize"
//#define ADDURL "client_id=2cc79d04e5264b928d4be870072ed56f&redirect_uri=http://graph.renren.com/oauth/login_success.html&response_type=token"
#define ADDURL "client_id=2cc79d04e5264b928d4be870072ed56f&redirect_uri=http://graph.renren.com/oauth/login_success.html&response_type=token"
#define MOREURL "client_id=2cc79d04e5264b928d4be870072ed56f&redirect_uri=http://graph.renren.com/oauth/login_success.html&response_type=token&username=15195941098&password=feng19890815"
#define SECRET "client_id=2cc79d04e5264b928d4be870072ed56f&client_secret=8f5364fbabc243b7a3992ab3ec6750af&redirect_uri=http://graph.renren.com/oauth/login_success.html&grant_type=client_credentials"
size_t write_data(char *ptr,size_t size,size_t nmemb,void *userdata);
int GetAccessToken();