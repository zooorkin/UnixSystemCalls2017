//
//  Screen.hpp
//  UnixSystemCalls2017
//
//  Created by Андрей Зорькин on 23.01.17.
//  Copyright © 2017 Андрей Зорькин. All rights reserved.
//

#ifndef Screen_hpp
#define Screen_hpp
#include <vector>

#include <iostream>
#include "stack_lab5.hpp"

const std::string vertical = "║";
const std::string horizontal = "═";
const std::string upLeft = "╔";
const std::string upRight = "╗";
const std::string downLeft = "╚";
const std::string downRight = "╝";

std::string makeString(std::vector<std::string> vector);

//////////////////////////////////////
//                                  //
//              SCREEN              //
//                                  //
//////////////////////////////////////

class Screen{
public:
    
    // Добавление строчки
    void addLine(std::string text);
    //
    void addText(std::vector<std::string> text);
    // Инициализация
    Screen(bool frame = true, int width = 80, int hight = 22);
    // Запуск главного интерфейса
    void main();
    
    void changeScreenSize();
private:
    std::string inputString();
    int inputInt();
    // Инициализация экрана
    void initScreen(int width, int hight);
    // Очищение экрана
    void clearScreen();
    // Ошибка прорисовки
    void errorOfPainting();
    // Рисовка заглавия
    void updateHeader(std::string text);
    // Очистка линии
    void clearLine(int);
    //
    bool screenMain(std::string input);
    //
    bool stackMain(std::string input);
    //
    bool unixMain(std::string input);
    //
    bool myFunctions(std::string input);
    // Обновление экрана
    void updateScreen();
    // Добавление рамки
    void makeFrame();
    // Добавление текста
    void add(std::string text, int x, int y);
    std::vector<std::vector<std::string>> screen{};
    int width;
    int hight;
    bool frame = false;
    std::string headerText{};
    bool end = false;
    
    std::vector<lab5::stack> Andrew_stacks{};
   // lab5::stack Andrew{};
   // lab5::stack Nastya{};
    
    // Координаты
    int x;
    int y;
    bool fullScreen;
};

//#include <stdio.h>

#endif /* Screen_hpp */
