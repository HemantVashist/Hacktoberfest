#include <iostream>
#include<cmath>
using namespace std;
bool isSafe(int mat[][9],int i,int j,int n,int num){
    //check for row and column
    for(int k=0;k<n;k++){
        if(mat[i][k]==num || mat[k][j]==num){
            return false;
        }
    }
    //check for 3*3 grid
    n=sqrt(n);
    int starti=(i/n)*n,startj=(j/n)*n;
    for(int k=0;k<n;k++){
        for(int l=0;l<n;l++){
            if(mat[starti+k][startj+l]==num)
                return false;
        }
    }
    return true;
}
bool SudokuSolver(int mat[][9],int i,int j,int n){
    if(i==n){
        for(int k=0;k<n;k++){
            for(int l=0;l<n;l++)
                cout<<10-mat[k][l]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
        return true;
    }
    if(j>=n){
        return SudokuSolver(mat,i+1,0,n);
    }
    if(mat[i][j]!=0){
        return SudokuSolver(mat,i,j+1,n);
    }
    for(int num=1;num<=n;num++){
        if(isSafe(mat,i,j,n,num)){
            mat[i][j]=num;
            if(SudokuSolver(mat,i,j+1,n))
                return true;
            mat[i][j]=0;
        }
    }
    return false;
}
int main() {
    int mat[9][9]={
        {9,0,0,0,3,0,0,0,8},
        {0,1,6,7,2,9,5,3,0},
        {0,0,0,5,0,8,0,0,0},
        {0,8,0,0,0,0,0,5,0},
        {0,0,0,3,7,2,0,0,0},
        {0,4,0,0,0,0,0,1,0},
        {0,0,0,1,0,4,0,0,0},
        {0,7,4,9,5,3,8,2,0},
        {5,0,0,0,8,0,0,0,6}
    };
    return SudokuSolver(mat,0,0,9);
}
