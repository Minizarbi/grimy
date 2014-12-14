make:
	@gcc -lm -fsanitize=address,undefined zarbfct.c
	@./a.out
