#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>

int result;
static int sk_open(struct inode *inode, struct file *filp)
{
	printk("device has been opened\n");
	return 0;
}
static int sk_release(struct inode *inode, struct file *filp)
{
	printk("device han been released\n");
	return 0;
}
//c99 standard
struct file_operations sk_fops =
{
	.owner 		= THIS_MODULE,
	.open 		= sk_open,
	.release	= sk_release,
};

//#insmod skeleton.ko <- init_module()  
//          Linux 3.x <- 2.x
static int skeleton_init(void)
{
	printk("skeleton init success\n");
	result = register_chrdev(0,"skeleton",&sk_fops);
	//include kernel.h
	printk("major number : %d\n",result);	

	return 0;
}

//#rmmod skeleton <- cleanup_module()
static void skeleton_exit(void)
{
	unregister_chrdev(result,"skeleton");
	printk("skeleton exit success\n");
}

//include init.h
module_init(skeleton_init);
module_exit(skeleton_exit);

//include module.h
//open source(no free source)
MODULE_LICENSE("GPL");
