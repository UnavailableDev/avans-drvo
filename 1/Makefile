RELEASE := $(shell uname -r)
KERNEL := /lib/modules/$(RELEASE)/build
# PWD doesn't have to be defined as it's inherited from the current environment
# MAKE shouldn't be defined as it's special in GNU make

# the names of these variables are required by the kernel's (imo weird) build
# system, see [kbuild-obj-var] and [kbuild-module-makefile] in ../readme.md
obj-m += redhue.o
redhue-y += main.o

all:
	$(MAKE) -C $(KERNEL) M=$(PWD) modules

# the generated compile_commands.json needs to be edited to point to the kernel
# folder as working directory because the include paths are relative
compile_commands.json:
	compiledb -o $@.tmp make -Bn
	jq --arg dir $(KERNEL) '.[].directory = $$dir' $@.tmp > $@
	$(RM) $@.tmp

