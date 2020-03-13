# 伪目标 1.防make clean重复 2.多目标编译，并行
.PHONY:clean

# exe文件名称
TARGET = main.exe
# 源文件 $(wildcard ./src/*.c) $(wildcard ./*.c) 
SRCS = $(wildcard ./src/*.c) $(wildcard ./*.c) 
# 头文件
INCS = -I./include
BUILD = ./build
# 需要的系统库
SYSLIBS = # -lpthread
# 编译器
CC = gcc
# 编译参数 -Wall启用所有警告 -W只显示编译器认为会出现错误的警告 -g调试信息 -std=gnu99指定编译标准
CFLAGS = -Wall -g

# 根据.c 替换成.o
OBJS = $(patsubst %.c,${BUILD}/%.o,$(notdir ${SRCS})) 
# OBJS = $(addprefix $(BUILD)/, $(notdir $(SRCS:.c=.o)))


# 函数：根据源文件生成目标文件
define SRC_TO_OBJ
	$(CC) $(CFLAGS) $(INCS) -c $(1) -o $(2) # 下行空格不能省

endef

# 最终目标文件
$(TARGET):$(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(SYSLIBS) 
# 依赖的目标
$(OBJS):
	$(foreach src,$(SRCS),\
		$(call SRC_TO_OBJ,\
					$(src),\
					$(addprefix $(BUILD)/,$(notdir $(src:.c=.o)))\
		)\
	)

# 清除obj
clean:
	rm -rf $(OBJS) $(TARGET)
