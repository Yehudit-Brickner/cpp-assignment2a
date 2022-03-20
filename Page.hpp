#pragma once


#include <stdexcept>
#include <string>
#include <iostream>
//#include <vector>
#include <map>
#include "Row.hpp"
using namespace std;
 

class Page{

      
        
        std::map<int, Row> _rowMap;

    public:     

        void addRow(int num){
            if(_rowMap.find(num)==_rowMap.end()){ // check if the row exsits
                Row r;
                _rowMap.insert( pair<int, Row>(num, r)); // if not create new row 
            }
        }

        Page(){
            addRow(0);
        }
        
       

};