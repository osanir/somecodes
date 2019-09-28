#include <fstream>

using namespace std;

const int w = 255, h = 255;

int main(){
    ofstream img( "picture.ppm");
    img << "P3" << endl;
    img << w << " " << h << endl;
    img << "255" << endl;

    for(int y=0; y<h; y++){
        for(int x=0; x<w; x++){
            int r = x % 255;
            int g = y % 255;
            int b = x * y % 255;

            img << r << " " << g << " " << b << endl;
        }
    }
    system("open picture.ppm");
    return 0;
}
