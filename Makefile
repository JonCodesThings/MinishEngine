PROJECT_OUT := minish.a
SRC_FILES := $(wildcard */*/*.cpp)
OBJ_FILES := $(wildcard *.o)

$(PROJECT_OUT): clean, objects
	ar rcs $(PROJECT_OUT) $(OBJ_FILES)

.PHONY: clean, objects
clean:
	rm *.o *.a

objects:
	g++ -c -I. $(SRC_FILES)