#include <linux/init.h>
#include <linux/module.h>
#include <linux/cdev.h>

#include "rw.h"


dev_t cdev_num;

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
	cdev->ops = &he_rw;
	// cdev_init(cdev, *he_rw);

	// if (cdev_add(cdev, cdev_num, 1) < 0){
		//TODO: ERROR HANDLING

	// }
	// printk("%d", MAJOR(cdev_num));
	return 0;
}

static void hello_exit(void) {
	printk(KERN_ALERT "Goodbye, world\n");
	cdev_del(cdev);
}


module_init(hello_init);
module_exit(hello_exit);

