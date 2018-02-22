//
//  stackMain.cpp
//  UnixSystemCalls2017
//
//  Created by Андрей Зорькин on 24.01.17.
//  Copyright © 2017 Андрей Зорькин. All rights reserved.
//

#include <stdio.h>
#include "Screen.hpp"

#include <unistd.h>


extern std::vector<std::string> hello;
std::vector<std::string> good_bye{
    {},
    {"                _    _        _          _         _"},
    {"               / /\\ /\\ \\     /\\_\\       /\\ \\      /\\_\\"},
    {"              / /  \\\\ \\ \\   / / /      /  \\ \\    / / /"},
    {"             / / /\\ \\\\ \\ \\_/ / /      / /\\ \\ \\  / / /_"},
    {"            / / /\\ \\ \\\\ \\___/ /      / / /\\ \\_\\/ /___/\\"},
    {"           / / /\\ \\_\\ \\\\ \\ \\_/      / /_/_ \\/_/\\____ \\ \\"},
    {"          / / /\\ \\ \\___\\\\ \\ \\      / /____/\\       / / /"},
    {"         / / /  \\ \\ \\__/ \\ \\ \\    / /\\____\\/      / / /"},
    {"        / / /____\\_\\ \\    \\ \\ \\  / / /______     _\\/_/"},
    {"       / / /__________\\    \\ \\_\\/ / /_______\\   /\\_\\"},
    {"       \\/_____________/     \\/_/\\/__________/   \\/_/"},
    {}
};

bool Screen::screenMain(std::string input){
    if (input == "help"){
        addLine("nh       : set new header");
        addLine("rh       : remove header");
        addLine("clear    : clear screen");
        addLine("exit     : exit");
        addLine("hello    : to say hello");
        addLine("hi       : to say hi");
        addLine("size     : ");
        addLine("scr_full : set full screen");
        addLine("scr_def  : set default screen");
        updateScreen();
        return true;
    }
    if (input == "hello" || input == "hi"){
        addText(hello);
        updateScreen();
        return true;
    }
    if (input == "exit" || input == "bye" || input == "пока"){
        addLine("Good bye!");
        addText(good_bye);
        updateScreen();
        end = true;
        exit(0);
        return true;
    }
    if (input == "nh"){
        //addLine("Input new Header Title");
        updateScreen();
        std::string header = inputString();
        updateHeader(header);
        updateScreen();
        return true;
    }
    if (input == "rh"){
        addLine("Header was removed");
        updateScreen();
        makeFrame();
        updateScreen();
        return true;
    }
    if (input == "clear"){
        clearScreen();
        updateScreen();
        return true;
    }
    if (input == "size"){
        addLine("Input width");
        updateScreen();
        int w = inputInt();
        updateScreen();
        addLine("Input hight");
        updateScreen();
        int h = inputInt();
        updateScreen();
        initScreen(w, h);
        clearScreen();
        updateHeader("default");
        updateScreen();
        return true;
    }
    if (input == "scr_full"){
        initScreen(181, 55);
        updateHeader("default");
        clearScreen();
        updateScreen();
        return true;
    }
    if (input == "scr_def"){
        initScreen(80, 22);
        updateHeader("default");
        clearScreen();
        updateScreen();
        return true;
    }
    return false;
}
