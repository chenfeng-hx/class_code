#include <linux/module.h>
#include <linux/proc_fs.h>
MODULE_LICENSE("GPL");
static struct proc_dir_entry *myproc_dir;
static int __init myproc_init(void)
{
    int ret = 0;
    printk("Start proc_mkdir module...");
    myproc_dir = proc_mkdir("myproc", NULL);
    if (myproc_dir == NULL)
        return -ENOMEM;
    return ret;
}
static void __exit myproc_exit(void)
{
    printk("Exit proc_mkdir module...");
    proc_remove(myproc_dir);//请同学们自行补充代码。
}
module_init(myproc_init);
module_exit(myproc_exit);