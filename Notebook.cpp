

#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

#include "Notebook.hpp"

    



    void ariel::Notebook::write( unsigned int page,unsigned int row, unsigned int column, Direction d, string txt){
        
        cout << "this function should write" << endl;
        if (column+txt.size()>=100){
            throw std::invalid_argument( "the text goes out of bound of the row" );
        }

        std::string reading=ariel::Notebook::read(page,row,column,d,txt.size());
        for(unsigned int i=0;i<txt.size();i++){
            if(reading[i]!='_'){
                 throw std::invalid_argument( "the text is trying to over write other text or marked out text" );
            }
        }
        if (d==Direction::Horizontal){
            unsigned int j=0;
            for(unsigned int i=column; i<column+txt.size();i++){
                _pageMap[page]._rowMap[row]._row[i]=txt[j];
                j++;
            } 
        }
        else{
            for(unsigned int i=0; i<txt.size();i++){
                _pageMap[page]._rowMap[row]._row[column]=txt[i];    
            }  
        }
    }


    string ariel::Notebook::read(unsigned int page,unsigned int row,unsigned int column, Direction d,unsigned int length){
        cout << "this function should read" << endl;
        if (column+length>=100){
            throw std::invalid_argument( "the text goes out of bound of the row" );
        }

        // check if page exsists, if not add the page
        if(_pageMap.find(page)==_pageMap.end()){ 
            Page p;
            _pageMap.insert( pair<unsigned int, Page>(page, p)); 
        }


        std::string ans;

        if (d==Direction::Horizontal){
            if(_pageMap[page]._rowMap.find(row)==_pageMap[page]._rowMap.end()){
                Row r;
                _pageMap[page]._rowMap.insert(pair<unsigned int,Row>(row,r));
                for( unsigned int i=column; i<column+length;i++){
                    ans.push_back(_pageMap[page]._rowMap[row]._row[i]);
                }
            }
            else{
                for( unsigned int i=column; i<column+length;i++){
                    ans.push_back(_pageMap[page]._rowMap[row]._row[i]);
                } 
            }
            return ans;
        }
        else{
            for (unsigned int i=row; i<=row+length;i++){
               if(_pageMap[page]._rowMap.find(i)==_pageMap[page]._rowMap.end()){
                    Row r;
                    _pageMap[page]._rowMap.insert(pair<unsigned int,Row>(i,r));
                    ans.push_back(_pageMap[page]._rowMap[row]._row[column]);
                }
                else{
                    ans.push_back(_pageMap[page]._rowMap[row]._row[column]);
                }
                return ans;
            }
        }

        
        

        return "somthing";
    }

    void ariel::Notebook::erase(unsigned int page, unsigned int row, unsigned int column, Direction d,unsigned int length){
        cout << "this function should erase" << endl;
        if (column+length>=100){
            throw std::invalid_argument( "the text goes out of bound of the row" );
        }
    }

    void ariel::Notebook::show(unsigned int page){
        cout << "this function should show" << endl;
    }


