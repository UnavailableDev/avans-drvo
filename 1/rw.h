#pragma once

#include <linux/fs.h>
#include <linux/types.h>


ssize_t he_read(struct file *, char __user *, size_t, loff_t *);
ssize_t he_write(struct file *, const char __user *, size_t, loff_t *);
int he_open(struct inode *, struct file *);
int he_release(struct inode *, struct file *);

