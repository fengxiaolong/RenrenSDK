object = GetUserIcon.o main.o
LIBS=$(shell pkg-config --libs glib-2.0 libcurl)
CFLAGS=$(shell pkg-config --cflags glib-2.0)
all:$(object)
	cc -o all $(object) $(CFLAGS) $(LIBS) -g
main.o:GetUserIcon.h
GetUserIcon.o:GetUserIcon.h
clean:
	rm *.o;rm all;rm \#*;rm *.icv