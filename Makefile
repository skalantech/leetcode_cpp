################################################################################
# Declare some Makefile variables
################################################################################
CC = g++
LANG_STD = -std=c++11
COMPILER_FLAGS = -Wall -Wfatal-errors
INCLUDE_PATH = #-I"./libs/"
SRC_FILES = ./longestsubs*.cpp \
			#./src/Game/*.cpp \
			./src/Logger/*.cpp \
			./src/ECS/*.cpp \
			./src/AssetStore/*.cpp \
			./libs/imgui/*.cpp
LINKER_FLAGS = #-lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -llua5.3 
OBJ_NAME = answer

################################################################################
# Declare some Makefile rules
################################################################################
build:
	$(CC) $(COMPILER_FLAGS) $(LANG_STD) $(INCLUDE_PATH) $(SRC_FILES) $(LINKER_FLAGS) -o $(OBJ_NAME)

run:
	./$(OBJ_NAME)

clean:
	rm $(OBJ_NAME)
