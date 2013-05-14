all:main.o GetAccessToken.o GetUserInfo.o
	gcc -o all main.o GetAccessToken.o GetUserInfo.o -lcurl
main.o:main.c GetAccessToken.h GetUserInfo.h
	gcc -c main.c
GetAccessToken.o:GetAccessToken.h
	gcc -c GetAccessToken.c
GetUserInfo.o:GetUserInfo.h
	gcc -c GetUserInfo.c
clean:
	rm *flymake*;rm *.html;rm all;rm *.o;rm *~;rm \#*
