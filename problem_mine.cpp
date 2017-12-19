// imports the libraries for the game 
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cstring>
#include <time.h>


// using namespace
using namespace std;

 
/**
 * function to check the index that user entered for a cell. 
 * Comparing it with the width and height of the game's grid.
 * 
 * @ int r ,int c , int height , int width
 **/
bool isValid(int r, int c, int height, int width){
    return ((r>=0)&&(r<height)&&(c>=0)&&(c<width));
    
}



void printGridNow(int width,int height,char **boardValues){
    
    // Saleh: I'm working on fixing the style here
    
    if(width==10){
        
        cout<< "\n==========================================="<<endl;
        cout<< "* Beginner Level Mineswepeer.             *"<<endl;
        cout<< "===========================================\n"<<endl;
        cout<<"+ - + - + - + - + - + - + - + - + - + - + - +"<<endl;
        cout<<"|   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |"<<endl;
        for (int row=0; row < height ; row++){
            cout<<"+ - + - + - + - + - + - + - + - + - + - + - +"<<endl;
            for(int column=0; column < width ; column++){
                if(column==0)
                cout<<"| "<<row<<" ";
                cout<<"| "<< boardValues[row][column]<<" ";
            }
            cout<<"|"<<endl;
        }
        cout<<"+ - + - + - + - + - + - + - + - + - + - + - +"<<endl;
    }
    else if(width==20){
        cout<< "\n"<<"==========================================="<<endl;
        cout<<       "* Intermediate Level Mineswepeer.         *"<<endl;
        cout<<       "==========================================="<<"\n"<<endl;
        cout<<"+ - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +"<<endl;
        cout<<"|   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10 |11 |12 |13 |14 |15 |16 |17 |18 |19 |"<<endl;
        for (int row=0; row < height ; row++){
            
            cout<<"+ - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +"<<endl;
            for(int column=0; column < width ; column++){
                if(column==0){
                    if (row<10)
                        cout<<"| "<<row<<" ";
                    else
                        cout<<"|"<<row<<" ";
                }
                cout<<"| "<< boardValues[row][column]<<" ";
            }
            cout<<"|"<<endl;
        }
        cout<<"+ - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +"<<endl;
    }
    else {
        cout<< "\n"<<"==========================================="<<endl;
        cout<<       "* Advance Level Mineswepeer.              *"<<endl;
        cout<<       "==========================================="<<"\n"<<endl;
        cout<<"+ - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +";
        cout<<" - + - + - + - + - + - + - + - + - + - +"<<endl;
        cout<<"|   | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |10 |11 |12 |13 |14 |15 |16 |17 |18 |19 |";
        cout<<"20 |21 |22 |23 |24 |25 |26 |27 |28 |29 |"<<endl;
        for (int row=0; row < height ; row++){
            cout<<"+ - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +";
            cout<<" - + - + - + - + - + - + - + - + - + - +"<<endl;
            for(int column=0; column < width ; column++){
                if(column==0){
                    if (row<10)
                        cout<<"| "<<row<<" ";
                    else
                        cout<<"|"<<row<<" ";
                }
                cout<<"| "<< boardValues[row][column]<<" ";
            }
            cout<<"|"<<endl;
        }
        cout<<"+ - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - + - +";
        cout<<" - + - + - + - + - + - + - + - + - + - +"<<endl;
    }
}


void buildGrid(int width,int height,char **boardValues){
    // Saleh: I'm working on fixing the style here
    for (int row=0; row < height ; row++){
        for(int column=0; column < width ; column++){
           boardValues[row][column]= '-';
        }
    }
}

