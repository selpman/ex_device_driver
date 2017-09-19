SUBDIRS = driver app
MODULE = skeleton
DRV = $(MODULE).ko
APP = sk_app

all : compile mod_in
	mknod /dev/sk c $(shell grep -o '[0-9]*' $(MODULE).dat) 1
	clear
	./$(APP)

compile :
	@for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir || exit $?; \
	done

mod_in :	
	insmod $(DRV)
	grep "$(MODULE)" /proc/devices > $(MODULE).dat

clean : 
	@for dir in $(SUBDIRS); do \
	$(MAKE) -C $$dir clean; \
	done
	$(RM) $(DRV) $(APP)
	rmmod $(MODULE)
	$(RM) /dev/sk
	$(RM) ./skeleton.dat

