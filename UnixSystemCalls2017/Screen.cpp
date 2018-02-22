//
//  Screen.cpp
//  UnixSystemCalls2017
//
//  Created by Андрей Зорькин on 23.01.17.
//  Copyright © 2017 Андрей Зорькин. All rights reserved.
//

#include <iostream>
#include <vector>
#include "Screen.hpp"
#include "stack_lab5.hpp"

#define default_x 3
#define default_y 2

//Slant
std::vector<std::string> hello{
    {"    __  __     ____      __"},
    {"   / / / /__  / / /___  / /"},
    {"  / /_/ / _ \\/ / / __ \\/ /"},
    {" / __  /  __/ / / /_/ /_/"},
    {"/_/ /_/\\___/_/_/\\____(_)"},
    {}
};

void Screen::main(){
    addText(hello);
    updateScreen();
    while (end != true){
        std::string input = inputString();
        
        if (screenMain(input) || stackMain(input) || unixMain(input)){
            continue;
        }
        if (myFunctions(input)){
            continue;
        }
        
        addLine("Error command (for help input \"help\", \"s_help\", \"man\")");
        updateScreen();
    }
}

std::string Screen::inputString(){
    std::string s;
    std::cin >> s;
    addLine("> " + s);
    return s;
}

int Screen::inputInt(){
    std::string s;
    std::cin >> s;
    addLine("> " + s);
    for (int i = 0; i < s.length(); ++i){
        switch (s[i]) {
            case '0': break;
            case '1': break;
            case '2': break;
            case '3': break;
            case '4': break;
            case '5': break;
            case '6': break;
            case '7': break;
            case '8': break;
            case '9': break;
            default:  return -1;
        }
    }
    int i = std::stoi(s);
    return i;
}

std::string makeString(std::vector<std::string> vector){
    std::string string{};
    for (auto symbol: vector){
        string += symbol;
    }
    return string;
}

Screen::Screen(bool frame, int width, int hight){
    x = default_x;
    y = default_y;
    fullScreen = false;
    
    initScreen(width, hight);
    if (frame){
        makeFrame();
    }
    updateHeader("Program_01");
}

void Screen::initScreen(int width, int hight){
    screen = std::vector<std::vector<std::string>>{};
    for (int y = 0; y < hight; ++y){
        std::vector<std::string> line{};
        for (int x = 0; x < width; ++x){
            line.push_back(" ");
        }
        this->width = width;
        this->hight = hight;
        screen.push_back(line);
    }
}

void Screen::add(std::string text, int x, int y){
    if (x >= 0 && x + text.length() <= width &&
        y < hight && y >= 0){

        for (int i = 0; i < text.length(); ++i){
            screen[y][x + i] = text[i];
        }
        ++y;
        
    }else{
        errorOfPainting();
    }
}

void Screen::addLine(std::string text){
    if (y >= 2 && y <= hight - 2){
        add(text, x, y);
    }else if (y == hight - 1){
        for (int i = 2; i <= hight - 3; ++i){
            screen[i] = screen[i + 1];
        }
        y = hight - 2;
        clearLine(y);
        add(text, x, y);
    }
    ++y;
}

void Screen::addText(std::vector<std::string> text){
    for (auto line: text){
        addLine(line);
    }
}

void Screen::errorOfPainting(){
    add(" ERROR_OF_PAINTING ", 2,0);
}
/*
 auto add(block: [String], at: (int x, int y)){
 var j = 0;
 for each in block{
 add(each text, at: (at.x, at.y + j));
 j += 1;
 }
 }
 
 auto paint(){
 s.screen[7][ i + 1] = "S";
 i = ( 1 + i ) % (width - 2);
 }
 */
void Screen::updateScreen(){
    
    // updateTime();
    std::cout << '\n';
    for(auto stroka: screen){
        std::string line = makeString(stroka);
        std::cout << line << '\n';
        //std::wcout<< line << '\n';
    }
    //paint();
    //usleep(60000) //60 Герц
}

void Screen::clearLine(int y){
        for (int x = frame; x < width - 1 - frame; ++x){
            screen[y][x] = " ";
        }
}

void Screen::clearScreen(){
    for (int y = frame; y <= hight - 1 - frame; ++y)
        clearLine(y);
    y = default_y;
}

void Screen::makeFrame(){
    for (int y = 0; y < hight; ++y){
        for (int x = 0; x < width; ++x){
            if (x == 0 && y == 0){
                screen[y][x] = upLeft;
                continue;
            }
            if (x == width - 1 && y == 0){
                screen[y][x] = upRight;
                continue;
            }
            if (x == 0 && y == hight - 1){
                screen[y][x] = downLeft;
                continue;
            }
            if (x == width - 1 && y == hight - 1){
                screen[y][x] = downRight;
                continue;
            }
            if (x == 0 || x == width - 1){
                screen[y][x] = vertical;
                continue;
            }
            if (y == 0 || y == hight - 1){
                screen[y][x] = horizontal;
                continue;
            }
        }
    }
    frame = true;
}

void Screen::updateHeader(std::string text){
    if (text == "default"){
        text = headerText;
    }
    headerText = text;
    if (frame == true){
        makeFrame();
    }
    std::string s = " " + text + " ";
    add(s, 2, 0);
}

void Screen::changeScreenSize(){
    this->fullScreen = !fullScreen;
    if(fullScreen){
        initScreen(181, 55);
    }else{
        initScreen(80, 22);
    }
    updateScreen();
}

/*
 auto updateTime(){
 let date = NSDate();
 let calendar = NSCalendar.current;
 /
 var hour: int{
 return calendar.component(.hour, date from as Date);
 }
 var minute: int{
 return calendar.component(.minute, date from as Date);
 }
 var second: int{
 return  calendar.component(.second, date from as Date);
 }
 var a = ""; var b = ""; var c = "";
 if (hour < 10 ){ a = "0"}
 if (minute < 10 ){ b = "0"}
 if (second < 10 ){ c = "0" }
 
 add(text: "╡\(a)\(hour):\(b)\(minute):\(c)\(second)╞", at: ( width - 12, 0));
 }
 */


