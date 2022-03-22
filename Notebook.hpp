

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

            std::map<unsigned int, Page> _pageMap;

        public:
           

            void write( int page,  int row, int column, Direction d, string txt);
            string read( int page,  int row,  int column, Direction d,  int length);
            void erase( int page,  int row,  int column, Direction d,  int length);
            void show( int page);
           
                       
            
            void addPage(  int num){
                if(_pageMap.find(num)==_pageMap.end()){ // check if the page exsits
                    Page p;
                    _pageMap.insert( pair<unsigned int, Page>(num, p)); // if not create new page
                }
            }

            
            Notebook(){
                addPage(0);
            }
    };

}; 