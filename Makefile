NAME = $(basename $(wildcard *.cpp))

all: compile print clean

compile:
	g++ -o $(NAME) $(NAME).cpp

print:
	./$(NAME)

clean:
	rm -f $(NAME)
