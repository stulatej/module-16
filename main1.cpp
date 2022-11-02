#include <iostream>
#include <string>

int main () {
    float speed_value = 0.0f;
    std::string speed_str;
    do {
        std::cout << "How did the speed change? ";
        float delta;
        std::cin >> delta;
        speed_value += delta;

        while (speed_value>150){
            speed_value -= delta;
            std::cout << "The car is too fast! You need to slow down. Enter speed again." << std::endl;
            std::cin >> delta;
            speed_value += delta;
        }

        char speed_str[32];
        std::sprintf(speed_str,"%.1f", speed_value);
        std::cout << "Current speed is: " <<speed_str<<" km/h\n";

    } while (speed_value>0);

    std::cout << "The car has stopped\n";

}