#include <ftxui/dom/elements.hpp> //Objetos tipo html. 
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position;
    int frame = 0;


    while (true)
    {
        auto can = Canvas(200,200);
        can.DrawPointLine(10 + frame, 30, 30 + frame, 30);
        can.DrawPointLine(10 + frame, 30, 10 + frame, 15);
        can.DrawPointLine(30 + frame, 30, 30 + frame, 15);
        can.DrawPointLine(10 + frame, 15, 20 + frame, 5);
        can.DrawPointLine(20 + frame, 5, 30 + frame, 15);

        if (frame % 2 == 0) {
            can.DrawPointLine(18 + frame, 30, 18 + frame, 25);
        }
        can.DrawPointLine(22 + frame, 30, 22 + frame, 25);
        can.DrawPointLine(18 + frame, 25, 22 + frame, 25);

        can.DrawPointCircle(5 + frame, 35, 1);


        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::Blue,canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.2s);
        frame++;
    }

    return 0;
}