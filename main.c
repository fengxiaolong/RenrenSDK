#include "GetAccessToken.h"
int main(int argc,char **argv)
    {
        if(0 ==GetAccessToken())
            system("chromium result.html");
        char *str = "helong";
        GetUserInfo(str);
        return 0;
    }