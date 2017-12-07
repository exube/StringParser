all: 
	make -C StringParser all
	sh build.sh

clean:
	make -C StringParser clean
	rm -rf bin
	rm -rf include
