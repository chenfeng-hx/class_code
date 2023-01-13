#include <linux/kthread.h>
#include <linux/module.h>
#include <linux/delay.h>
MODULE_LICENSE("GPL");
#define BUF_SIZE 20
static struct task_struct *myThread = NULL;
static int print(void *data)
{
    while (!kthread_should_stop())
    {
        printk("New kthread is running.");
        msleep(2000);
    }
    return 0;
}
static int __init kthread_init(void)
{
    printk("Create kernel thread!\n");
    // 创建的内核线程名称
    myThread = kthread_run(print, NULL, "printThread"); // 请同学们自行补充代码。
    return 0;
}
static void __exit kthread_exit(void)
{
    printk("Kill new kthread.\n");
    if (myThread)
        kthread_stop(myThread);
}
module_init(kthread_init);
module_exit(kthread_exit);