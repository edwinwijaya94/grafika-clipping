#include "file.h"

map<string, vector<Point> > getPointsFromFile(vector<string> filenames){

    map<string, vector<Point> > points;

    for (int i=0;i<filenames.size();i++){
        ifstream infile(filenames[i]);
        string line;

        while (getline(infile, line))
        {
            string label = line.substr (1,line.length()-2);
            // cout << "label : " << label << endl;
            while (getline(infile, line))
            {
                if (line.compare("") == 0) break;

                istringstream iss(line);
                int x, y;
                iss >> x >> y;
                // cout << "x : " << x << " y : " << y << endl;
                points[label].push_back((Point){x,y});
            }
        }
    }

    return points;
}

// int main(){

//     vector<string> filenames;
//     filenames.push_back("points.txt");

//     getPointsFromFile(filenames);
//     return 0;
// }