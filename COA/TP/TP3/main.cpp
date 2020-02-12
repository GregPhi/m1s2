#include "shape.h"
using namespace cimg_library;

#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main(){

  Rectangle r(0,0,100,50,green);

  CImgDisplay main_disp(1000, 1000, "Main Display", 1);

  int x,y = 0;

  while (!main_disp.is_closed() && !main_disp.is_keyESC() && !main_disp.is_keyQ()) {
    main_disp.wait();           // wait for a mouse or keyboard event

    CImg<unsigned char> img(main_disp.width(),main_disp.height(), 1, 3, 0);

    img.fill(255);//.draw_text(main_disp.width()/2 - 200, main_disp.height()/2 - 5, ss.str().c_str(), black,0,1,16);

    r.draw(img);
    img.display(main_disp);
    main_disp.wait(50);
  }
}
