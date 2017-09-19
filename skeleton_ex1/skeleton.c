#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>

//#insmod skeleton.ko <- init_module()  
//          Linux 3.x <- 2.x
static int skeleton_init(void)
{
	//include kernel.h
	printk("skeleton init success\n");
	
	return 0;
}

//#rmmod skeleton <- cleanup_module()
static void skeleton_exit(void)
{
	printk("skeleton exit success\n");
}

//include init.h
module_init(skeleton_init);
module_exit(skeleton_exit);

//include module.h
//open source(no free source)
MODULE_LICENSE("GPL");
