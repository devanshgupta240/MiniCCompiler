parser:	lexer.l parser.y helpers.c code_gen.c
	bison -d parser.y
	flex lexer.l
	g++ -o $@ parser.tab.c lex.yy.c helpers.c code_gen.c
clean:	parser parser.tab.c parser.tab.h lex.yy.c
	rm parser parser.tab.c parser.tab.h lex.yy.c