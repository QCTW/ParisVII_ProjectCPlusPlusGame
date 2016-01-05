# the compiler: gcc for C program, define as g++ for C++
CC=g++
CPP_FILES:=$(wildcard */*.cpp) 
OBJ_FILES:=$(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))
OBJ_DIR=./obj/
BIN_DIR=./bin/
SFML_INCLUDE_DIR=/usr/local/Cellar/sfml/2.3_1/include
SFML_SUPPORT=-I$(SFML_INCLUDE_DIR)
SFML_LIB=-lsfml-graphics -lsfml-window -lsfml-system
TEST_FILES:=$(wildcard $(BIN_DIR)test*.exe)

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS=-std=c++11 -stdlib=libstdc++ -g -Wall

# the build target executable:
all: clean $(OBJ_DIR) compile.components main.exe

compile.components: player cell platform move view

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

check:
	# ./SFML_Check.sh $(SFML_INCLUDE_DIR)

player  : $(addprefix $(OBJ_DIR),$(notdir $(patsubst %.cpp,%.o, $(wildcard player/*.cpp))))
obj/%.o : player/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

move    : $(addprefix $(OBJ_DIR),$(notdir $(patsubst %.cpp,%.o, $(wildcard move/*.cpp))))
obj/%.o : move/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

platform: $(addprefix $(OBJ_DIR),$(notdir $(patsubst %.cpp,%.o, $(wildcard platform/*.cpp))))
obj/%.o : platform/%.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

cell    : $(addprefix $(OBJ_DIR),$(notdir $(patsubst %.cpp,%.o, $(wildcard cell/*.cpp))))
obj/%.o : cell/%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

view    : $(addprefix $(OBJ_DIR),$(notdir $(patsubst %.cpp,%.o, $(wildcard view/*.cpp))))
obj/%.o : view/%.cpp
	$(CC) -c $(CFLAGS) $(SFML_SUPPORT) $< -o $@	

main.exe: $(BIN_DIR)
	$(RM) obj/main.o
	$(CC) $(CFLAGS) $(SFML_LIB) -o $(BIN_DIR)main.exe obj/*.o main.cpp

test	: clean $(OBJ_DIR) compile.components $(BIN_DIR) test.compile test.run

test.run:$(TEST_FILES)
	$(TEST_FILES)

test.compile: $(addprefix $(BIN_DIR),$(notdir $(patsubst %.cpp,%.exe, $(wildcard test/*.cpp))))
$(BIN_DIR)%.exe: test/%.cpp
	$(CC) $(CFLAGS) $(SFML_LIB) -o $@ obj/*.o $<

clean   :
	$(RM) $(OBJ_DIR)*
	rm -fr $(BIN_DIR)*
