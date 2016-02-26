
#include "polygon.h"

Point getPivot(vector<Point> vertices){
    int xmin=vertices[0].x, xmax=vertices[0].x, ymin=vertices[0].y, ymax=vertices[0].y;
    for(int i=1; i<vertices.size(); i++){
        if(vertices[i].x > xmax){
            xmax = vertices[i].x;
        }
        if(vertices[i].x < xmin){
            xmin = vertices[i].x;
        }

        if(vertices[i].y > ymax){
            ymax = vertices[i].y;
        }
        if(vertices[i].y < ymin){
            ymin = vertices[i].y;
        }
    }

    return (Point){(xmax+xmin)/2, (ymax+ymin)/2};
}

Point transformPoint(Point P, Point centroid, float scale, float rotation){
    int i,j;
    Point Pnew;
    float PI = 3.14159265;
    float rad = rotation * PI / 180.0f;
    //printf("centroid %d %d\n",centroid.x, centroid.y);
    //scale
    Pnew.x = centroid.x +(int)(double(P.x - centroid.x) * scale);
    Pnew.y = centroid.y +(int)(double(P.y - centroid.y) * scale);

    //rotate
    int tx2 = Pnew.x - centroid.x, ty2 = Pnew.y - centroid.y;
    Pnew.x = centroid.x + (int)((double)tx2 * cos(rad) - (double)ty2 * sin(rad));
    Pnew.y = centroid.y + (int)((double)tx2 * sin(rad) + (double)ty2 * cos(rad));

    // for(j = 0; j < scaledH; j++){
    //     for(i = 0; i < scaledW; i++){
    //         x2 = i - centroid.x;
    //         y2 = j - centroid.y;
            
    //         if(rotation != 0) {
    //             int tx2 = x2, ty2 = y2;
    //             x2 = (int)((float)tx2 * cos(rad) - (float)ty2 * sin(rad));
    //             y2 = (int)((float)tx2 * sin(rad) + (float)ty2 * cos(rad));
    //         }
    //         SetPixel(x+x2,y+y2, image->pixels[(int)((float)j/scale)][(int)((float)i/scale)]);
    //     }
    // }

    return Pnew;
}


void drawPolygon(vector<Point> Pol){
    for(int k=0; k<Pol.size(); k++){     
        DrawLine(Pol[k].x, Pol[k].y, Pol[(k+1)%Pol.size()].x, Pol[(k+1)%Pol.size()].y, Color32{255,255,255,255});
    }
}

void drawPolygon(vector<Point> Pol, float scale, float rotation ){
    Point centroid = getPivot(Pol);
    //printf("check\n");
	for(int k=0; k<Pol.size(); k++){
		//printf("before : %d %d\n", Pol[k].x, Pol[k].y);
        Pol[k] = transformPoint(Pol[k],centroid, scale, rotation);
        //printf("after : %d %d\n", Pol[k].x, Pol[k].y);
	}
	
	drawPolygon(Pol);
}
