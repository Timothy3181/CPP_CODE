#include<iostream>

using namespace std;

enum class color {BLUE, RED};

color color1 = color::BLUE;
color color2 = color::RED;

int main()
{
    cout << static_cast<int>(color1) << " " << static_cast<int>(color2) << endl;
}
