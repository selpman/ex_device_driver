#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>

#include <asm/uaccess.h> //copy_to_user define
#include <linux/sched.h> //struct task_struct access
#include <linux/fdtable.h> //file_struct define

int major=245;
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

typedef struct {
	pid_t pid;
	unsigned int next_fd;
	unsigned long i_ino;
}my_read;
	 
static ssize_t sk_read(struct file *filp, char* buffer, size_t count, loff_t *f_pos)
{
	my_read reads;

	reads.next_fd 	= current->files->next_fd;
	reads.pid 	= current->pid;
	reads.i_ino	= filp->f_inode->i_ino;
	
	printk("pid number is %d\n",reads.pid);
	printk("next_fd : %d\n",reads.pid);
	printk("i_ino : %f\n",reads.i_ino);

	copy_to_user(buffer,&reads,count);
	return count; 
}

//c99 standard
struct file_operations sk_fops =
{
	.owner 		= THIS_MODULE,
	.open 		= sk_open,
	.release	= sk_release,
	.read		= sk_read,
};

//#insmod skeleton.ko <- init_module()  
//          Linux 3.x <- 2.x
static int skeleton_init(void)
{
	printk("skeleton init success\n");
	result = register_chrdev(major,"skeleton",&sk_fops);
	if(result < 0)
	{
		printk("couldn`t get a major number\n");
		return 0;
	}

	//include kernel.h
	printk("major number : %d\n",result);	
	printk("skeleton init success\n");	

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
