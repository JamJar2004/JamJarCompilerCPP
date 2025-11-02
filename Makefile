# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++20 -g -fdiagnostics-color=always

# Directories
SRC_DIR := Compiler
TEST_DIR := ConsoleTester
BUILD_DIR := build
TARGET := $(TEST_DIR)/Main

# Find all .cpp files recursively
SRCS := $(shell find $(SRC_DIR) -name '*.cpp') $(TEST_DIR)/Main.cpp
OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Default rule
all: $(TARGET)

# Link final binary
$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile each .cpp into .o
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean