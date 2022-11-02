#include <iostream>
#include <sstream>
#include <string>

enum switches {
    LIGHTS_INSIDE = 1,
    LIGHTS_OUTSIDE = 2,
    HEATERS = 4,
    WATER_PIPE_HEATING = 8,
    CONDITIONER = 16 ,
    OUTLETS = 32,
};


/*void conditions (int time, float temp_inside, float temp_outside,  std::string movement,  std::string light_inside,  std::string light_outside){
  int state = 0;
}*/

int main () {
    std::cout<<"The program is about to start. Get ready to enter temperature inside the house, outside the house, if there is any movement outside (yes/no), if the light is switched on or not (yes/no): "<<std::endl;
    int state = 0;
    std::string buffer;
    state&=~LIGHTS_INSIDE;
    state&=~LIGHTS_OUTSIDE;
    state&=~HEATERS;
    state&=~WATER_PIPE_HEATING;
    state&=~CONDITIONER;
    float temp_inside;
    float temp_outside;
    std::string movement_str;
    bool movement;
    std::string light_inside_str;
    bool light_inside;

    for (int day = 0; day < 3; day++) {
        int light_temperature = 5000;
        for (int time = 0; time < 24; time++) {
            std::cout << "It's day " << day + 1 << " time " << time << " o'clock." << std::endl;
            std::cout << "Enter data: " << std::endl;

            std::getline(std::cin, buffer);

            std::istringstream input(buffer);

            input >> temp_inside >> temp_outside >> movement_str >> light_inside_str;

            movement = (movement_str == "yes");
            light_inside = (light_inside_str == "yes");
            //temperature outside and heating
            if (temp_outside <= 0 && (! (state&WATER_PIPE_HEATING))) {
                state|=WATER_PIPE_HEATING;
                std::cout << "Water pipe heating has been turned on." << std::endl;
            }else if (temp_outside >= 5 && (state&WATER_PIPE_HEATING)) {
                state&=~WATER_PIPE_HEATING;
                std::cout << "Water pipe heating has been turned off."<<std::endl;
            }
            //свет на улице
            if ((time > 16 || time < 5) && movement && (!(state&LIGHTS_OUTSIDE))) {
                std::cout << "Lights outside have been turned on. "<<std::endl;
                state|=LIGHTS_OUTSIDE;
            }else if (((time <= 16 && time >= 5)||(movement == false)) && (state&LIGHTS_OUTSIDE)) {
                std::cout << "Lights outside have been turned off"<<std::endl;
                state&=~LIGHTS_OUTSIDE;
            }

            //отопление в доме
            if ((temp_inside<22) && (!(state&HEATERS))){
                state|=HEATERS;
                std::cout <<"The heaters have been turned on!"<<std::endl;
            }else if ((temp_inside>25) && (state|HEATERS)){
                std::cout<<"Heaters have been turned off"<<std::endl;
                state&=~HEATERS;
            }
            //кондиционер
            if ((temp_inside>30) && (!(state&CONDITIONER))){
                state|=CONDITIONER;
                std::cout << "Conditioner has been turned on" << std::endl;
            }else if ((temp_inside<=25) && (state|CONDITIONER)){
                state&=~CONDITIONER;
                std::cout << "Conditioner has been turned off"<<std::endl;
            }
            //температура света
            if (time > 16&&time <= 20) {
                light_temperature -= 575;
                if (light_inside) {
                    std::cout << "The temperature of light is " << light_temperature << "." << std::endl;
                }
            }
        }
    }
    return 0;
}