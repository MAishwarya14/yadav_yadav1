#include <stdio.h>
#include <stdlib.h>
void draw_board();
char take_input();
void process_input(char ch);
void go_left();
void go_up();
void go_down();
void go_right();
void clear_board();
void swap(int x1,int y1,int x2,int y2);
int check_win();

//Initial board , change the values and zero indexes for various boards
int easy[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,0,13,14,15};
int medium[4][4]={1,2,3,4,9,6,7,8,0,10,5,11,12,13,14,15};
int hard[4][4]={14,2,3,4,13,6,7,8,5,9,15,11,12,10,1,0};
int board[4][4];
int choose_level();
//Intially zero postions ,first and second indexes , if 0 is at (1,3) firstindex will be 1 and second will be 3
int zero_pos_first_index;
int zero_pos_second_index;
//Initial move count
int move_count=0;

int main()
{
int level;
printf("choose your level\n1.easy\t\t2.medium\t\t3.hard\n");
scanf("%d",&level);
choose_level(level);
fflush(stdin);
draw_board();
    //Intitially draw the board
    int check,move;
    check=check_win();
    //printf("%d",check);
while(check!=1)
{
    //Loop till check_win is not equal to 1

        //Take input and store in ch
        //Process input (ch)
        //Clear the board
        //Draw the board again
        //Increase move count

    //End Loop
    //Print You have won with ___ Moves
move=take_input();
clear_board();
process_input(move);
if(move!='w' && move!='s' && move!='a' && move!='d')
printf("invalid move\n");
printf("________________________\n");
draw_board();
printf("________________________\n");
move_count++;
check=check_win();
printf("%d",check);
}
printf("You have WON with %d Moves",move_count);
}
int choose_level(int level)
{int i,j;
switch(level)
{
    case 1:zero_pos_first_index=3;
           zero_pos_second_index=0;
           for(i=0;i<4;i++)
           {
               for(j=0;j<4;j++)
               {
                   board[i][j]=easy[i][j];
               }
           }
             break;
    case 2:zero_pos_first_index=2;
           zero_pos_second_index=0;
           for(i=0;i<4;i++)
           {
               for(j=0;j<4;j++)
               {
                   board[i][j]=medium[i][j];
               }
           }
            break;
    case 3:
        zero_pos_first_index=3;
        zero_pos_second_index=3;
        for(i=0;i<4;i++)
           {
               for(j=0;j<4;j++)
               {
                   board[i][j]=hard[i][j];
               }
           }
           break;
}
}


void draw_board()
{int row,column;
for(row=0;row<4;row++)
{
    for(column=0;column<4;column++)
    {
        printf("%4d",board[row][column]);
    }
    printf("\n");
}

}
void clear_board(){
    //Clear the board
    system("cls");
}
char take_input()
{
/*
Take input and return it ,Use Fflush if scanf is being used

*/
int ch;
printf("----------[W] UP --- [S] Down --- [A] LEFT --- [D] Right--------------\n");
scanf("%c",&ch);
//if(ch!='w' && ch!='s' && ch!='a' && ch!='d')
//printf("invalid move\n");
fflush(stdin);
return ch;
}

void process_input(char ch)
{

/*
Handle the input char ch ,which is either w,a,s,d ,for up,left,down and right
Use a switch case and call go_left(),go_right()etc respectively
*/
switch(ch)
{
    case 'w': go_up();
    break;
    case 's':go_down();
    break;
    case 'd':go_right();
    break;
    case 'a':go_left();
    break;
    default :if(printf("invalid move\n"));
    move_count--;

    }
}

void go_left()
{
//move 0 tile left
if(zero_pos_second_index-1>=0)
{
    swap(zero_pos_first_index,zero_pos_second_index,zero_pos_first_index,zero_pos_second_index-1);
    zero_pos_second_index=zero_pos_second_index-1;
}
}
void go_right()
{
//move 0 tile right
if(zero_pos_second_index+1<=3)
    {
        swap(zero_pos_first_index,zero_pos_second_index,zero_pos_first_index,zero_pos_second_index+1);
        zero_pos_second_index=zero_pos_second_index+1;
    }
}
void go_up()
{
if(zero_pos_first_index-1>=0)
       {

        swap(zero_pos_first_index,zero_pos_second_index,zero_pos_first_index-1,zero_pos_second_index);
        zero_pos_first_index=zero_pos_first_index-1;
       }
}
void go_down()
{
//Move 0 tile down
if(zero_pos_first_index+1<=3)
       {

        swap(zero_pos_first_index,zero_pos_second_index,zero_pos_first_index+1,zero_pos_second_index);
     zero_pos_first_index=zero_pos_first_index+1;
       }
}

void swap(int x1,int y1,int x2,int y2)
{int temp;
//Swap board[x1][y1] and board[x2][y2];
temp=board[x1][y1];
board[x1][y1]=board[x2][y2];
board[x2][y2]=temp;
}

int check_win(){
//Return 1 , if current board has all tiles perfectly places ,or 0 otherwise
int check_array[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,0};
int i,j,count=0;
for(i=0;i<4;i++)
{
    for(j=0;j<4;j++)
    {
        if(board[i][j]==check_array[i][j])
        {
            count++;
        }

    }
}
if(count>=15)
    return 1;
else
    return 0;

}

