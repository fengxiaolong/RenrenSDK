object=try_json.c
CFLAGS=$(shell pkg-config --cflags json-glib-1.0 gtk+-3.0)
LIBS=$(shell pkg-config --libs json-glib-1.0 gtk+-3.0)
all:$(object)
	gcc $(object) $(CFLAGS) $(LIBS) -o all -g
clean:
	rm \#*;rm *.o;rm all;rm *.o
