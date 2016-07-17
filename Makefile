all:
	@g++ -std=c++11 *.cpp

wc:
	@wc *.cpp *.h

clean:
	@rm a.out