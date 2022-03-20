#pragma once


#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Notebook.hpp"




void write(int page, int row, int column, Direction d, string txt){
    cout << "this function should write" << endl;
}


string read(int page, int row, int column, Direction d, int length){
    cout << "this function should read" << endl;
    return "somthing";
}

void erase(int page, int row, int column, Direction d, int length){
    cout << "this function should erase" << endl;
}

void show(int page){
    cout << "this function should show" << endl;
}


