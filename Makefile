team:
	@echo "Team: idiosyncrasy"
	@echo
	@echo "Rehana Mahfuz"
	@echo "rmahfuz"
	@echo
	@echo "Nivedita Nighojkar"
	@echo "Nnnighojk"
	@echo

clean:
	@rm -f lex.yy.cpp
	@rm -f parser.tab.cpp
	@rm -f parser.tab.hpp
	@rm -f a.out
compiler:
	@bison -d parser.ypp
	@flex -o lex.yy.cpp scanner.lpp
	@g++ -std=c++0x parser.tab.cpp lex.yy.cpp -lfl

all:
	@echo "Hi"
