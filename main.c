#include "GetAccessToken.h"
#include "AccessToken.h"
int main(int argc,char **argv)
    {
        if(0 ==GetAccessToken())
            system("chromium result.html");
        char *str = "helong";
        GetUserInfo(ACCESS_TOKEN);
        return 0;
    }