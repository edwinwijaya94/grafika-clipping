
#include "polygon.h"

void DrawPolygon(vector<Point> Pol){
	printf("a\n");
	for(int i=0; i<Pol.size(); i++){
		//printf("%d %d %d %d\n",Pol[i].x, Pol[i].y, Pol[(i+1)%Pol.size()].x, Pol[(i+1)%Pol.size()].y);
		DrawLine(Pol[i].x, Pol[i].y, Pol[(i+1)%Pol.size()].x, Pol[(i+1)%Pol.size()].y, Color32{255,255,255,255});
	}
}