void neighbor(char **tempValues, char **tempValues1, int playerHeight, int playerWidth, int height, int width){
     if(!(tempValues1[playerHeight][playerWidth]!='0')){
                if(isValid(playerHeight+1,playerWidth-1,height,width)){tempValues1[playerHeight+1][playerWidth-1]=tempValues[playerHeight+1][playerWidth-1];}
                if(isValid(playerHeight+1,playerWidth,height,width)){tempValues1[playerHeight+1][playerWidth]=tempValues[playerHeight+1][playerWidth];}
                if(isValid(playerHeight+1,playerWidth+1,height,width)){tempValues1[playerHeight+1][playerWidth+1]=tempValues[playerHeight+1][playerWidth+1];}
                if(isValid(playerHeight,playerWidth-1,height,width)){tempValues1[playerHeight][playerWidth-1]=tempValues[playerHeight][playerWidth-1];}
                if(isValid(playerHeight,playerWidth+1,height,width)){tempValues1[playerHeight][playerWidth+1]=tempValues[playerHeight][playerWidth+1];}
                if(isValid(playerHeight-1,playerWidth-1,height,width)){tempValues1[playerHeight-1][playerWidth-1]=tempValues[playerHeight-1][playerWidth-1];}
                if(isValid(playerHeight-1,playerWidth,height,width)){tempValues1[playerHeight-1][playerWidth]=tempValues[playerHeight-1][playerWidth];}
                if(isValid(playerHeight-1,playerWidth+1,height,width)){tempValues1[playerHeight-1][playerWidth+1]=tempValues[playerHeight-1][playerWidth+1];}}
}

void play(int width, int height, char **boardValues,char **tempValues, char **tempValues1, int flag_count, int numberMines){
    int playerWidth;
    int playerHeight;
    int flag=0;
    cout<<"Enter the value of the height ";
    cin>>playerHeight;
    while((playerHeight>height-1)||(playerHeight<0)){
        cout<<"INVALID INPUT!!"<<endl;
        cout<<"Enter the value of the height ";
        cin.clear();
        cin.ignore(256,'\n');
        cin>>playerHeight;
        
    }
    cout<<"Enter the value of the width ";
    cin>>playerWidth;    
    while((playerWidth>0)||(playerWidth<width-1)){
        cout<<"INVALID INPUT!!"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"Enter the value of the width ";
        cin>>playerWidth;
    }
    while((flag>=0)||(flag<=1)){
        cout<<"INVALID INPUT!!"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
    cout<<"Do you want to insert flag?(0 or 1) ";
    cin>>flag;
    }
   
    
    tempValues1[playerHeight][playerWidth]=tempValues[playerHeight][playerWidth];
    if((flag==1) && (!(tempValues1[playerHeight][playerWidth]!='*'))){
        flag_count++;
    }
    if(flag==1){ 
        tempValues1[playerHeight][playerWidth]= '#';
        printGridNow(width,height,tempValues1);
        play(width,height,boardValues,tempValues,tempValues1,flag_count,numberMines);
    }
    else{
        if(!(boardValues[playerHeight][playerWidth]!='*')){
            printGridNow(width,height,boardValues);
            cout<<"YOU LOST!!!"<<endl;
            for(int i=0;i<100000;i++){
                for(int x=0;x<500;x++);
            }
            exit(0);
        }
        else{
            //buildGrid(width,height,boardValues);
            //boardValues[playerHeight][playerWidth]= tempValues[playerHeight][playerWidth];
            if(!(tempValues1[playerHeight][playerWidth]!='0')){
                if(isValid(playerHeight+1,playerWidth-1,height,width)){tempValues1[playerHeight+1][playerWidth-1]=tempValues[playerHeight+1][playerWidth-1];
                    if(!(tempValues[playerHeight+1][playerWidth-1]!='0')){ neighbor(tempValues,tempValues1,playerHeight+1,playerWidth-1,height,width);}
                }
                if(isValid(playerHeight+1,playerWidth,height,width)){tempValues1[playerHeight+1][playerWidth]=tempValues[playerHeight+1][playerWidth];
                    if(!(tempValues[playerHeight+1][playerWidth]!='0')){ neighbor(tempValues,tempValues1,playerHeight+1,playerWidth,height,width);}
                }
                if(isValid(playerHeight+1,playerWidth+1,height,width)){tempValues1[playerHeight+1][playerWidth+1]=tempValues[playerHeight+1][playerWidth+1];
                    if(!(tempValues[playerHeight+1][playerWidth+1]!='0')){ neighbor(tempValues,tempValues1,playerHeight+1,playerWidth+1,height,width);}
                }
                if(isValid(playerHeight,playerWidth-1,height,width)){tempValues1[playerHeight][playerWidth-1]=tempValues[playerHeight][playerWidth-1];
                    if(!(tempValues[playerHeight][playerWidth-1]!='0')){ neighbor(tempValues,tempValues1,playerHeight,playerWidth-1,height,width);}
                }
                if(isValid(playerHeight,playerWidth+1,height,width)){tempValues1[playerHeight][playerWidth+1]=tempValues[playerHeight][playerWidth+1];
                    if(!(tempValues[playerHeight][playerWidth+1]!='0')){ neighbor(tempValues,tempValues1,playerHeight,playerWidth+1,height,width);}
                }
                if(isValid(playerHeight-1,playerWidth-1,height,width)){tempValues1[playerHeight-1][playerWidth-1]=tempValues[playerHeight-1][playerWidth-1];
                    if(!(tempValues[playerHeight-1][playerWidth-1]!='0')){ neighbor(tempValues,tempValues1,playerHeight-1,playerWidth-1,height,width);}
                }
                if(isValid(playerHeight-1,playerWidth,height,width)){tempValues1[playerHeight-1][playerWidth]=tempValues[playerHeight-1][playerWidth];
                    if(!(tempValues[playerHeight-1][playerWidth]!='0')){ neighbor(tempValues,tempValues1,playerHeight-1,playerWidth,height,width);}
                }
                if(isValid(playerHeight-1,playerWidth+1,height,width)){tempValues1[playerHeight-1][playerWidth+1]=tempValues[playerHeight-1][playerWidth+1];
                    if(!(tempValues[playerHeight-1][playerWidth+1]!='0')){ neighbor(tempValues,tempValues1,playerHeight-1,playerWidth+1,height,width);}
                }
            }
            printGridNow(width,height,tempValues1);
            play(width,height,boardValues,tempValues,tempValues1,flag_count,numberMines);
        }
    }
    if(flag_count==numberMines){
        cout<<"YOU WIN"<<endl;
    }
        
}

