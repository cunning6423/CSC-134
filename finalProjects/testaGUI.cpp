#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>

// Currently best option FLTK
int main() {
    Fl_Window window(400, 300, "Simple GUI");
    window.show();
    return Fl::run();
}

// other code has recommended SFML

