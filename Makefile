
projet_automate:
	gcc -Wall -Wextra -pedantic src/test_automate.c -I include -L lib -l automate -o bin/test_automate
	./bin/test_automate
	
