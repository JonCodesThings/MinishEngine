PROJECT_OUT := minish
SRC_FILES := $(wildcard */*/*.cpp)
OBJ_FILES = $(wildcard *.o)

all: static dynamic

static: objects
	ar rcs $(PROJECT_OUT).a $(OBJ_FILES)

dynamic: objects
	g++ -shared -o $(PROJECT_OUT).so $(OBJ_FILES)

.PHONY: clean objects
clean:
	rm -f *.o *.a *.so

objects: clean
	g++ -fPIC -c -I. $(SRC_FILES) -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system
	$(eval OBJ_FILES := *.o)