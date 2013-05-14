all:main.o GetAccessToken.o
	gcc -o all main.o GetAccessToken.o -lcurl
main.o:main.c GetAccessToken.h
	gcc -c main.c
GetAccessToken.o:GetAccessToken.h
	gcc -c GetAccessToken.c
clean:
	rm *flymake*;rm *.html;rm all;rm *.o;rm *~;rm \#*
