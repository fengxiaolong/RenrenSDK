#include "GetAccessToken.h"
#include "GetCurrentSessionID.h"
#include "GetUserInfo.h"
int main(int argc,char **argv)
    {
        if(0 ==GetAccessToken())
            system("chromium result.html");
        GetUserInfo(ACCESS_TOKEN);
        GetCurrentSessionID(ACCESS_TOKEN);
        return 0;
    }