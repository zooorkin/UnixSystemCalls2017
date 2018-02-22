//
//  UnixMain.cpp
//  UnixSystemCalls2017
//
//  Created by Андрей Зорькин on 24.01.17.
//  Copyright © 2017 Андрей Зорькин. All rights reserved.
//

#include "Screen.hpp"
#include <unistd.h>

void f(int sig){
    if (sig == SIGALRM){
        std::cout<< "ALARM!\n";
        usleep(500000);
        std::cout<< "ALARM!\n";
        usleep(500000);
        std::cout<< "ALARM!\n";
        
    } else
        std::cout << "interrupt\n";
}

bool Screen::unixMain(std::string input){
    
    if (input == "getpid"){
        std::string s = std::to_string(getpid());
        addLine("ID of the current process is " + s);
        updateScreen();
        return true;
    }
    
    if (input == "getppid"){
        std::string s = std::to_string(getppid());
        addLine("ID of the parent of the current process is " + s);
        updateScreen();
        return true;
    }
    
    if (input == "alarm"){
        addLine("Input amount of seconds");
        updateScreen();
        int seconds = inputInt();
        updateScreen();
        // Обработка сигнала f
        signal(SIGALRM, f);
        alarm(seconds);
        return true;
    }
    
    if (input == "fchdir"){
        addLine("Input file descriptor");
        updateScreen();
        int fd = inputInt();
        updateScreen();
        int res = fchdir(fd);
        if (res == 0){
            addLine("Success");
        }else{
            addLine("Error");
        }
        updateScreen();
        return true;
    }
    
    if (input == "chdir"){
        addLine("Input path");
        updateScreen();
        std::string path = inputString();
        updateScreen();
        int res = chdir(path.c_str());
        if (res == 0){
            addLine("Success");
        }else{
            addLine("Error");
        }
        updateScreen();
        return true;
    }

    if (input == "getcwd" || input == "pwd"){
        char path[1024];
        char *res = getcwd(path, sizeof(path));
        addLine(std::string(path));
        updateScreen();
        return true;
    }
    
    if (input == "_def"){
        addLine("_def");
        updateScreen();
        return true;
    }
    if (input == "man"){
        addLine("getpid  : ID of the current process");
        addLine("getppid : ID of the parent of the current process");
        addLine("alarm   : to make interrupt by alarm");
        addLine("chdir : ");
        addLine("fchdir : ");
        addLine("getcwd : ");
        addLine("pwd : ");
//                addLine(" : ");
        updateScreen();
        return true;
    }
    return false;
}
