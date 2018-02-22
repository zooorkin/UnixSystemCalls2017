//
//  main.cpp
//  UnixSystemCalls2017
//
//  Created by Андрей Зорькин on 23.01.17.
//  Copyright © 2017 Андрей Зорькин. All rights reserved.
//

#include <iostream>
#include "Screen.hpp"

#include <unistd.h>
#include <signal.h>

int main(int argc, const char * argv[]) {
    

    
    Screen S{true};
    S.main();
    
    return 0;
}
