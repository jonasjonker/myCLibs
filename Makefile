
SOURCES = $(wildcard *.c) $(wildcard */*.c)
OBJECTS := $(patsubst %.c,%.o,$(SOURCES))

all: $(OBJECTS)
	cc -o main $(OBJECTS)

utils/logging.o  :  
utils/loadfile.o : utils/logging.h
main.o: utils/loadfile.h  utils/logging.h

.PHONY : clean
clean:
	rm main $(OBJECTS)