void buildMines(int width,int height, char **boardValues, int numberMines, int playerHeight, int playerWidth){
    int mineRow;
    int mineCol;
    int i=0;
    srand(time(NULL));
    while(i<numberMines){
        mineRow=rand() % height + 0;
        mineCol=rand() % width + 0;
        if((mineRow!=playerHeight) &&(mineCol!=playerWidth)){
            if(boardValues[mineRow][mineCol]== '*');
            else{
                boardValues[mineRow][mineCol]= '*';
                //cout<<"("<<mineRow<<","<<mineCol<<")";
                i=i+1;
            }
        }
        //cout<<i<<"  "<<endl;
    }
    
}


void buildValues(int width, int height, char **boardValues, int numberMines, char **tempValues){
    int count=0;
    
    for(int r=0;r<height;r++){
        for(int c=0;c<width;c++){
            if(boardValues[r][c]!= '*'){
                if(isValid((r+1),(c-1),height,width)){
                    if(boardValues[r+1][c-1]== '*') count++;
                }
                if(isValid((r+1),(c),height,width)){
                    if(boardValues[r+1][c]== '*') count++;
                }
                if(isValid((r+1),(c+1),height,width)){
                    if(boardValues[r+1][c+1]== '*') count++;
                }
                if(isValid((r),(c-1),height,width)){
                    if(boardValues[r][c-1]== '*') count++;
                }
                if(isValid((r),(c+1),height,width)){
                    if(boardValues[r][c+1]== '*') count++;
                }
                if(isValid((r-1),(c-1),height,width)){
                    if(boardValues[r-1][c-1]== '*') count++;
                }
                if(isValid((r-1),(c),height,width)){
                    if(boardValues[r-1][c]== '*') count++;
                }
                if(isValid((r-1),(c+1),height,width)){
                    if(boardValues[r-1][c+1]== '*') count++;
                }
                tempValues[r][c]=count+'0';
            }
            
            else{tempValues[r][c]='*';}
            count=0;
            //cout<<tempValues[r][c];
        }
    }
}

