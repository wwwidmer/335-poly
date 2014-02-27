polynomial.out : main.o polynomial.o tokenizer.o
	g++ -o polynomial.out main.o polynomial.o tokenizer.o
tokenizer.o: tokenizer.cpp tokenizer.h
	g++ -c tokenizer.cpp tokenizer.h
polynomial.o: polynomial.cpp polynomial.h
	g++ -c polynomial.cpp polynomial.h
clean : &nbps rm *.o rm *~




