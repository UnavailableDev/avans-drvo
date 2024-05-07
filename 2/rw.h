#pragma once

#include <linux/fs.h>
#include <linux/types.h>
#include <linux/io.h>

/* PIN */
#define PIN 19
/* base address */
#define GPIO1_ADDR 0x4804c000
/* register offsets in uint32_t sizes */
#define GPIO_OE 0x4D // 0x134
#define GPIO_DATAIN 0x4E // 0x138
#define GPIO_CLEARDATAOUT 0x64 // 0x190
#define GPIO_SETDATAOUT 0x65 // 0x194
/* max size in bytes */
#define GPIO_MAX 0x198

extern uint32_t* gpio1;
extern uint32_t oe;

ssize_t he_read(struct file *, char __user *, size_t, loff_t *);
ssize_t he_write(struct file *, const char __user *, size_t, loff_t *);
int he_open(struct inode *, struct file *);
int he_release(struct inode *, struct file *);

