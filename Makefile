src/%.o: src/%.c
	gcc -c -Wall -Wextra -I include $< -o $@

lib/libautomate.a: src/creer_automate.o src/lire_automate.o src/liberer_automate.o  src/test_automate.o
	ar rcs $@ $^

projet_automate: lib/libautomate.a
	gcc -Wall -Wextra -pedantic src/test_automate.c -I include -L lib -lautomate -o bin/test_automate
	./bin/test_automate
	
