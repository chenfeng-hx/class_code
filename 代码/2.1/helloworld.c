// #include<stdio.h>
// int main()
// {
// 	char str[] = "Hello";
// 	printf("%s", str);
// }

#include<linux/module.h>    // 包含了对模块的结构定义以及模块的版本控制

MODULE_LICENSE("GPL");      // 声明了GPL版权

int __init hello_init(void) {    // 加载模块
    printk("hello init\n");
	printk("hello, world!\n");
	return 0;
}

void __exit hello_exit(void){     
    printk("hello exit\n");
}

module_init(hello_init);
module_exit(hello_exit);