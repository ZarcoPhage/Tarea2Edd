# See
# https://makefiletutorial.com

all: clean build

clean:
	rm -fr broken-keyboard

build:
	@echo Compiling broken-keyboard ...
	g++ broken-keyboard.cpp keyboard-buffer.cpp keyboard.cpp -o broken-keyboard -Wall
	@echo Run with ./broken-keyboard
