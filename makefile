all:
	g++ -o exec main.c bitmap.c image.c gameobject.c input.c framebuffer.c vector.c rect.c polygon.cpp -lm -fpermissive -std=c++11
    
run:
	sudo ./exec
