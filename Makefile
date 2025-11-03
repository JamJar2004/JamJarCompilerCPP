# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++20 -g -fdiagnostics-color=always

# Directories
SRC_DIR := .
BUILD_DIR := build
TARGET := ConsoleTester/Main

# Find all source files recursively
SRCS := $(shell find $(SRC_DIR) -type f -name '*.cpp')

# Generate corresponding object file paths under build/
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

# Default rule
all: $(TARGET)

# Link step
$(TARGET): $(OBJS)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile rule (maps .cpp to .o)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean