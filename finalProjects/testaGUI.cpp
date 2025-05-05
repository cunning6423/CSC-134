#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>

void button_cb(Fl_Widget* w, void*) {
    std::cout << "Button clicked!\n";
}

int main() {
    Fl_Window win(300, 200, "Glitchuations GUI");
    Fl_Button btn(100, 80, 100, 40, "Start");
    btn.callback(button_cb);
    win.end();
    win.show();
    return Fl::run();
}

// other code has recommended SFML

