

 


#include "doctest.h"
#include "Notebook.hpp"
#include <string>
#include <vector>
#include <ctime>
#include <random>
using ariel::Direction;


ariel::Notebook notebook1;
ariel::Notebook notebook2;
ariel::Notebook notebook3;
ariel::Notebook notebook4;


TEST_CASE("good write and read"){
    
    notebook1.write(/*page*/0,  /*row*/0,  /*column*/0,  Direction::Horizontal,"hello world");
    CHECK(notebook1.read(/*page*/0,  /*row*/0,  /*column*/0,  Direction::Horizontal,11)=="hello world");
    
    notebook2.write(/*page*/0,  /*row*/0,  /*column*/0,  Direction::Horizontal,"cpp is fun");
    CHECK(notebook2.read(/*page*/0,  /*row*/0,  /*column*/0,  Direction::Horizontal,10)=="cpp is fun");
    
    notebook1.write(/*page*/0,/*row*/1, /*column*/1,Direction::Vertical,"ABCD");
    CHECK(notebook1.read(/*page*/0,  /*row*/1,  /*column*/1,  Direction::Vertical,4)=="ABCD");

    notebook1.write(/*page*/1,/*row*/1, /*column*/1,Direction::Vertical,"even thogh this is a very long sentence (longer than 100 chars) this will be okay because it is vertical and not horazantal");
    CHECK(notebook1.read(/*page*/1,  /*row*/1,  /*column*/1,  Direction::Vertical,123)=="even thogh this is a very long sentence (longer than 100 chars) this will be okay because it is vertical and not horazantal");

 }

TEST_CASE("bad write"){
    CHECK_THROWS(notebook1.write(/*page*/0,  /*row*/0,  /*column*/10,  Direction::Horizontal,"cpp is fun"));  // cant write over somthing written
    CHECK_THROWS(notebook1.write(/*page*/0,  /*row*/4,  /*column*/1,  Direction::Horizontal,"DEFG"));  // cant write over somthing written
    CHECK_THROWS(notebook1.write(/*page*/0,  /*row*/0,  /*column*/95,  Direction::Horizontal,"cpp is fun"));  //goes out of bounds in the end of the row  
    CHECK_THROWS(notebook1.write(/*page*/0,  /*row*/5,  /*column*/0,  Direction::Horizontal,"this is not going to run because it has to many letters!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"));  //goes out of bounds in the end of the row 
}


TEST_CASE("negative number write"){
    CHECK_THROWS(notebook4.write(/*page*/-1,  /*row*/0,  /*column*/0,  Direction::Horizontal,"hello world")); // negative page
    CHECK_THROWS(notebook4.write(/*page*/0,  /*row*/-1,  /*column*/0,  Direction::Horizontal,"hello world")); // negative row
    CHECK_THROWS(notebook4.write(/*page*/-1,  /*row*/0,  /*column*/-1,  Direction::Horizontal,"hello world")); // negative column

    CHECK_THROWS(notebook4.write(/*page*/-1,  /*row*/0,  /*column*/0,  Direction::Vertical,"hello world")); // negative page
    CHECK_THROWS(notebook4.write(/*page*/0,  /*row*/-1,  /*column*/0,  Direction::Vertical,"hello world")); // negative row
    CHECK_THROWS(notebook4.write(/*page*/-1,  /*row*/0,  /*column*/-1,  Direction::Vertical,"hello world")); // negative column
}


TEST_CASE("bad read"){
    
    CHECK_THROWS(notebook1.read(/*page*/0,  /*row*/0,  /*column*/90,  Direction::Horizontal,11)); // goes out of bounds in the end of the row
    CHECK_THROWS(notebook1.read(/*page*/0,  /*row*/0,  /*column*/0,  Direction::Horizontal,101)); // goes out of bounds in the end of the row    
}

