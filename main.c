#include "GetAccessToken.h"
#include "GetCurrentSessionID.h"
#include "GetUserInfo.h"
#include "GetMultipleIcon.h"
int main(int argc,char **argv)
    {
        //if(0 ==GetAccessToken())
            //system("chromium result.html");
        GetUserInfo(ACCESS_TOKEN);
        GetCurrentSessionID(ACCESS_TOKEN);
        int i = 0;
        while(i < 2019)
            {
                GetMultipleIcon(i);
                i++;
            }
        return 0;
    }