void first_choice(int width,int height,char **boardValues,char **tempValues, char **tempValues1,int numberMines){
    int playerHeight;
    int playerWidth;
    int flag;
    int flag_count=0;
    cout<<"Enter the value of the height ";
    cin>>playerHeight;
    while((playerHeight>0)||(playerHeight<height-1)){
        cout<<"INVALID INPUT!!"<<endl;
        cout<<"Enter the value of the height ";
        cin.clear();
        cin.ignore(256,'\n');
        cin>>playerHeight;
        
    }
    cout<<"Enter the value of the width ";
    cin>>playerWidth;    
    while((playerWidth>0)||(playerWidth<width-1)){
        cout<<"INVALID INPUT!!"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"Enter the value of the width ";
        cin>>playerWidth;
    }
    while((flag>=0)||(flag<=1)){
        cout<<"INVALID INPUT!!"<<endl;
        cin.clear();
        cin.ignore(256,'\n');
    cout<<"Do you want to insert flag?(0 or 1) ";
    cin>>flag;
    }
    buildMines(width,height,boardValues,numberMines,playerHeight,playerWidth);
    buildValues(width,height,boardValues,numberMines,tempValues);
    tempValues1[playerHeight][playerWidth]=tempValues[playerHeight][playerWidth];
    if((flag==1) && (!(tempValues1[playerHeight][playerWidth]!='*'))){
        flag_count++;
    }
    if(flag==1){ 
        tempValues1[playerHeight][playerWidth]= '#';
        printGridNow(width,height,tempValues1);
    }
    
    else{
            //buildGrid(width,height,boardValues);
            //boardValues[playerHeight][playerWidth]= tempValues[playerHeight][playerWidth];
            if(!(tempValues1[playerHeight][playerWidth]!='0')){
                if(isValid(playerHeight+1,playerWidth-1,height,width)){tempValues1[playerHeight+1][playerWidth-1]=tempValues[playerHeight+1][playerWidth-1];
                    if(!(tempValues[playerHeight+1][playerWidth-1]!='0')){ neighbor(tempValues,tempValues1,playerHeight+1,playerWidth-1,height,width);}
                }
                if(isValid(playerHeight+1,playerWidth,height,width)){tempValues1[playerHeight+1][playerWidth]=tempValues[playerHeight+1][playerWidth];
                    if(!(tempValues[playerHeight+1][playerWidth]!='0')){ neighbor(tempValues,tempValues1,playerHeight+1,playerWidth,height,width);}
                }
                if(isValid(playerHeight+1,playerWidth+1,height,width)){tempValues1[playerHeight+1][playerWidth+1]=tempValues[playerHeight+1][playerWidth+1];
                    if(!(tempValues[playerHeight+1][playerWidth+1]!='0')){ neighbor(tempValues,tempValues1,playerHeight+1,playerWidth+1,height,width);}
                }
                if(isValid(playerHeight,playerWidth-1,height,width)){tempValues1[playerHeight][playerWidth-1]=tempValues[playerHeight][playerWidth-1];
                    if(!(tempValues[playerHeight][playerWidth-1]!='0')){ neighbor(tempValues,tempValues1,playerHeight,playerWidth-1,height,width);}
                }
                if(isValid(playerHeight,playerWidth+1,height,width)){tempValues1[playerHeight][playerWidth+1]=tempValues[playerHeight][playerWidth+1];
                    if(!(tempValues[playerHeight][playerWidth+1]!='0')){ neighbor(tempValues,tempValues1,playerHeight,playerWidth+1,height,width);}
                }
                if(isValid(playerHeight-1,playerWidth-1,height,width)){tempValues1[playerHeight-1][playerWidth-1]=tempValues[playerHeight-1][playerWidth-1];
                    if(!(tempValues[playerHeight-1][playerWidth-1]!='0')){ neighbor(tempValues,tempValues1,playerHeight-1,playerWidth-1,height,width);}
                }
                if(isValid(playerHeight-1,playerWidth,height,width)){tempValues1[playerHeight-1][playerWidth]=tempValues[playerHeight-1][playerWidth];
                    if(!(tempValues[playerHeight-1][playerWidth]!='0')){ neighbor(tempValues,tempValues1,playerHeight-1,playerWidth,height,width);}
                }
                if(isValid(playerHeight-1,playerWidth+1,height,width)){tempValues1[playerHeight-1][playerWidth+1]=tempValues[playerHeight-1][playerWidth+1];
                if(!(tempValues[playerHeight-1][playerWidth+1]!='0')){ neighbor(tempValues,tempValues1,playerHeight-1,playerWidth+1,height,width);}
                }
            }
            printGridNow(width,height,tempValues1);
            play(width,height,boardValues,tempValues,tempValues1,flag_count,numberMines);
        }
    
    play(width,height,boardValues,tempValues,tempValues1,flag_count,numberMines);
}