TEST_CASE("negative number read"){
    CHECK_THROWS(notebook4.read(/*page*/-1,  /*row*/0,  /*column*/0,  Direction::Horizontal,5)); // negative page 
    CHECK_THROWS(notebook4.read(/*page*/0,  /*row*/-1,  /*column*/0,  Direction::Horizontal,5)); // negative row
    CHECK_THROWS(notebook4.read(/*page*/0,  /*row*/0,  /*column*/-1,  Direction::Horizontal,5)); // negative column
    CHECK_THROWS(notebook4.read(/*page*/0,  /*row*/0,  /*column*/0,  Direction::Horizontal,-1)); // negative length

    CHECK_THROWS(notebook4.read(/*page*/-1,  /*row*/0,  /*column*/0,  Direction::Vertical,5)); // negative page 
    CHECK_THROWS(notebook4.read(/*page*/0,  /*row*/-1,  /*column*/0,  Direction::Vertical,5)); // negative row
    CHECK_THROWS(notebook4.read(/*page*/0,  /*row*/0,  /*column*/-1,  Direction::Vertical,5)); // negative column
    CHECK_THROWS(notebook4.read(/*page*/0,  /*row*/0,  /*column*/0,  Direction::Vertical,-1)); // negative length 
}


TEST_CASE("good erase and read"){
    notebook1.erase(/*page*/0,  /*row*/0,  /*column*/0,  Direction::Horizontal,11);
    CHECK(notebook1.read(/*page*/0,  /*row*/0,  /*column*/0,  Direction::Horizontal,11)=="~~~~~~~~~~~");
    
    notebook1.erase(/*page*/0,/*row*/1, /*column*/1,Direction::Vertical,4);   
    notebook1.erase(/*page*/0,/*row*/3, /*column*/0,Direction::Horizontal,4);

    CHECK(notebook1.read(/*page*/0,  /*row*/0,  /*column*/0,  Direction::Horizontal,5)=="~~~~~"); // erased hello world from row 1
    CHECK(notebook1.read(/*page*/0,  /*row*/1,  /*column*/0,  Direction::Horizontal,5)=="_~___"); // erased ABCD from column 1
    CHECK(notebook1.read(/*page*/0,  /*row*/2,  /*column*/0,  Direction::Horizontal,5)=="_~___"); // erased ABCD from column 1
    CHECK(notebook1.read(/*page*/0,  /*row*/3,  /*column*/0,  Direction::Horizontal,5)=="~~~~_"); // erased ABCD from column 1 and the first for places in row 3
    CHECK(notebook1.read(/*page*/0,  /*row*/4,  /*column*/0,  Direction::Horizontal,5)=="_~___"); // erased ABCD from column 1
}

TEST_CASE("bad erase"){
    
    CHECK_THROWS(notebook1.erase(/*page*/0,  /*row*/0,  /*column*/90,  Direction::Horizontal,11)); // goes out of bounds in the end of the row
    CHECK_THROWS(notebook1.erase(/*page*/0,  /*row*/0,  /*column*/100,  Direction::Vertical,11)); // goes out of bounds in the end of the row
    CHECK_THROWS(notebook1.erase(/*page*/0,  /*row*/0,  /*column*/0,  Direction::Horizontal,101)); // goes out of bounds in the end of the row    
}



TEST_CASE("negative number erase"){
    CHECK_THROWS(notebook4.erase(/*page*/-1,  /*row*/0,  /*column*/0,  Direction::Horizontal,5)); // negative page
    CHECK_THROWS(notebook4.erase(/*page*/0,  /*row*/-1,  /*column*/0,  Direction::Horizontal,5)); // negative row
    CHECK_THROWS(notebook4.erase(/*page*/0,  /*row*/0,  /*column*/-1,  Direction::Horizontal,5)); // negative column
    CHECK_THROWS(notebook4.erase(/*page*/0,  /*row*/0,  /*column*/0,  Direction::Horizontal,-1)); // negative length

    CHECK_THROWS(notebook4.erase(/*page*/-1,  /*row*/0,  /*column*/0,  Direction::Vertical,5)); // negative page
    CHECK_THROWS(notebook4.erase(/*page*/0,  /*row*/-1,  /*column*/0,  Direction::Vertical,5)); // negative row
    CHECK_THROWS(notebook4.erase(/*page*/0,  /*row*/0,  /*column*/-1,  Direction::Vertical,5)); // negative column
    CHECK_THROWS(notebook4.erase(/*page*/0,  /*row*/0,  /*column*/0,  Direction::Vertical,-1)); // negative length
}

