CC = clang
CFLAGS = -Wall -Wpedantic -Werror -Wextra

all: strings_test

strings_test: strings.o strings_test.o
	$(CC) strings.o strings_test.o -o strings_test

strings.o: strings.c strings.h
	$(CC) $(CFLAGS) -c strings.c

strings_test.o: strings_test.c strings.h
	$(CC) $(CFLAGS) -c strings_test.c

clean:
	rm -f strings_test strings.o strings_test.o

format:
	clang-format -i -style=file *.[ch]
