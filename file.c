#include "file.h"

map<string, vector<Point> > getPointsFromFile(vector<string> filenames){

    map<string, vector<Point> > points;

    for (int i=0;i<filenames.size();i++){
        ifstream infile(filenames[i]);
        string line;
        string x;

        while (getline(infile, line))
        {
			//cout<<line.length()<<endl;
			//cout<<"line10: "<<line[10]<<endl;
            string label = line.substr (1,line.length()-3);
            //cout<<"label: "<<label<<endl;
            // cout << "label : " << label << endl;
            while (getline(infile, line))
            {
                //cout<<line.length()<<endl;
                //cout<<line<<endl;
                //if (line[0] == '\n') break;
                //printf("%d\n", line.length());
                if (line.length() == 1) break;

                istringstream iss(line);
                int x, y;
                iss >> x >> y;
                 //cout << "x : " << x << " y : " << y << endl;
                points[label].push_back((Point){x,y});
            }

        }
    }
	printf("points --- size: %d\n",points.size());
    return points;
}

// int main(){

//     vector<string> filenames;
//     filenames.push_back("points.txt");

//     getPointsFromFile(filenames);
//     return 0;
// }