void initialization(){
    int ucerChoose=1;// default
    int width;
    int height;
    int numberMines;
    
    cout<< "==========================================="<<endl;
    cout<< "* Please select the level of the game:    *"<<endl;
    cout<< "*-----------------------------------------*"<<endl;
    cout<< "* 1- For beginner (10 x 10).              *"<<endl;
    cout<< "* 2- For intermediate (20 x 20).          *"<<endl;
    cout<< "* 3- For advanced (30 x 30).              *"<<endl;
    cout<< "==========================================="<<endl;
    
    
    cin>> ucerChoose;
    if (ucerChoose < 1 || ucerChoose>3){
        cout<< "Error 1: You should type the number that correspond to the level."<<endl;
    }
    else {
        if(ucerChoose==1){
            cout<<"choose the number of mines(20 to 98): ";
            cin>>numberMines;
            while((numberMines>98) ||(numberMines<20)){
                cout<<"Error :The number of mines, should be a number between (20 to 98): ";
                cin.clear();
                cin.ignore(256,'\n');
             cin>>numberMines;
            }
            width=10;
            height =10; // defualt
            //numberMines =20; //defualt max =100
            char** boardValues = new char*[height];
            
            for(int i = 0; i < height; i++){
                boardValues[i] = new char[width];
            }
            char** tempValues = new char*[height];
            for(int i = 0; i < height; i++){
                tempValues[i] = new char[width];
            }
            char** tempValues1 = new char*[height];
            for(int i = 0; i < height; i++){
                tempValues1[i] = new char[width];
            }
            buildGrid(width, height,tempValues1);
            buildGrid(width, height,boardValues);
            buildGrid(width,height,tempValues);
            printGridNow(width, height,boardValues);
            first_choice(width,height,boardValues,tempValues,tempValues1,numberMines);
        }
        else if(ucerChoose==2){
            cout<<"choose the number of mines(80 to 300): ";
            cin>>numberMines;
            while((numberMines>300) ||(numberMines<80)){
                cout<<"Error :The number of mines, should be a number between (80 to 300): ";
                cin.clear();
                cin.ignore(256,'\n');
             cin>>numberMines;
            }
            width=20;
            height =20; // defualt
            //numberMines =80; //defualt max= 400
            char** boardValues = new char*[height];
            
            for(int i = 0; i < height; i++){
                boardValues[i] = new char[width];
            }
            char** tempValues = new char*[height];
            for(int i = 0; i < height; i++){
                tempValues[i] = new char[width];
            }
            char** tempValues1 = new char*[height];
            for(int i = 0; i < height; i++){
                tempValues1[i] = new char[width];
            }
            buildGrid(width, height,tempValues1);
            buildGrid(width, height,boardValues);
            buildGrid(width,height,tempValues);
            printGridNow(width, height,boardValues);
            first_choice(width,height,boardValues,tempValues,tempValues1,numberMines);
        }
        else{
            cout<<"choose the number of mines(180 to 500): ";
            cin>>numberMines;
            while((numberMines>500) ||(numberMines<180)){
                cout<<"Error :The number of mines, should be a number between (180 to 500): ";
                cin.clear();
                cin.ignore(256,'\n');
             cin>>numberMines;
            }
            width=30;
            height= 30; // defualt
           // numberMines =180; //defualt max=900
            char** boardValues = new char*[height];
            
            for(int i = 0; i < height; i++){
                boardValues[i] = new char[width];
            }
            char** tempValues = new char*[height];
            for(int i = 0; i < height; i++){
                tempValues[i] = new char[width];
            }
            char** tempValues1 = new char*[height];
            for(int i = 0; i < height; i++){
                tempValues1[i] = new char[width];
            }
            buildGrid(width, height,tempValues1);
            buildGrid(width, height,boardValues);
            buildGrid(width,height,tempValues);
            printGridNow(width, height,boardValues);
            first_choice(width,height,boardValues,tempValues,tempValues1,numberMines);
        }
        
        
    }
    
    //cout<< "the number user pick is "<< ucerChoose;
    
}




int main(int argc, char* argv[])
{
        // these are boolean flags to set if the player win or lose
    bool won =false; 
    bool lost=false;
     //check if the game get argument
    if(argc !=1){
        cout << "Error : The game accept no arguments. " << endl;
        return -1;
    }
    initialization();
    // we should have a loop here to keep the player play untill either win or lose became true.
    
    
    return 0;
}