all:
	mkdir -p build
	$(CC) -o build/powerd src/main.c
	./build/powerd
