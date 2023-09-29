all:
	mkdir -p build
	$(CC) src/main.c -o build/powerd
