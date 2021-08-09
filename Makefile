CC=gcc

lazybox:
	$(CC) ./src/lazybox.c -o ./bin/lazybox

.PHONY: build links cleanlinks clean

build: lazybox links

links: 
	ln bin/lazybox bin/helloworld

cleanlinks:
	rm bin/helloworld

clean: cleanlinks
	rm bin/lazybox
	
