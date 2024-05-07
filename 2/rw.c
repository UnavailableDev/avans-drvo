#include "rw.h"


ssize_t he_read(struct file *f, char __user *buff, size_t len, loff_t *ppos){
	printk(KERN_DEBUG "read %zu", len);
	int val = ioread32(gpio1 + GPIO_DATAIN);
	val = (val >> PIN) & 1;
	printk(KERN_ALERT "%d", val);
	return 0;
};
ssize_t he_write(struct file *f, const char __user *buff, size_t len, loff_t *ppos){
	static int count = 0;

	/* ledje aan en uit zetten */
	gpio1 = ioremap(GPIO1_ADDR, GPIO_MAX);
	barrier();
	if (count % 2){
		iowrite32( (1<<PIN), gpio1 + GPIO_SETDATAOUT ); // Pin 19 aan
	} else {
		iowrite32( (1<<PIN), gpio1 + GPIO_CLEARDATAOUT ); // Pin 19 uit
	}
	count++;
	wmb(); // write memory barrier
	iounmap(gpio1);
	
	printk(KERN_DEBUG "%d", count);
	printk(KERN_DEBUG "write %zu", len);
	return len;
};
int he_open(struct inode *inode, struct file *f){

	printk("open");
	return 0;
};
int he_release(struct inode *inode, struct file *f){

	printk("release");
	return 0;
};


