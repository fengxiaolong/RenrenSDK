object = main.o GetAccessToken.o GetUserInfo.o
all:$(object)
	gcc -o all $(object) -lcurl
main.o:main.c GetAccessToken.h GetUserInfo.h AccessToken.h
GetAccessToken.o:GetAccessToken.h
GetUserInfo.o:GetUserInfo.h AccessToken.h
clean:
	rm *flymake*;rm *.html;rm all;rm *.o;rm *~;rm \#*;rm *.json
