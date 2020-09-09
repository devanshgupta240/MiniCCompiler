second_pass:	second_pass.l second_pass.y help2.c
	bison -d second_pass.y
	flex second_pass.l
	g++ -o $@ second_pass.tab.c lex.yy.c help2.c
clean:	second_pass second_pass.tab.c second_pass.tab.h lex.yy.c
	rm second_pass second_pass.tab.c second_pass.tab.h lex.yy.c