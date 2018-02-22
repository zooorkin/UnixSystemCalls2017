//
//  StackMain.cpp
//  UnixSystemCalls2017
//
//  Created by Андрей Зорькин on 24.01.17.
//  Copyright © 2017 Андрей Зорькин. All rights reserved.
//

#include "Screen.hpp"

bool Screen::stackMain(std::string input){
    if (input == "s_help"){
        addLine("s_new   : make new stack");
        addLine("s_add   : add new element");
        addLine("s_pr    : print stack");
        addLine("s_c     : count");
        addLine("s_at    : show element at index");
        addLine("s_rm_a  : remove all stacks");
        addLine("s_div   : divide");
        addLine("s_def   : stacks by default");
        addLine("s_copy  : copy stack");
        addLine("s_rm_el : removes element");
        addLine("s_unite : unite stacks");
        updateScreen();
        return true;
    }
    if (input == "s_copy") {
        addLine("Choose the stack");
        updateScreen();
        int number_of_stack = inputInt();
        if (number_of_stack > Andrew_stacks.size() || number_of_stack <= 0){
            addLine("Stack with the same number is not exist");
            updateScreen();
            return true;
        }
        Andrew_stacks.push_back(Andrew_stacks[number_of_stack - 1]);
        addLine("Copied");
        updateScreen();
        return true;
    }
    if (input == "s_def"){
        lab5::stack movies{};
        movies.push(lab5::movie{"Forrest Gump", "1994"});
        movies.push(lab5::movie{"Inception", "2010"});
        movies.push(lab5::movie{"A Beautiful Mind", "2001"});
        movies.push(lab5::movie{"Back to the Future", "1985"});
        movies.push(lab5::movie{"One Flew Over the Cuckoo's Nest", "1975"});
        
        lab5::stack movies_pixar{};
        movies_pixar.push(lab5::movie{"WALL-E", "2008"});
        movies_pixar.push(lab5::movie{"Up", "2009"});
        movies_pixar.push(lab5::movie{"Inside Out", "2015"});
        movies_pixar.push(lab5::movie{"Monsters, Inc", "2001"});
        
        lab5::stack movies_music{};
        movies_music.push(lab5::movie{"Metallica: Through the Never", "2013"});
        
        Andrew_stacks.clear();
        Andrew_stacks.push_back(movies);
        Andrew_stacks.push_back(movies_pixar);
        Andrew_stacks.push_back(movies_music);
        
        addLine("done");
        
        updateScreen();
        return true;
    }
    if (input == "s_new"){
        Andrew_stacks.push_back(lab5::stack{});
        addLine("New stack was created");
        updateScreen();
        return true;
    }
    if (input == "s_add"){
        if (Andrew_stacks.size() == 0){
            addLine("There is no any stack to add new element");
            updateScreen();
            return true;
        }
        
        addLine("Choose the stack");
        updateScreen();
        int number_of_stack = inputInt();
        if (number_of_stack > Andrew_stacks.size() || number_of_stack <= 0){
            addLine("Stack with the same number is not exists");
            updateScreen();
            return true;
        }
        
        
        addLine("Input name");
        updateScreen();
        std::string name = inputString();
        
        addLine("Input year");
        updateScreen();
        std::string yearString = inputString();
        
        lab5::movie movie{name, yearString};
        Andrew_stacks[number_of_stack - 1].push(movie);
        addLine("Pushed");
        updateScreen();
        return true;
    }
    if (input == "s_pr"){
        if (Andrew_stacks.size() > 0){
            addLine("Array of stacks contains:");
            for (int each_stack = 0; each_stack < Andrew_stacks.size(); ++each_stack){
                addLine("   Stack #" + std::to_string(1 + each_stack) + " contains:");
                
                if (Andrew_stacks[each_stack].count() > 0){
                    for (int i = 0; i < Andrew_stacks[each_stack].count(); ++i){
                        lab5::movie m = Andrew_stacks[each_stack].at_index(i);
                        std::string s = "       " +std::to_string(1 + i) + " " + m.name + ", " + m.year;
                        addLine(s);
                    }
                }else{
                    addLine("       nothing");
                }
                
            }
        }else{
            addLine("There is no any stack");
        }
        updateScreen();
        return true;
    }
    if (input == "s_c"){
        if (Andrew_stacks.size() > 0){
            for (int each_stack = 0; each_stack < Andrew_stacks.size(); ++each_stack){
                std::string s = "Stack #" + std::to_string(1 + each_stack) + " contains ";
                s   += std::to_string(Andrew_stacks[each_stack].count()) + " elements";
                addLine(s);
            }
        }else{
            addLine("There is no any stack");
        }
        updateScreen();
        return true;
    }
    if (input == "s_at"){
        
        addLine("Choose the stack");
        updateScreen();
        int number_of_stack = inputInt();
        if (number_of_stack > Andrew_stacks.size() || number_of_stack <= 0){
            addLine("Stack with the same number is not exist");
            updateScreen();
            return true;
        }
        
        addLine("Choose the element");
        updateScreen();
        int number_of_element = inputInt();
        if (number_of_element > Andrew_stacks[number_of_stack - 1].count() || number_of_element <= 0){
            addLine("Element with the same number is not exist");
            updateScreen();
            return true;
        }
        
        lab5::movie m = Andrew_stacks[number_of_stack - 1].at_index(number_of_element - 1);
        std::string info = m.name + ", " + m.year;
        addLine(info);
        
        updateScreen();
        return true;
    }
    if (input == "s_rm_el"){
        
        addLine("Choose the stack");
        updateScreen();
        int number_of_stack = inputInt();
        if (number_of_stack > Andrew_stacks.size() || number_of_stack <= 0){
            addLine("Stack with the same number is not exist");
            updateScreen();
            return true;
        }
        
        addLine("Choose the element");
        updateScreen();
        int number_of_element = inputInt();
        if (number_of_element > Andrew_stacks[number_of_stack - 1].count() || number_of_element <= 0){
            addLine("Element with the same number is not exist");
            updateScreen();
            return true;
        }
        
        lab5::movie m = Andrew_stacks[number_of_stack - 1].at_index(number_of_element - 1);

        Andrew_stacks[number_of_stack - 1].remove(m);
        addLine("Done...");
        updateScreen();
        return true;
    }
    if (input == "s_rm_a"){
        Andrew_stacks.clear();
        addLine("All stacks removed");
        updateScreen();
        return true;
    }
    if (input == "s_div"){
        addLine("Choose the stack");
        updateScreen();
        int number_of_stack = inputInt();
        if (number_of_stack > Andrew_stacks.size() || number_of_stack <= 0){
            addLine("Stack with the same number is not exist");
            updateScreen();
            return true;
        }
        
        addLine("Choose length");
        updateScreen();
        int length = inputInt();
        if (length > Andrew_stacks[number_of_stack - 1].count() || length <= 0){
            addLine("Wrong length");
            updateScreen();
            return true;
        }
        lab5::stack temp_stack = Andrew_stacks[number_of_stack - 1].sub_stack(length);
        Andrew_stacks.push_back(temp_stack);
        addLine("Divided");
        updateScreen();
        return true;
        
    }
    if (input == "s_unite"){
        addLine("Choose the stack");
        updateScreen();
        int number_of_stack = inputInt();
        if (number_of_stack > Andrew_stacks.size() || number_of_stack <= 0){
            addLine("Stack with the same number is not exist");
            updateScreen();
            return true;
        }
        addLine("Choose the stack");
        updateScreen();
        int number_of_stack2 = inputInt();
        if (number_of_stack2 > Andrew_stacks.size() || number_of_stack2 <= 0){
            addLine("Stack with the same number is not exist");
            updateScreen();
            return true;
        }
        
        
        Andrew_stacks[number_of_stack - 1] = Andrew_stacks[number_of_stack - 1] + Andrew_stacks[number_of_stack2 - 1];
        
        for (int i = number_of_stack2 - 1; i < Andrew_stacks.size() + 1; ++i){
            Andrew_stacks[i] = Andrew_stacks[i + 1];
        }
        Andrew_stacks.pop_back();
        
        
        addLine("done...");
        updateScreen();
        return true;
        
    }
    return false;
}
