object = main.o GetAccessToken.o GetUserInfo.o GetCurrentSessionID.o GetMultipleIcon.o
CFLAGS=$(shell pkg-config --libs libcurl)
all:$(object)
	cc -o all $(object) $(CFLAGS) -g
main.o:main.c GetAccessToken.h GetUserInfo.h AccessToken.h GetCurrentSessionID.o
GetAccessToken.o:GetAccessToken.h AccessToken.h
GetUserInfo.o:GetUserInfo.h AccessToken.h
GetCurrentSessionID.o:GetCurrentSessionID.h AccessToken.h
GetMultipleIcon.o:GetMultipleIcon.h AccessToken.h
clean:
	rm *flymake*;rm *.html;rm all;rm *.o;rm *~;rm \#*;rm *.json
