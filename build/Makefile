ACC_BASE=/opt/tool/acc
BUILD_DIR=$(ACC_BASE)/build
SRC_DIR=$(ACC_BASE)/src
TARGET=liu_acc

all:
	gcc $(SRC_DIR)/main.c -o $(BUILD_DIR)/$(TARGET)
	mv $(TARGET) $(BUILD_DIR)/bin

.PHONY :clean
clean:
	rm ${BUILD_DIR}/bin/*
