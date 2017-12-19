
#include <iostream>
#include <stdlib.h>
#include <string>
#include<cstring>

using namespace std;

void printGridNow(int width,int height,char **boardValues){
    
    // Saleh: working here now 
    
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
        cout<<"- = coverd  # = flaged  "<<endl;
        
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
        cout<<"- = coverd  # = flaged  "<<endl;

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
        cout<<"- = coverd  # = flaged  "<<endl;

        
    }
    
    
}
void buildGrid(int width,int height,char **boardValues){
    // Saleh: filling the grid with empty char -
    for (int row=0; row < height ; row++){
        for(int column=0; column < width ; column++){
           boardValues[row][column]= '-';
        }
    }
    
}
void buildMines(int width,int height, char **boardValues, int numberMines, int playerWidth,int playerHeight){
    int mineRow;
    int mineCol;
    int i=0;
    while(i<numberMines){
        mineRow=rand() % height + 0;
        mineCol=rand() % width + 0;
        if((playerHeight!=mineRow) && (playerWidth!=mineCol)){
        if(boardValues[mineRow][mineCol]== '*'){
            i++;
            continue;
        }
        else{
            boardValues[mineRow][mineCol]= '*';
            i++;
        }
    }
    }
}

bool isValid(int r, int c, int height, int width){
    return ((r>=0)&&(r<height)&&(c>=0)&&(c<width));
    
}

void buildValues(int width, int height, char **boardValues, int numberMines, char **tempValues){
    int count=0;
    
    for(int r=0;r<height;r++){
        for(int c=0;c<width;c++){
            if(boardValues[r][c]!= '*'){
                if(isValid((r+1),(c-1),height,width)){
                    if(!(boardValues[r+1][c-1]!= '*')) count++;
                }
                if(isValid((r+1),(c),height,width)){
                    if((boardValues[r+1][c]!= '*')) count++;
                }
                if(isValid((r+1),(c+1),height,width)){
                    if((boardValues[r+1][c+1]!= '*')) count++;
                }
                if(isValid((r),(c-1),height,width)){
                    if((boardValues[r][c-1]!= '*')) count++;
                }
                if(isValid((r),(c+1),height,width)){
                    if((boardValues[r][c+1]!= '*')) count++;
                }
                if(isValid((r-1),(c-1),height,width)){
                    if((boardValues[r-1][c-1]!= '*')) count++;
                }
                if(isValid((r-1),(c),height,width)){
                    if((boardValues[r-1][c]!= '*')) count++;
                }
                if(isValid((r-1),(c+1),height,width)){
                    if((boardValues[r-1][c+1]!= '*')) count++;
                }
                tempValues[r][c]=count+'0';
            }
            
            else{tempValues[r][c]='*';}
            count=0;
            //cout<<tempValues[r][c];
        }
    }
}



