SRC_DIR = src
BUILD_DIR = build
CC = g++
SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
SRC_IMPLEMENTATIONS = $(wildcard $(SRC_DIR)/implementations/*.cpp)
OBJ_NAME = gameengine
COMPILER_FLAGS = -std=c++20 -Wall -O0 -g
INCLUDE_SDL_HEADERS =-I/Library/Frameworks/SDL2.framework/Headers
INCLUDE_SDL_HEADERS_IMAGE =-I/Library/Frameworks/SDL2_image.framework/Headers
INCLUDE_SDL_HEADERS_TTF =-I/Library/Frameworks/SDL2_ttf.framework/Headers
INCLUDE_SDL_HEADERS_MIXER =-I/Library/Frameworks/SDL2_mixer.framework/Headers
PATHFRAMEWORK =-F/Library/Frameworks
FRAMEWORK_SDL =-framework SDL2
FRAMEWORK_SDL_IMAGE =-framework SDL2_image
FRAMEWORK_SDL_MIXER =-framework SDL2_mixer
FRAMEWORK_SDL_TTF =-framework SDL2_ttf

all:
	$(CC) $(COMPILER_FLAGS) $(SRC_FILES) $(SRC_IMPLEMENTATIONS) $(INCLUDE_SDL_HEADERS) $(INCLUDE_SDL_HEADERS_IMAGE) $(INCLUDE_SDL_HEADERS_TTF) $(INCLUDE_SDL_HEADERS_MIXER) $(PATHFRAMEWORK) $(FRAMEWORK_SDL) $(PATHFRAMEWORK) $(FRAMEWORK_SDL_IMAGE) $(PATHFRAMEWORK) $(FRAMEWORK_SDL_MIXER) $(PATHFRAMEWORK) $(FRAMEWORK_SDL_TTF) -v -o $(BUILD_DIR)/$(OBJ_NAME) -v && rsync -avr $(SRC_DIR)/assets $(BUILD_DIR)/

clean: 
	rm -rf build/*

