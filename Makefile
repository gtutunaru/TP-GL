CFLAGS := -Wall -g -pedantic -std=c++11
INC := -I ./include/

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

EXE := $(BIN_DIR)/calculator

SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CXX) $^  -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CFLAGS) -c $< $(INC) -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)


