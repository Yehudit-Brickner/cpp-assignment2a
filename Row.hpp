#pragma once

#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
using namespace std;




class Row{
   
    private:
        std::vector<char> _row;

    public:    
        // constructer
        Row(){
            _row.reserve(100);
                for ( unsigned int i=0; i<100; i++){
                    _row[i]='_';
                }    
        }  
            
};


