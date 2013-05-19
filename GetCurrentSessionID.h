#ifndef GETCURRENTSESSIONID
#define GETCURRENTSESSIONID
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "AccessToken.h"
#include <curl/curl.h>
#define USERINFOURL "v=1.0&access_token="
int GetCurrentSessionID(char *access_token);
static size_t write_data(char *ptr,size_t size,size_t nmemb,void *userdata);
#endif