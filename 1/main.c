#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>

#include "rw.h"

#define CHR_NAME "redhue"

dev_t cdev_num;

int param_name = 0;

MODULE_LICENSE("Dual BSD/GPL");

struct cdev *cdev;
struct file_operations he_rw = {
	.read = he_read, 
	.write = he_write,
	.open = he_open,
	.release = he_release,
};

static int hello_init(void) {
	printk(KERN_ALERT "Hello, world\n");
	
	cdev = cdev_alloc();
	if (!cdev) {
		printk(KERN_ALERT "error");
		cdev_del(cdev);
		return 1;
	}
	cdev->ops = &he_rw;
	cdev_init(cdev, &he_rw);

	cdev_num = MKDEV(500, 0);
	// if (alloc_chrdev_region(&cdev_num, 0, 1, CHR_NAME) < 0) {
	if (register_chrdev_region(cdev_num, 1, CHR_NAME) < 0) {
		//TODO  ERROR HANDLING
		printk(KERN_ERR "region error");
	}
	if (cdev_add(cdev, cdev_num, 1) < 0){
		//TODO: ERROR HANDLING
		printk(KERN_ERR "cdev_add oops");
	}
	printk(KERN_DEBUG "%d", MAJOR(cdev_num));
	

	return 0;
}

static void hello_exit(void) {
	printk(KERN_ALERT "Goodbye, world\n");
	unregister_chrdev_region(cdev_num, 1);
	cdev_del(cdev);
}

module_param(param_name, int, 0400);

module_init(hello_init);
module_exit(hello_exit);