void play(int width, int height, char **boardValues,char **tempValues, char **tempValues1, int numberMines, int countt){
    int playerWidth;
    int playerHeight;
    int flag=0;
    int count2;
    cout<<"Enter the value's position in X axis:";
    cin>>playerHeight;
    cout<<"Enter the value's position in Y axis:";
    cin>>playerWidth;
    if((playerHeight<0)||(playerHeight>=height)||(playerWidth<0)||(playerWidth>=width)){
        cout<<"Error: Incorret Value!"<<endl;
        play(width,height,boardValues,tempValues,tempValues1,numberMines,count2);
    }
    cout<<"Do you want to insert flag?(0 or 1) ";
    cin>>flag;
    cout<<countt;
    if(countt==0){
        buildMines(width,height,boardValues,numberMines,playerWidth,playerHeight);
        buildValues(width,height,boardValues,numberMines,tempValues);
        
    }
    cout<<tempValues[playerHeight][playerWidth];
    count2=countt+1;
    tempValues1[playerHeight][playerWidth]=tempValues[playerHeight][playerWidth];
    if(flag==1){ 
        tempValues1[playerHeight][playerWidth]= '#';
        printGridNow(width,height,tempValues1);
        play(width,height,boardValues,tempValues,tempValues1,numberMines,count2);
    }
    else{
        if(!(boardValues[playerHeight][playerWidth]!='*')){
            printGridNow(width,height,boardValues);
            cout<<"YOU LOST!!!"<<endl;}
        else{
            //buildGrid(width,height,boardValues);
            //boardValues[playerHeight][playerWidth]= tempValues[playerHeight][playerWidth];
            if(!(tempValues1[playerHeight][playerWidth]!='0')){
                tempValues1[playerHeight+1][playerWidth-1]=tempValues[playerHeight+1][playerWidth-1];
                tempValues1[playerHeight+1][playerWidth]=tempValues[playerHeight+1][playerWidth];
                tempValues1[playerHeight+1][playerWidth+1]=tempValues[playerHeight+1][playerWidth+1];
                tempValues1[playerHeight][playerWidth-1]=tempValues[playerHeight][playerWidth-1];
                tempValues1[playerHeight][playerWidth+1]=tempValues[playerHeight][playerWidth+1];
                tempValues1[playerHeight-1][playerWidth-1]=tempValues[playerHeight-1][playerWidth-1];
                tempValues1[playerHeight-1][playerWidth]=tempValues[playerHeight-1][playerWidth];
                tempValues1[playerHeight-1][playerWidth+1]=tempValues[playerHeight-1][playerWidth+1];
            printGridNow(width,height,tempValues1);
            play(width,height,boardValues,tempValues,tempValues1,numberMines,count2);
        }
        else{
            printGridNow(width,height,tempValues1);
            play(width,height,boardValues,tempValues,tempValues1,numberMines,count2);
        }
        }
    }
    
        
}


void initialization(){
    int ucerChoose=1;// default
    int width;
    int height;
    int numberMines;
    int count1=0;
    
    cout<< "==========================================="<<endl;
    cout<< "* Please select the level of the game:    *"<<endl;
    cout<< "*-----------------------------------------*"<<endl;
    cout<< "* 1- For beginner (10 x 10).              *"<<endl;
    cout<< "* 2- For intermediate (20 x 20).          *"<<endl;
    cout<< "* 3- For advanced (30 x 30).              *"<<endl;
    cout<< "==========================================="<<endl;
    
    
    cin>> ucerChoose;
    if (ucerChoose < 1 || ucerChoose>3){
        cout<< "Error 1: You should type the number that crosspond to the level."<<endl;
    }
    else {
        if(ucerChoose==1){
            width=10;
            height =10; // defualt
            numberMines =20; //defualt max =100
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
            //buildMines(width,height,boardValues,numberMines);
    //buildValues(width,height,boardValues,numberMines,tempValues);
    play(width,height,boardValues,tempValues,tempValues1,numberMines,count1);
            
        }
        else if(ucerChoose==2){
            width=20;
            height =20; // defualt
            numberMines =80; //defualt max= 400
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
            //buildMines(width,height,boardValues,numberMines);
    //buildValues(width,height,boardValues,numberMines,tempValues);
    play(width,height,boardValues,tempValues,tempValues1,numberMines,count1);
        }
        else{
            width=30;
            height= 30; // defualt
            numberMines =180; //defualt max=900
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
            //buildMines(width,height,boardValues,numberMines);
    //buildValues(width,height,boardValues,numberMines,tempValues);
    play(width,height,boardValues,tempValues,tempValues1,numberMines,count1);
        }
        
        
    }
    
    //cout<< "the number user pick is "<< ucerChoose;
    
}



int main(int argc, char* argv[])
{
    
    // these are boolean flags to set if the player win or lose
    bool won =false; 
    bool lost=false;
    
    initialization();
    // we should have a loop here to keep the player play untill either win or lose became true.
    
    
    return 0;
}