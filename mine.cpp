// imports the libraries for the game 
#include <iostream>
#include <stdlib.h>
#include <string>
#include<cstring>

// using namespace 
using namespace std;



//All function's declarations 
bool isValid(int r, int c, int height, int width);
void printGridNow(int width,int height,char **boardValues);
void buildGrid(int width,int height,char **boardValues);
void play(int width, int height, char **boardValues,char **tempValues, char **tempValues1);
void first_choice(int width,int height,char **boardValues,char **tempValues, char **tempValues1,int numberMines);
void initialization();



/**
 * function to check the index that user entered for a cell. 
 * Comparing it with the width and height of the game's grid.
 * 
 * @ int r ,int c , int height , int width
 **/
bool isValid(int r, int c, int height, int width){
    return ((r>=0)&&(r<height)&&(c>=0)&&(c<width));
    
}

/**
 * function to print the Grid after each step of the game.
 * Beginning of the game all the cells are going to be empty '-'. 
 * 
 * @ int height , int width, boardValues
 **/
void printGridNow(int width,int height,char **boardValues){
    
    //Each level of the game has different grid. Here is the Beginner level.
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
    
    //build the grid for the intermediate level.
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
    
    //build the grid for the advance level.
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

/**
 * function to set the grid of the game for the first time all to empty '-'.
 * 
 * @ int width, int height  , char boardValues
 **/
void buildGrid(int width,int height,char **boardValues){
    
    // Loop through the 2D array and set it to '-'
    for (int row=0; row < height ; row++){
        for(int column=0; column < width ; column++){
           boardValues[row][column]= '-';
        }
    }
}


/**
 * function to set the grid of the game for the first time all to empty '-'.
 * 
 * @ int width, int height  , char boardValues
 **/
void play(int width, int height, char **boardValues,char **tempValues, char **tempValues1){
    int playerWidth;
    int playerHeight;
    int flag=0;
    cout<<"Enter the value of the height and the width ";
    cin>>playerHeight>>playerWidth;
    cout<<"Enter 0 to open the cell or 1 to flag it (0 or 1): ";
    cin>>flag;
    if((playerHeight<0)||(playerHeight>height-1)||(playerWidth<0)||(playerWidth>width-1)){
        cout<<"INVALID INPUT!!"<<endl;
        cout<<"Enter the value of the height and the width ";
        cin>>playerHeight>>playerWidth;
        cout<<"Enter 0 to open the cell or 1 to flag it (0 or 1):";
        cin>>flag;
        play(width,height,boardValues,tempValues,tempValues1);
    }
    tempValues1[playerHeight][playerWidth]=tempValues[playerHeight][playerWidth];
    if(flag==1){ 
        tempValues1[playerHeight][playerWidth]= '#';
        printGridNow(width,height,tempValues1);
        play(width,height,boardValues,tempValues,tempValues1);
    }
    else{
        if(!(boardValues[playerHeight][playerWidth]!='*')){
            printGridNow(width,height,boardValues);
            cout<<"YOU LOST!!!"<<endl;
            exit(0);
        }
        else{
            //buildGrid(width,height,boardValues);
            //boardValues[playerHeight][playerWidth]= tempValues[playerHeight][playerWidth];
            if(!(tempValues1[playerHeight][playerWidth]!='0')){
                if(isValid(playerHeight+1,playerWidth-1,height,width)){tempValues1[playerHeight+1][playerWidth-1]=tempValues[playerHeight+1][playerWidth-1];}
                if(isValid(playerHeight+1,playerWidth,height,width)){tempValues1[playerHeight+1][playerWidth]=tempValues[playerHeight+1][playerWidth];}
                if(isValid(playerHeight+1,playerWidth+1,height,width)){tempValues1[playerHeight+1][playerWidth+1]=tempValues[playerHeight+1][playerWidth+1];}
                if(isValid(playerHeight,playerWidth-1,height,width)){tempValues1[playerHeight][playerWidth-1]=tempValues[playerHeight][playerWidth-1];}
                if(isValid(playerHeight,playerWidth+1,height,width)){tempValues1[playerHeight][playerWidth+1]=tempValues[playerHeight][playerWidth+1];}
                if(isValid(playerHeight-1,playerWidth-1,height,width)){tempValues1[playerHeight-1][playerWidth-1]=tempValues[playerHeight-1][playerWidth-1];}
                if(isValid(playerHeight-1,playerWidth,height,width)){tempValues1[playerHeight-1][playerWidth]=tempValues[playerHeight-1][playerWidth];}
                if(isValid(playerHeight-1,playerWidth+1,height,width)){tempValues1[playerHeight-1][playerWidth+1]=tempValues[playerHeight-1][playerWidth+1];}}
            printGridNow(width,height,tempValues1);
            play(width,height,boardValues,tempValues,tempValues1);
        }
    }
        
}

/**
 * function to generate the mines in the game's grid.
 * 
 * @ int width, int height  , char boardValues, int numberMines, int playerHeight, int playerWidth
 **/
void buildMines(int width,int height, char **boardValues, int numberMines, int playerHeight, int playerWidth){
    int mineRow;
    int mineCol;
    int i=0;
    
    while(i<numberMines){
        mineRow=rand() % height + 0;
        mineCol=rand() % width + 0;
       //Saleh : need to be reviewed the number of mines is less than what expected
        if((mineRow!=playerHeight) &&(mineCol!=playerWidth)){
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

/**
 * function to count the number of mines adjacent to a cell. This function will loop through all cells.
 * 
 * @ int width, int height  , char boardValues, int numberMines, int playerHeight, int playerWidth
 **/
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
/**
 * function to read freom the user the index of the cell he wants to reach. It will do that by 
 * reading the height follow by the width. Also it reads if the player wants to add a flag.
 * 
 * @ int width, int height  , char boardValues, int numberMines, int playerHeight, int playerWidth
 **/
void first_choice(int width,int height,char **boardValues,char **tempValues, char **tempValues1,int numberMines){
    int playerHeight;
    int playerWidth;
    int flag;
    cout<<"Enter the value of the height and the width ";
    cin>>playerHeight>>playerWidth;
    //cout<<"Enter the value of the height and the width "; should be 
    cout<<"Enter 0 to open the cell or 1 to flag it (0 or 1):";
    cin>>flag;
    if((playerHeight<0)||(playerHeight>height-1)||(playerWidth<0)||(playerWidth>width-1)){
        cout<<"INVALID INPUT!!"<<endl;
        cout<<"Enter the value of the height and the width ";
        cin>>playerHeight>>playerWidth;
        cout<<"Enter 0 to open the cell or 1 to flag it (0 or 1):";
        cin>>flag;
        first_choice(width,height,boardValues,tempValues,tempValues1,numberMines);
    }
    buildMines(width,height,boardValues,numberMines,playerHeight,playerWidth);
    buildValues(width,height,boardValues,numberMines,tempValues);
    tempValues1[playerHeight][playerWidth]=tempValues[playerHeight][playerWidth];
    if(flag==1){ 
        tempValues1[playerHeight][playerWidth]= '#';
        printGridNow(width,height,tempValues1);
    }
    
    else{
            //buildGrid(width,height,boardValues);
            //boardValues[playerHeight][playerWidth]= tempValues[playerHeight][playerWidth];
            if(!(tempValues1[playerHeight][playerWidth]!='0')){
                if(isValid(playerHeight+1,playerWidth-1,height,width)){tempValues1[playerHeight+1][playerWidth-1]=tempValues[playerHeight+1][playerWidth-1];}
                if(isValid(playerHeight+1,playerWidth,height,width)){tempValues1[playerHeight+1][playerWidth]=tempValues[playerHeight+1][playerWidth];}
                if(isValid(playerHeight+1,playerWidth+1,height,width)){tempValues1[playerHeight+1][playerWidth+1]=tempValues[playerHeight+1][playerWidth+1];}
                if(isValid(playerHeight,playerWidth-1,height,width)){tempValues1[playerHeight][playerWidth-1]=tempValues[playerHeight][playerWidth-1];}
                if(isValid(playerHeight,playerWidth+1,height,width)){tempValues1[playerHeight][playerWidth+1]=tempValues[playerHeight][playerWidth+1];}
                if(isValid(playerHeight-1,playerWidth-1,height,width)){tempValues1[playerHeight-1][playerWidth-1]=tempValues[playerHeight-1][playerWidth-1];}
                if(isValid(playerHeight-1,playerWidth,height,width)){tempValues1[playerHeight-1][playerWidth]=tempValues[playerHeight-1][playerWidth];}
                if(isValid(playerHeight-1,playerWidth+1,height,width)){tempValues1[playerHeight-1][playerWidth+1]=tempValues[playerHeight-1][playerWidth+1];}}
            printGridNow(width,height,tempValues1);
            play(width,height,boardValues,tempValues,tempValues1);
        }
    
    play(width,height,boardValues,tempValues,tempValues1);
}


/**
 * The start function of the game. All the initlization of the game are found here.
 * 
 * @ int width, int height  , char boardValues
 **/
void initialization(){
    
    int ucerChoose=1;// by defualt (10 x 10)
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
    
    //Salhe : fixed when trying to enter a string or number doesn't match options.
    cin>> ucerChoose;
    while (ucerChoose!=1&&ucerChoose!=2&&ucerChoose!=3){
        cout<< "Error : You should type the number that crosspond to the level."<<endl;
        cin.clear();
        cin.ignore(256,'\n');
        cin>>ucerChoose;
    }
    
        if(ucerChoose==1){
            width= 10;
            height = 10;
            cout<<"Choose the number of mines (20 to 98):"<< endl;
            cin>>numberMines;
            while((numberMines>98) ||(numberMines<20)){
                cout<<"Error :The number of mines, should be a number between (20 to 98): ";
                cin.clear();
                cin.ignore(256,'\n');
             cin>>numberMines;
            }
            
            
            char** boardValues = new char*[height];
            
            for(int i = 0; i < height; i++){
                boardValues[i] = new char[width];
            }
            
            // temp 1 2D array of type char same size as boardValues
            char** tempValues = new char*[height];
            for(int i = 0; i < height; i++){
                tempValues[i] = new char[width];
            }
            
            // temp 2 2D array of type char same size as boardValues
            char** tempValues1 = new char*[height];
            for(int i = 0; i < height; i++){
                tempValues1[i] = new char[width];
            }
            //set them all to -
            buildGrid(width, height,tempValues1);
            buildGrid(width, height,boardValues);
            buildGrid(width,height,tempValues);
            
            //display the board at the begining 
            printGridNow(width, height,boardValues);
            first_choice(width,height,boardValues,tempValues,tempValues1,numberMines);
        }
        
        //for the intermediate level
        else if(ucerChoose==2){
            cout<<"Choose the number of mines (80 to 498): ";
            cin>>numberMines;
            while((numberMines>498) || (numberMines<80)){
                cout<<"Error :Choose the number of mines , should be between (80 to 498): ";
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
        
        //for the advance level
        else if(ucerChoose==2){
            cout<<"Choose the number of mines(180 to 898): ";
            cin>>numberMines;
            while((numberMines>898) || (numberMines<180)){
                cout<<"choose the number of mines(180 to 898): ";
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




int main(int argc, char* argv[])
{
    
    // these are boolean flags to set if the player win or lose
    bool won =false; 
    bool lost=false;
     //check if the game get argument
    if(argc !=0){
        cout << "Error : The game accept no arguments. " << endl;
        return -1;
    }

    
    initialization();
    // we should have a loop here to keep the player play untill either win or lose became true.
    
    
    return 0;
}