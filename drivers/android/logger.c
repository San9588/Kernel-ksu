// drivers/android/logger.c

#include <linux/fs.h>
#include <linux/miscdevice.h>
#include <linux/module.h>
#include <linux/uaccess.h>

#define LOGGER_LOG_MAIN 0

static ssize_t logger_read(struct file *file, char __user *buf,
			   size_t count, loff_t *ppos)
{
	return 0;
}

static const struct file_operations logger_fops = {
	.owner = THIS_MODULE,
	.read = logger_read,
};

static struct miscdevice logger_main_device = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "log_main",
	.fops = &logger_fops,
};

static int __init logger_init(void)
{
	return misc_register(&logger_main_device);
}

module_init(logger_init);
MODULE_LICENSE("GPL");
