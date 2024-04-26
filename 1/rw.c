#include "rw.h"



ssize_t he_read(struct file *f, char __user *buff, size_t len, loff_t *ppos){
	printk("read");
	return 0;
};
ssize_t he_write(struct file *f, const char __user *buff, size_t len, loff_t *ppos){

	printk("read");
	return len;
};
int he_open(struct inode *inode, struct file *f){

	printk("read");
	return 0;
};
int he_release(struct inode *inode, struct file *f){

	printk("read");
	return 0;
};


