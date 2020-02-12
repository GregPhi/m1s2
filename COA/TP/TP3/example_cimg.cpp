#include "CImg.h"
using namespace cimg_library;

#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

int main()
{
    const unsigned char
        red[]   = { 255,0,0 },
        green[] = { 0,255,0 },
        blue [] = { 0,0,255 },
        black[] = { 0,0,0 };

    CImgDisplay main_disp(700, 400, "Main Display", 0);
    int x = 0, y = 0;
    bool button_status = false;

    while (!main_disp.is_closed() && !main_disp.is_keyESC() && !main_disp.is_keyQ()) {
        main_disp.wait();           // wait for a mouse or keyboard event

        x = main_disp.mouse_x();    // get the x position of the mouse, relative to the window
        y = main_disp.mouse_y();    // get the x position of the mouse, relative to the window

        bool click = main_disp.button(); // true if the mouse has been clicked

        button_status = button_status xor click;

        bool keyA = main_disp.is_key(cimg::keyA);

        stringstream ss;

        ss << "X = " << setw(3) << x << "  Y = " << setw(3) << y << "   click = " << click
           << "   b status = " << button_status <<  "   keyA = " << keyA ;

        cout << ss.str() << endl;

        CImg<unsigned char> img(main_disp.width(),main_disp.height(), 1, 3, 0);

        // Functions to draw:

        // CImg<T>& CImg<T>::draw_line(const int x0, const int y0,
        //       const int x1, const int y1, const tc ∗const color,
        //       const float opacity=1, const unsigned int
        //       pattern=∼0U, const bool init_hatch=true)

        // CImg<T>& CImg<T>::draw_triangle (const int x0, const int
        //       y0, const int x1, const int y1, const int x2, const
        //       int y2, const tc ∗const color, const float opacity =
        //       1 )

        // CImg<T>& CImg<T>::draw_circle (const int x0, const int y0,
        //       int radius, const tc ∗const color, const float
        //       opacity = 1 )

        // CImg<T>& CImg<T>::draw_rectangle (const int x0, const int
        //       y0, const int z0, const int x1, const int y1, const
        //       int z1, const tc ∗const color, const float opacity =
        //       1 )

        // Example:

        img.fill(255).draw_text(main_disp.width()/2 - 200, main_disp.height()/2 - 5, ss.str().c_str(), black,0,1,16);
        if (button_status)
            img.draw_rectangle(x, y, x+100, y+50, green);

        img.display(main_disp);
        main_disp.wait(50);           // wait for 50 milliseconds

    }
    cout << "End!!" << endl;
}
