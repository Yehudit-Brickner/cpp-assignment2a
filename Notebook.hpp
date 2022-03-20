#pragma once

#include <stdexcept>
#include <string>
#include <iostream>
#include <vector>
#include "Direction.hpp"
#include "Page.hpp"

using namespace std;



namespace ariel{ 

    class Notebook{


        
        private:

            // std::map<int, Page> _pageMap;

        public:
            std::map<int, Page> _pageMap;


            void write(unsigned int page, unsigned int row,unsigned int column, Direction d, string txt);
            string read(unsigned int page, unsigned int row, unsigned int column, Direction d, unsigned int length);
            void erase(unsigned int page, unsigned int row, unsigned int column, Direction d, unsigned int length);
            void show(unsigned int page);
           
            
            

            
            void addPage(int num){
                if(_pageMap.find(num)==_pageMap.end()){ // check if the page exsits
                    Page p;
                    _pageMap.insert( pair<int, Page>(num, p)); // if not create new page
                }
            }

            
            Notebook(){
                _pageMap;
                addPage(0);
            }
    };

}; 