TEST_CASE("loop1"){

    for (int i=0; i<110;i++){
        if(i<=88){
            notebook3.write(/*page*/i,  /*row*/i,  /*column*/i,  Direction::Horizontal,"hello world");
            CHECK(notebook3.read(/*page*/i,  /*row*/i,  /*column*/i,  Direction::Horizontal,11)=="hello world"); 
        }
        else{
            CHECK_THROWS(notebook3.write(/*page*/i,  /*row*/i,  /*column*/i,  Direction::Horizontal,"hello world")); // the words become out of bounds or start out of bounds
        }
    }
}

TEST_CASE("loop2"){

    
    for ( int i=32; i<126;i++){
        std::string txt1;
        txt1.push_back(i);
        notebook3.write(/*page*/0,  /*row*/i,  /*column*/2, Direction::Horizontal,txt1);
        std::string txt2="_____";
        txt2.at(2)=i;
        CHECK(notebook3.read(/*page*/0,  /*row*/i,  /*column*/0,  Direction::Horizontal,5)==txt2); 
    }
    
}

TEST_CASE("speacial symbol"){
    notebook2.write(/*page*/10,  /*row*/10,  /*column*/10,  Direction::Horizontal,"hello \n world");
    CHECK(notebook2.read(/*page*/10,  /*row*/10,  /*column*/10,  Direction::Horizontal,13)=="hello \n world");

    notebook2.write(/*page*/20,  /*row*/10,  /*column*/10,  Direction::Horizontal,"hello \r world");
    CHECK(notebook2.read(/*page*/20,  /*row*/10,  /*column*/10,  Direction::Horizontal,13)=="hello \r world");

    notebook2.write(/*page*/30,  /*row*/10,  /*column*/10,  Direction::Horizontal,"hello \t world");
    CHECK(notebook2.read(/*page*/30,  /*row*/10,  /*column*/10,  Direction::Horizontal,13)=="hello \t world");

    notebook2.write(/*page*/11,  /*row*/10,  /*column*/10,  Direction::Vertical,"hello \n world");
    CHECK(notebook2.read(/*page0*/11,  /*row*/10,  /*column*/10,  Direction::Vertical,13)=="hello \n world");

    notebook2.write(/*page*/21,  /*row*/10,  /*column*/10,  Direction::Vertical,"hello \r world");
    CHECK(notebook2.read(/*page*/21,  /*row*/10,  /*column*/10,  Direction::Vertical,13)=="hello \r world");

    notebook2.write(/*page*/31,  /*row*/10,  /*column*/10,  Direction::Vertical,"hello \t world");
    CHECK(notebook2.read(/*page*/31,  /*row*/10,  /*column*/10,  Direction::Vertical,13)=="hello \t world");

    CHECK_THROWS(notebook3.write(/*page*/40,  /*row*/1,  /*column*/1,  Direction::Horizontal,"~~~")); // you cant write a '~'
    CHECK_THROWS(notebook3.write(/*page*/40,  /*row*/1,  /*column*/1,  Direction::Vertical,"~~~")); // you cant write a '~'
    CHECK_THROWS(notebook3.write(/*page*/40,  /*row*/1,  /*column*/1,  Direction::Vertical,"a~c")); // you cant write a '~'
    CHECK_THROWS(notebook3.write(/*page*/40,  /*row*/1,  /*column*/1,  Direction::Horizontal,"a~c")); // you cant write a '~'
 
}

TEST_CASE("using _"){
    ariel::Notebook notebook5;
    



}
