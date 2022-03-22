


    // void ariel::Notebook::write(  int page, int row,  int column, Direction d, string txt){
    // const  int max=100; 
    //   //  cout << "this function should write" << endl;
    //   
    //     if(d==Direction::Horizontal){
    //         // cout<< "horizantal1" << endl;
    //         if (column+txt.size()>=max){
    //             //cout << "threw exception" << endl;
    //             throw std::invalid_argument( "the text goes out of bound of the row" );
    //         }
    //     }
    //     else{
    //         //  cout<< "vertical1" << endl;
    //         if (column>max){
    //           //  cout << "threw exception" << endl;
    //             throw std::invalid_argument( "the text goes out of bound of the row" );  
    //         }
    //     }
    //     std::string reading=ariel::Notebook::read(page,row,column,d,txt.size());
    //     for( int i=0;i<txt.size();i++){
    //         if(reading[i]!='_'){
    //              throw std::invalid_argument( "the text is trying to over write other text or marked out text" );
    //         }
    //     }
    //     if (d==Direction::Horizontal){
    //          int j=0;
    //         //cout<< "trying to change the row" << endl; 
    //         for( int i=column; i<column+txt.size();i++){
    //             _pageMap[page]._rowMap[row]._row[i]=txt[j];
    //             // char *cptr =&_pageMap[page]._rowMap[row]._row[i];
    //             // *cptr=txt[j];   
    //             j++;
    //         } 
    //         //cout<< "hopefully changed the row" << endl; 
    //     }
    //     else{
    //         //cout<< "trying to change the columns" << endl;
    //          int j=0; 
    //         for( int i=row; i<row+txt.size();i++){
    //             _pageMap[page]._rowMap[i]._row[column]=txt[j]; 
    //             // char *cptr =&_pageMap[page]._rowMap[i]._row[column];
    //             // *cptr=txt[j];
    //             j++; 
    //         } 
    //       //  cout<<"hopefully changed the columns" << endl;  
    //     }
    // }

    // string ariel::Notebook::read( int page, int row, int column, Direction d, int length){
    //     const int max=100; 
    //     //cout << "this function should read" << endl;
    //     //cout << "page num " << page << "row num " << row << "column num  "<< column << "  length  " << length<< endl; 
    //     if(d==Direction::Horizontal){
    //         // cout<< "horizantal1" << endl;
    //         if (column+length>=max){
    //       //      cout << "threw exception" << endl;
    //             throw std::invalid_argument( "the text goes out of bound of the row" );
    //         }
    //     }
    //     else{
    //         // cout<< "vertical1" << endl;
    //         if (column>max){
    //         //    cout << "threw exception" << endl;
    //           throw std::invalid_argument( "the text goes out of bound of the row" );  
    //         }
    //     }
    //
    //     // check if page exsists, if not add the page
    //     // cout<< "check page" << endl;
    //     if(_pageMap.find(page)==_pageMap.end()){ 
    //         Page p;
    //         _pageMap.insert( pair< int, Page>(page, p)); 
    //     }
    //     // cout<< "finish check page" << endl;        
    //   
    //     std::string ans;
    //
    //     if (d==Direction::Horizontal){
    //         // cout<< "horizantal2" << endl;
    //         // cout<< "check row" << endl;
    //         if(_pageMap[page]._rowMap.find(row)==_pageMap[page]._rowMap.end()){
    //             Row r;
    //             _pageMap[page]._rowMap.insert(pair< int,Row>(row,r));
    //           //  cout<< "finish check row" << endl;
    //             for(  int i=column; i<column+length;i++){
    //                 ans.push_back(_pageMap[page]._rowMap[row]._row[i]);
    //                 //cout<< ans<< endl;
    //             }
    //             //cout<< ans<< "  finish"<<endl;
    //         }
    //         else{
    //             for(  int i=column; i<column+length;i++){
    //                 ans.push_back(_pageMap[page]._rowMap[row]._row[i]);
    //             } 
    //             //cout<< ans<< "  finish" <<endl;
    //         }
    //         return ans;
    //     }
    //     // cout<< "vertical1" << endl;
    //     for ( int i=row; i<row+length;i++){
    //           //cout << "row num is  "<< i<<  "  column is  "<<column<< endl;
    //         if(_pageMap[page]._rowMap.find(i)==_pageMap[page]._rowMap.end()){
    //             Row r;
    //             _pageMap[page]._rowMap.insert(pair< int,Row>(i,r));
    //             ans.push_back(_pageMap[page]._rowMap[i]._row[column]);
    //             //char c= _pageMap[page]._rowMap[i]._row[column];
    //             //cout <<"added row then char  "<< c<< endl;
    //         }
    //         else{
    //             ans.push_back(_pageMap[page]._rowMap[i]._row[column]);
    //             //char c= _pageMap[page]._rowMap[i]._row[column];
    //             //cout <<"row exsists added char  "<< c<< endl;
    //         }
    //     }
    //     //cout << ans <<" finish"<< endl;
    //     return ans;
    //     // return "somthing";
    //
    // }

    // void ariel::Notebook::erase( int page,  int row,  int column, Direction d, int length){
    //       const  int max=100; 
    //   //  cout << "this function should erase" << endl;
    //     if(d==Direction::Horizontal){
    //         // cout<< "horizantal1" << endl;
    //         if (column+length>=max){
    //            // cout << "threw exception" << endl;
    //             throw std::invalid_argument( "the text goes out of bound of the row" );
    //         }
    //     }
    //     else{
    //         //  cout<< "vertical1" << endl;
    //         if (column>=max){
    //            // cout << "threw exception" << endl;
    //             throw std::invalid_argument( "the text goes out of bound of the row" );  
    //         }
    //     }
    //   
    //     if (d==Direction::Horizontal){
    //         // int j=0;
    //        // cout<< "trying to change the row" << endl; 
    //         for( int i=column; i<column+length;i++){
    //             _pageMap[page]._rowMap[row]._row[i]='~';
    //             // char *cptr =&_pageMap[page]._rowMap[row]._row[i];
    //             // *cptr='~';   
    //             //j++;
    //         } 
    //        // cout<< "hopefully changed the row" << endl; 
    //     }
    //     else{
    //         //cout<< "trying to change the columns" << endl;
    //         // int j=0; 
    //         for( int i=row; i<row+length;i++){
    //             _pageMap[page]._rowMap[i]._row[column]='~'; 
    //             // char *cptr =&_pageMap[page]._rowMap[i]._row[column];
    //             // *cptr='~';
    //            // j++; 
    //         } 
    //         //cout<<"hopefully changed the columns" << endl;  
    //     }
    //
    // }

    // void ariel::Notebook::show( int page){
    //     cout << "this function should show" << endl;
    // }


