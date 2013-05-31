#ifndef GETMULTIPLEICON
#define GETMULTIPLEICON
#include "AccessToken.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <error.h>
void GetMultipleIcon(int n);
static size_t write_data(char *ptr,size_t size,size_t nmemb,void *userdata);
#endif