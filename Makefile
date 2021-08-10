CC=gcc

lazybox:
	$(CC) ./src/lazybox.c -o ./bin/lazybox

.PHONY: build links cleanlinks clean

build: lazybox links

links: 
	ln bin/lazybox bin/helloworld
	ln bin/lazybox bin/echo

cleanlinks:
	rm bin/helloworld
	rm bin/echo

clean: cleanlinks
	rm bin/lazybox
	
