#include "rw.h"



ssize_t he_read(struct file *f, char __user *buff, size_t len, loff_t *ppos){
	printk(KERN_DEBUG "read %zu", len);
	return 0;
};
ssize_t he_write(struct file *f, const char __user *buff, size_t len, loff_t *ppos){

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


