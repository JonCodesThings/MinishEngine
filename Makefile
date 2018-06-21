PROJECT_OUT := minish
SRC_FILES := $(wildcard */*/*.cpp)
OBJ_FILES = $(wildcard *.o)

COMPILER = g++
COMPILER_FLAGS = -Wall -g
LINKER_FLAGS = -fPIC -Wall -c
INCLUDE = .
VPATH = Core/Audio/ Core/Entity/ Core/Graphics/ Core/Input/ Core/Physics/ Core/System/ Core/Tiles/

%.o : %.cpp
	$(COMPILER) $(COMPILER_FLAGS) $< -c -I$(INCLUDE)

all: $(PROJECT_OUT)

$(PROJECT_OUT) : $(patsubst %.cpp, %.o, $(wildcard */*/*.cpp))
	ar rcs $(PROJECT_OUT).a *.o
	rm -f *.o

static: $(OBJ_FILES)
	ar rcs $(PROJECT_OUT).a $(OBJ_FILES)

dynamic: objects
	g++ -shared -o $(PROJECT_OUT).so $(OBJ_FILES)

.PHONY: clean objects
clean:
	rm -f *.o *.a *.so