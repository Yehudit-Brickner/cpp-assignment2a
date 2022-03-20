

#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Notebook.hpp"






    void ariel::Notebook:: write( unsigned int page,unsigned int row, unsigned int column, Direction d, string txt){
        cout << "this function should write" << endl;
    }


    string ariel::Notebook::read(unsigned int page,unsigned int row,unsigned int column, Direction d,unsigned int length){
        cout << "this function should read" << endl;
        return "somthing";
    }

    void ariel::Notebook::erase(unsigned int page, unsigned int row, unsigned int column, Direction d,unsigned int length){
        cout << "this function should erase" << endl;
    }

    void ariel::Notebook::show(unsigned int page){
        cout << "this function should show" << endl;
    }


