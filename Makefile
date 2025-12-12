GCC=g++
CCFLAGS=-Wall -Iinclude/
ECHO=@echo

SRC_DIR=src
BUILD_DIR=build
EXE_DIR=bin

DAY_SRC=$(wildcard $(SRC_DIR)/day*.cpp)

DAY_OBJ=$(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(DAY_SRC))
UTILS_OBJ=$(BUILD_DIR)/utils.o

EXE=$(patsubst $(SRC_DIR)/%.cpp,$(EXE_DIR)/%,$(DAY_SRC))

.SECONDARY:

all: $(EXE)

$(EXE_DIR)/%: $(BUILD_DIR)/%.o $(UTILS_OBJ)
	$(ECHO) "Edition des liens de <$@>"
	$(GCC) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(ECHO) "Compilation de <$<>"
	$(GCC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(BUILD_DIR)/* $(EXE_DIR)/*