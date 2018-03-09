PROJECT_OUT := minish.a
SRC_FILES := $(wildcard */*/*.cpp)
OBJ_FILES = $(wildcard *.o)

$(PROJECT_OUT): objects
	ar rcs $(PROJECT_OUT) $(OBJ_FILES)

.PHONY: clean objects
clean:
	rm -f *.o *.a

objects: clean
	g++ -c -I. $(SRC_FILES)
	$(eval OBJ_FILES := *.o)