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
        auto can = Canvas(50,50);
        //Casa
        can.DrawPointLine(10, 30, 30, 30);
        can.DrawPointLine(10, 30, 10, 15);
        can.DrawPointLine(30, 30, 30, 15);
        can.DrawPointLine(10, 15, 20, 5);
        can.DrawPointLine(20, 5, 30, 15);

        //Puerta
        if (frame % 2 == 0)
        {
            can.DrawPointLine(22, 30, 22, 25);
        } else
        {
            can.DrawPointLine(18, 30, 18, 25);
            can.DrawPointLine(22, 30, 22, 25);
            can.DrawPointLine(18, 25, 22, 25);
        }

        //Human
        int human = (frame % 50);
        can.DrawPointCircle(human, 35, 1);

        //Sol
        int sun = (frame % 50);
        can.DrawPointCircle(sun, 5, 3);

        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());
        Element lienzo = bgcolor(Color::Blue,canvas(&can));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.3s);
        frame++;
    }

    return 0;
}