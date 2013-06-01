#ifndef GETUSERICON
#define GETUSERICON
#include <stdio.h>
#include <curl/curl.h>
#include <string.h>
#include <stdlib.h>
#include <glib.h>

int Getusericon(int from,int to);//get url uid between from and to
static size_t write_data(char *ptr,size_t size,size_t nmemb,void *userdata);

#endif
