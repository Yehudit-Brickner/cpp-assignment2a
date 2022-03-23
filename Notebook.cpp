

#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

#include "Notebook.hpp"

     





    // void ariel::Notebook::write(  int page, int row,  int column, Direction d, string txt){
    //     cout << "this function should write somthing" << endl;
    // }
    // string ariel::Notebook::read( int page,  int row,  int column, Direction d,  int length){
    //     cout << "this function should read somthing" << endl;
    //     return "somthing";
    // }
    // void ariel::Notebook::erase( int page,  int row,  int column, Direction d,  int length){
    //     cout << "this function should erase somthing" << endl;
    // }
    // void ariel::Notebook::show( int page){
    //     cout << "this function should show somthing" << endl;
    // }





    void ariel::Notebook::write(  int page, int row,  int column, Direction d, string txt){
        
        

        if(page<0 ||row<0 ||column<0){
            throw std::invalid_argument( "the page or row or column is negative" );
        }

        for (std::string::size_type i = 0; i < txt.size(); i++){
            if(txt.at(i)=='~'){
                throw std::invalid_argument( "the text has an illegal symbol" );  
            }
        }
        
        //cout << "this function should write" << endl;

        int max=100;
        int txt_length=txt.length(); 

        if(d==Direction::Horizontal){
            if (column+txt_length>=max){
                throw std::invalid_argument( "the text goes out of bound of the row" );
            }
        }
        else{
            if (column>max){
                throw std::invalid_argument( "the text goes out of bound of the row" );  
            }
        }
        std::string reading=ariel::Notebook::read(page,row,column,d,txt.size());
        for( std::string::size_type i = 0; i < txt.size(); i++){
            if(reading[i]!='_'){
                 throw std::invalid_argument( "the text is trying to over write other text or marked out text" );
            }
        }
        if (d==Direction::Horizontal){
             std::string::size_type j=0;
            for( int i=column; i<column+txt_length;i++){
                _pageMap[page]._rowMap[row]._row[i]=txt[j];   
                j++;
            } 
        }
        else{
            std::string::size_type j=0; 
            for( int i=row; i<row+txt_length;i++){
                _pageMap[page]._rowMap[i]._row[column]=txt[j]; 
                j++; 
            } 
        }
    }

    string ariel::Notebook::read( int page, int row, int column, Direction d, int length){
         

        if(page<0 ||row<0 ||column<0 || length<0){
            throw std::invalid_argument( "the page or row or column or length is negative" );
        }
      

        //cout << "this function should read" << endl;
        
        
        int max=100;
        if(d==Direction::Horizontal){
            if (column+length>=max){
                throw std::invalid_argument( "the text goes out of bound of the row" );
            }
        }
        else{
            if (column>max){
              throw std::invalid_argument( "the text goes out of bound of the row" );  
            }
        }
    
        // check if page exsists, if not add the page
        if(_pageMap.find(page)==_pageMap.end()){ 
            Page p;
            _pageMap.insert( pair< int, Page>(page, p)); 
        }    
      
        std::string ans;

        //horizantal
        if (d==Direction::Horizontal){
            if(_pageMap[page]._rowMap.find(row)==_pageMap[page]._rowMap.end()){
                Row r;
                _pageMap[page]._rowMap.insert(pair< int,Row>(row,r));
                for(  int i=column; i<column+length;i++){
                    ans.push_back(_pageMap[page]._rowMap[row]._row[i]);
                }   
            }
            else{
                for(  int i=column; i<column+length;i++){
                    ans.push_back(_pageMap[page]._rowMap[row]._row[i]);
                } 
            }
            return ans;
        }
        //vertical
        for ( int i=row; i<row+length;i++){
            if(_pageMap[page]._rowMap.find(i)==_pageMap[page]._rowMap.end()){
                Row r;
                _pageMap[page]._rowMap.insert(pair< int,Row>(i,r));
                ans.push_back(_pageMap[page]._rowMap[i]._row[column]);
            }
            else{
                ans.push_back(_pageMap[page]._rowMap[i]._row[column]);
            }
        }
        return ans;
        //return "somthing";
    
    }



    void ariel::Notebook::erase( int page,  int row,  int column, Direction d, int length){

         if(page<0 ||row<0 ||column<0 || length<0){
            throw std::invalid_argument( "the page or row or column or length is negative" );
        }
         
        //cout << "this function should erase" << endl;
        
        
        int max=100; 
        if(d==Direction::Horizontal){
            if (column+length>=max){
                throw std::invalid_argument( "the text goes out of bound of the row" );
            }
        }
        else{
            if (column>=max){
                throw std::invalid_argument( "the text goes out of bound of the row" );  
            }
        }
      
        if (d==Direction::Horizontal){
            for( int i=column; i<column+length;i++){
                _pageMap[page]._rowMap[row]._row[i]='~';
            } 
        }
        else{
            for( int i=row; i<row+length;i++){
                _pageMap[page]._rowMap[i]._row[column]='~'; 
            }   
        }
    
    }

    void ariel::Notebook::show( int page){
        
        if(page<0 ){
            throw std::invalid_argument( "the page is negative" );
        }
        //cout << "this function should show" << endl;
    }


