#include<iostream>
using namespace std;
int main()
{
    int order, i, j;

    cout<<"\nEnter the order of the matrix: ";
    cin>>order;

    int Matrix[order][order];
    cout<<"\nenter elements of matrix one by one (row major) :- \n";
    for(i=0; i< order; i++)
    {
        for(j=0; j < order; j++)
        {
            cin>>Matrix[i][j];
        }
    }

    int RowMin[order], ColumnMax[order], R_Max, C_Min, Var;

    for(i=0; i < order; i++)
    {
        Var = Matrix[i][0];
        for(j=0; j < order; j++)
        {
            if(Matrix[i][j] < Var) Var = Matrix[i][j];
        }
        RowMin[i] = Var;
    }

    for(i=0; i < order; i++)
    {
        Var = 0;
        for(j=0; j < order; j++)
        {
            if(Matrix[j][i] > Var) Var = Matrix[j][i];
        }
        ColumnMax[i] = Var;
    }

    R_Max = RowMin[0];
    for(i=0; i < order; i++)
    {
        if(RowMin[i] > R_Max) R_Max = RowMin[i];
    }

    C_Min = ColumnMax[0];
    for(i=0; i < order; i++)
    {
        if(ColumnMax[i] < C_Min) C_Min = ColumnMax[i];
    }

    if(R_Max == C_Min)
    {
        cout<<"\nmatrix is nice";
        return 0;
    }
    int count,c[order];
      for(i=0; i < order; i++)
    {
       count=0;
        for(j=0; j < order; j++)
        {
            if(Matrix[j][i] > R_Max) count++;
        }
        c[i]=count;
    }
   int min=c[0];
     for(i=0; i < order; i++)
    {
        if(c[i]<min)
            min=c[i];
    }
    cout<<"\nnumber of changes required= "<<min;
    return 0;
}

