all:
	g++ -o exec main.c bitmap.c image.c gameobject.c input.c framebuffer.c vector.c rect.c polygon.cpp shape.cpp file.c  scanline.cpp -lm -fpermissive -std=c++11 
    
run:
	sudo ./exec