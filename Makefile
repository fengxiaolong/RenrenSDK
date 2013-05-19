object = main.o GetAccessToken.o GetUserInfo.o GetCurrentSessionID.o
all:$(object)
	gcc -o all $(object) -lcurl -g
main.o:main.c GetAccessToken.h GetUserInfo.h AccessToken.h GetCurrentSessionID.o
GetAccessToken.o:GetAccessToken.h AccessToken.h
GetUserInfo.o:GetUserInfo.h AccessToken.h
GetCurrentSessionID.o:GetCurrentSessionID.h AccessToken.h
clean:
	rm *flymake*;rm *.html;rm all;rm *.o;rm *~;rm \#*;rm *.json
