//
//  myFunctions.cpp
//  UnixSystemCalls2017
//
//  Created by Андрей Зорькин on 24.01.17.
//  Copyright © 2017 Андрей Зорькин. All rights reserved.
//

#include "Screen.hpp"

bool Screen::myFunctions(std::string input){
    if (input == "sl"){
        std::vector<std::string> text{};
        text.push_back("а ты уж и не знаешь, как это:");
        text.push_back("какой там грош куда летел зачем");
        text.push_back("а к трубке все равно не подходила");
        text.push_back("на улице была всегда зима...");
        addText(text);
        updateScreen();
        return true;
    }
    if (input == "time?"){
        addLine(__TIME__);
        updateScreen();
        return true;
    }
    return false;
}
