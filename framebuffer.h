#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <linux/fb.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <string.h>
#include <math.h>
#include "color32.h"
#include "bitmap.h"
#include "image.h"
#include "gameobject.h"



void InitFramebuffer(long int*, long int*);
void SwapBuffers();
void CloseFramebuffer();
void ClearScreen();
void SetPixel(int x, int y, Color32 color);
void DrawLine(int x0, int y0, int x1, int y1, Color32 color);
void DrawRect(Rect rect, Color32 color);
void DrawImage(int x, int y, const Image *image, float scale, float rotation);
void DrawGameObject(const GameObject* go);
/*
void DrawBitmap(int x, int y, const BitmapFile *bitmapFile);
void DrawSubBitmap(int x, int y, const BitmapFile *bitmapFile, int offsetX, int offsetY, int width, int height);
void DrawBitmapAsSprite(int x, int y, const BitmapFile *bitmapFile, int width, int height, int index);
*/
#endif
