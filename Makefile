main: main.c wektor.c
	gcc main.c -O2 -o main -fsanitize=address

test: main
	bash test.sh