//
//  soduko.c
//  mysudoku
//
//  Created by PUSHPENDU GHOSH on 17/02/16.
//  Copyright © 2016 PUSHPENDU. All rights reserved.
//  Xcode 7.2 (7C68)
//

#include <stdio.h>
int A[9][9],I[82],J[82],X[82]={0},c;

void check(int i,int j)//A checking function to check whether the digit inserted is unique or not
{
    int cbox,rbox,a,k,l;
    c=0;
    a=A[i][j];
    
    cbox=(j/3)*3;
    rbox=(i/3)*3;
    
    for(k=0;k<9;k++)
    {
        if(a==A[i][k])
            c++;
    }
    for(k=0;k<9;k++)
    {
        if(a==A[k][j])
            c++;
    }
    for(k=rbox;k<rbox+3;k++)
    {
        for(l=cbox;l<cbox+3;l++)
        {
            if(a==A[k][l])
                c++;
        }
    }
    
}

void input()//Takes input from user
{
    int i,j;
    
    printf("Enter unsolved sudoku (For all blank spaces enter 0) :\n");
    
    for(i=0;i<9;i++)
    {for(j=0;j<9;j++)
    {
        scanf("%d",&A[i][j]);
    }
    }
}

void output(int t)//Displays the final output
{
    int i,j;
    
    if(t==81)
    {
        printf("\nSolved soduko : \n");
    
        for(i=0;i<9;i++)
        {   for(j=0;j<9;j++)
            {
                printf("%d ",A[i][j]);
            }printf("\n");
        }
    }
    else
        printf("\nInvalid entries...this sudoku can't be solved.Please check the entries and input the values again.\n");
        
}

int main()
{
    int i,j,b=0,z=1,k,x=0,t=0;
    
    input();
    
    for(i=0;i<9;i++)
    {for(j=0;j<9;j++)
    {
        if(b==1)//b=1 corresponds wrong entry and takes us back to change the previous element
        {
            j=J[z];
            
            if(A[i][j]==X[z])
            {
                for(k=x+1;k<=9;k++)//changing the previous elements
                {
                    A[i][j]=k;
                    check(i,j);
                    
                    if(c==3)
                    {
                        I[z]=i;
                        J[z]=j;
                        X[z]=k;
                    
                        z++;
                        b=0;
                        break;
                    }
                }
                if(k==10) //some previous element entered by the program is wrong
                {
                    if(i==I[1]&&j==J[1]) //stops program...case when the sudoku is unsolvable
                    {
                        i=10;
                        j=10;
                        break;
                    }
                    z--;
                    A[i][j]=0;
                    i=I[z];
                    b=1;
                    x=X[z];
                    i--;
                    
                    break;
                }
            }
        }
        
        else
        {
            if(A[i][j]==0)
            {
                for(k=1;k<10;k++)//Assigning a new value to the void space
                {
                    A[i][j]=k;
                    
                    check(i,j);
                
                    if(c==3)//shows k is unique...and has k is stored in that element
                    {
                        I[z]=i;
                        J[z]=j;
                        X[z]=k;

                        z++;
                        b=0;
                        break;
                    }
                }
                if(k==10)//some previous element entered by the program is wrong
                {
                    z--;
                    A[i][j]=0;
                    i=I[z];
                    b=1;
                    x=X[z];
                    i--;
                    break;
                }
            }
        }
    }
    }
    
    for(i=0;i<9;i++)//check the uniqeness of all elements so as to get sure was the sudoku solvable?
    {
        for(j=0;j<9;j++)
        {
            check(i,j);
            if(c==3)
                t++;
        }
    }
    
    output(t);
    
    return 0;
    
}

//Four example sudokus : two solvable and other two unsolvable is given below

/* Solvable
0 0 0 0 0 0 6 8 0
0 0 0 0 7 3 0 0 9
3 0 9 0 0 0 0 4 5
4 9 0 0 0 0 0 0 0
8 0 3 0 5 0 9 0 2
0 0 0 0 0 0 0 3 6
9 6 0 0 0 0 3 0 8
7 0 0 6 8 0 0 0 0
0 2 8 0 0 0 0 0 0
*/


/* Unsolvable
5 0 0 0 0 0 6 8 0
0 0 0 0 7 3 0 0 9
3 0 9 0 0 0 0 4 5
4 9 0 0 0 0 0 0 0
8 0 3 0 5 0 9 0 2
0 0 0 0 0 0 0 3 6
9 6 0 0 0 0 3 0 8
7 0 0 6 8 0 0 0 0
0 2 8 0 0 0 0 0 0
*/

/*Solvable
1 0 3 4 0 0 7 0 9
0 5 6 0 8 9 0 2 3
0 8 9 1 0 3 4 0 6
2 1 4 0 6 5 0 9 7
3 0 0 8 0 7 0 1 4
8 0 7 0 1 4 0 6 5
0 3 1 0 4 0 9 7 8
6 4 0 9 7 0 5 3 1
0 7 8 0 0 1 0 4 2
*/

/*Unsolvable
 1 0 3 4 0 0 7 0 9
 0 5 6 0 8 9 0 2 3
 0 8 9 1 0 3 4 0 6
 2 1 4 0 6 5 0 9 7
 3 0 0 8 0 7 0 1 4
 8 0 7 0 1 4 0 6 5
 0 3 1 0 4 0 9 7 8
 6 4 0 9 7 0 5 3 1
 0 7 8 0 0 1 0 4 3
*/