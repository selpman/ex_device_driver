CC = gcc
TARGET = sk_app

all : $(TARGET).c
	$(CC) -o $(TARGET) $^
	mv $(TARGET) ../

clean :
	cd ../ && $(RM) $(TARGET)
	
