KDIR = /lib/modules/$(shell uname -r)/build
PWD = $(shell pwd)
TARGET = skeleton

obj-m = $(TARGET).o

all :
	$(MAKE) -C $(KDIR) M=$(PWD) modules
	cp $(TARGET).ko ../

clean :
	$(MAKE) -C $(KDIR) M=$(PWD) clean
	cd ../ && $(RM) $(TARGET).ko
