# ifneq ($(KERNELRELEASE),)
	# obj-m :=main.o
# else
	# KERNELDIR ?= /root/raspberrypi-kernel //此处路径为内核源码路径，根据实际情况修改；该内核源码必须要经过编译，否则会报错。
	# PWD := $(shell pwd)
# default:
	# $(MAKE) -C $(KERNELDIR) M=$(PWD) modules
# endif
# .PHONY:clean
# clean:
	# -rm *.mod.c *.o *.order *.symvers *.ko

ifneq ($(KERNELRELEASE),)
	obj-m :=helloworld.o
else
	KERNELDIR ?= /lib/modules/$(shell uname -r)/build
	PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif
.PHONY:clean
clean:-rm *.mod.c *.o *.order *.symvers *.ko
