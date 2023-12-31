#include <iostream>
#include <iomanip>
using namespace std;

/////////////////////////////////////////////////////////////////////////
// Function to input matrix values
void inputMatrix(float** matrix, int rows, int columns) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << "Input the [" << i + 1 << ", " << j + 1 << "] element: ";
            cin >> matrix[i][j];
            cout << endl;
        }
    }
}
/////////////////////////////////////////////////////////////////////////
void inputRightHandSide(float* rhs, int rows) {
    cout << "Input the right-hand side values:" << endl;
    for (int i = 0; i < rows; ++i) {
        cout << "Equation " << i + 1 << ": ";
        cin >> rhs[i];
    }
}
/////////////////////////////////////////////////////////////////////////
// Function to output the matrix
void outputMatrix(float** matrix, int rows, int columns) {
    cout << "Your matrix: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            cout << setw(4) << matrix[i][j];
        }
        cout << endl;
    }
}
//////////////////////////////////////////////////////////////////////
void swapRows(float** matrix, int row1, int row2, int columns) {
  for (int j = 0; j < columns; ++j) {
      int temp = matrix[row1][j];
      matrix[row1][j] = matrix[row2][j];
      matrix[row2][j] = temp;
  }
}
//////////////////////////////////////////////////////////////////////


int main() {
    cout << "This code was prepared to solve the SLAE"<<endl;
  cout<<"using Gauss Elimination method."<<endl; 
  cout<<"It can solve SLAE made from 5, 4, 3 and 2 equations" << endl;
    cout << "------------------------------------";
    cout << endl << endl;
    int r; 
    cout << "Enter a number of equations: ";
    cin >> r;
    int c=r;



    float** matrix = new float*[r];
    for (int i = 0; i < r; ++i) {
        matrix[i] = new float[c];
    }

    float* rhs = new float[r];

    inputMatrix(matrix, r, c);
    outputMatrix(matrix, r, c);
    inputRightHandSide(rhs, r);
  cout<<"------------------------------------";

  //IF MATRIX IS 5X5
  float a = 0;
  if(r==5)
  {


  //[1][1] --> 1
    a=matrix[0][0];
    if(a!=0)
    {
      for (int j = 0; j < c; ++j) {
                matrix[0][j]=matrix[0][j]/a; 
          }
      rhs[0]=rhs[0]/a;
      }

  //[2][1] --> 0
    a=matrix[1][0];
    for (int j = 0; j < c; ++j) {
      matrix[1][j]=matrix[1][j]-matrix[0][j]*a;
    }
    rhs[1]=rhs[1]-rhs[0]*a;

  //[3][1] -->0
  a=matrix[2][0];
  for (int j = 0; j < c; ++j) {
    matrix[2][j]=matrix[2][j]-matrix[0][j]*a;
  }
  rhs[2]=rhs[2]-rhs[0]*a;

  //[4][1] -->0
  a=matrix[3][0];
  for (int j = 0; j < c; ++j) {
    matrix[3][j]=matrix[3][j]-matrix[0][j]*a;
  }
  rhs[3]=rhs[3]-rhs[0]*a;

  //[5][1] -->0
  a=matrix[4][0];
  for (int j = 0; j < c; ++j) {
    matrix[4][j]=matrix[4][j]-matrix[0][j]*a;
  }
  rhs[4]=rhs[4]-rhs[0]*a;

  int rowToSwap1 = 1;
  int rowToSwap2 = 2;

  if(matrix[1][1]==0)
  {
    swapRows(matrix, rowToSwap1, rowToSwap2, c);
    float temp=0;
    temp=rhs[1];
    rhs[1]=rhs[2];
    rhs[2]=temp;
  }

  //[2][2]-->1
  a=matrix[1][1];
  if(a!=0)
  {
    for (int j = 0; j < c; ++j) 
    {
      matrix[1][j]=matrix[1][j]/a;
    }
    rhs[1]=rhs[1]/a;
  }



  //[1][2]-->0
  a=matrix[0][1];
  for (int j = 0; j < c; ++j) {
    matrix[0][j]=matrix[0][j]-matrix[1][j]*a;
  }
  rhs[0]=rhs[0]-rhs[1]*a;

  //[3][2]-->0
  a=matrix[2][1];
  for (int j=0; j<c; ++j)
  {
    matrix[2][j]=matrix[2][j]+matrix[1][j]*a*-1;
  }
  rhs[2]=rhs[2]+rhs[1]*a*-1;

  //[4][2]-->0
  a=matrix[3][1];
  for (int j=0; j<c; ++j)
  {
    matrix[3][j]=matrix[3][j]+matrix[1][j]*a*-1;
  }
  rhs[3]=rhs[3]+rhs[1]*a*-1;

  //[5][2]-->0
  a=matrix[4][1];
  for(int j=0; j<c; ++j)
  {
    matrix[4][j]=matrix[4][j]+matrix[1][j]*a*-1;
  }
  rhs[4]=rhs[4]+rhs[1]*a*-1;

  //[3][3]-->1
  a=matrix[2][2];
  if(a!=0)
  {
    for (int j=0; j<c; ++j)
    {
      matrix[2][j]=matrix[2][j]/a;
    }
    rhs[2]=rhs[2]/a;
  }

  //[1][3]-->0
  a=matrix[0][2];
  for (int j=0; j<c; ++j)
  {
    matrix[0][j]=matrix[0][j]+matrix[2][j]*a*-1;
  }
  rhs[0]=rhs[0]+rhs[2]*a*-1;

  //[2][3]-->0
  a=matrix[1][2];
  for (int j=0; j<c; ++j)
  {
    matrix[1][j]=matrix[1][j]-matrix[2][j]*a;
  }
  rhs[1]=rhs[1]-rhs[2]*a;


  //[4][3]-->0
  a=matrix[3][2];
  for (int j=0; j<c; ++j)
  {
    matrix[3][j]=matrix[3][j]-matrix[2][j]*a;
  }
  rhs[3]=rhs[3]-rhs[2]*a;

  //[5][3]-->0 ////???????????
  a=matrix[4][2];
    for (int j=0; j<c; ++j)
    {
      matrix[4][j]=matrix[4][j]+matrix[2][j]*a*-1;
    }
    rhs[4]=rhs[4]+rhs[2]*a*-1;

  //[4][4]-->1
  a=matrix[3][3];
  if(a!=0)
  {
    for (int j=0; j<c; ++j)
    {
      matrix[3][j]=matrix[3][j]/a;
    }
    rhs[3]=rhs[3]/a;
  }

  //[1][4]-->0
  a=matrix[0][3];
  for (int j=0; j<c; ++j)
  {
    matrix[0][j]=matrix[0][j]-matrix[3][j]*a;
  }
  rhs[0]=rhs[0]-rhs[3]*a;


  //[2][4]-->0
  a=matrix[1][3];
  for (int j=0; j<c; ++j)
  {
    matrix[1][j]=matrix[1][j]-matrix[3][j]*a;
  }
  rhs[1]=rhs[1]-rhs[3]*a;


  //[3][4]-->0
  a=matrix[2][3];
  for (int j=0; j<c; ++j)
  {
    matrix[2][j]=matrix[2][j]+matrix[3][j]*a*-1;
  }
  rhs[2]=rhs[2]+rhs[3]*a*-1;


  //[5][4]-->0 //??????????????????????????//
  a=matrix[4][3];
    for (int j=0; j<c; ++j)
    {
      matrix[4][j]=matrix[4][j]+matrix[3][j]*a*-1;
    }
    rhs[4]=rhs[4]+rhs[3]*a*-1;


  //[5][5]-->1
  a=matrix[4][4];
  if (a!=0)
  {
    for (int j=0; j<c; ++j)
    {
      matrix[4][j]=matrix[4][j]/a;
    }
    rhs[4]=rhs[4]/a;
  }

  //[1][5]-->1 ????????????
  a=matrix[0][4];
    for (int j=0; j<c; ++j)
    {
      matrix[0][j]=matrix[0][j]-matrix[4][j]*a;
    }
    rhs[0]=rhs[0]-rhs[4]*a;

  //[2][5]-->1
  a=matrix[1][4];
    for (int j=0; j<c; ++j)
    {
      matrix[1][j]=matrix[1][j]-matrix[4][j]*a;
    }
    rhs[1]=rhs[1]-rhs[4]*a;

  //[3][5]-->1
  a=matrix[2][4];
    for (int j=0; j<c; ++j)
    {
      matrix[2][j]=matrix[2][j]-matrix[4][j]*a;
    }
    rhs[2]=rhs[2]-rhs[4]*a;

  //[4][5]-->1
  a=matrix[3][4];
    for (int j=0; j<c; ++j)
    {
      matrix[3][j]=matrix[3][j]-matrix[4][j]*a;
    }
    rhs[3]=rhs[3]-rhs[4]*a;
  }
   else if(r==4)
   {
     //[1][1] --> 1
       a=matrix[0][0];
       if(a!=0)
       {
         for (int j = 0; j < c; ++j) {
                   matrix[0][j]=matrix[0][j]/a; 
             }
         rhs[0]=rhs[0]/a;
         }

     //[2][1] --> 0
       a=matrix[1][0];
       for (int j = 0; j < c; ++j) {
         matrix[1][j]=matrix[1][j]-matrix[0][j]*a;
       }
       rhs[1]=rhs[1]-rhs[0]*a;

     //[3][1] -->0
     a=matrix[2][0];
     for (int j = 0; j < c; ++j) {
       matrix[2][j]=matrix[2][j]-matrix[0][j]*a;
     }
     rhs[2]=rhs[2]-rhs[0]*a;

     //[4][1] -->0
     a=matrix[3][0];
     for (int j = 0; j < c; ++j) {
       matrix[3][j]=matrix[3][j]-matrix[0][j]*a;
     }
     rhs[3]=rhs[3]-rhs[0]*a;

     int rowToSwap1 = 1;
     int rowToSwap2 = 2;

     if(matrix[1][1]==0)
     {
       swapRows(matrix, rowToSwap1, rowToSwap2, c);
       float temp=0;
       temp=rhs[1];
       rhs[1]=rhs[2];
       rhs[2]=temp;
     }

     //[2][2]-->1
     a=matrix[1][1];
     if(a!=0)
     {
       for (int j = 0; j < c; ++j) 
       {
         matrix[1][j]=matrix[1][j]/a;
       }
       rhs[1]=rhs[1]/a;
     }



     //[1][2]-->0
     a=matrix[0][1];
     for (int j = 0; j < c; ++j) {
       matrix[0][j]=matrix[0][j]-matrix[1][j]*a;
     }
     rhs[0]=rhs[0]-rhs[1]*a;

     //[3][2]-->0
     a=matrix[2][1];
     for (int j=0; j<c; ++j)
     {
       matrix[2][j]=matrix[2][j]+matrix[1][j]*a*-1;
     }
     rhs[2]=rhs[2]+rhs[1]*a*-1;

     //[4][2]-->0
     a=matrix[3][1];
     for (int j=0; j<c; ++j)
     {
       matrix[3][j]=matrix[3][j]+matrix[1][j]*a*-1;
     }
     rhs[3]=rhs[3]+rhs[1]*a*-1;

     //[3][3]-->1
     a=matrix[2][2];
     if(a!=0)
     {
       for (int j=0; j<c; ++j)
       {
         matrix[2][j]=matrix[2][j]/a;
       }
       rhs[2]=rhs[2]/a;
     }

     //[1][3]-->0
     a=matrix[0][2];
     for (int j=0; j<c; ++j)
     {
       matrix[0][j]=matrix[0][j]+matrix[2][j]*a*-1;
     }
     rhs[0]=rhs[0]+rhs[2]*a*-1;

     //[2][3]-->0
     a=matrix[1][2];
     for (int j=0; j<c; ++j)
     {
       matrix[1][j]=matrix[1][j]-matrix[2][j]*a;
     }
     rhs[1]=rhs[1]-rhs[2]*a;


     //[4][3]-->0
     a=matrix[3][2];
     for (int j=0; j<c; ++j)
     {
       matrix[3][j]=matrix[3][j]-matrix[2][j]*a;
     }
     rhs[3]=rhs[3]-rhs[2]*a;

     //[4][4]-->1
     a=matrix[3][3];
     if(a!=0)
     {
       for (int j=0; j<c; ++j)
       {
         matrix[3][j]=matrix[3][j]/a;
       }
       rhs[3]=rhs[3]/a;
     }

     //[1][4]-->0
     a=matrix[0][3];
     for (int j=0; j<c; ++j)
     {
       matrix[0][j]=matrix[0][j]-matrix[3][j]*a;
     }
     rhs[0]=rhs[0]-rhs[3]*a;


     //[2][4]-->0
     a=matrix[1][3];
     for (int j=0; j<c; ++j)
     {
       matrix[1][j]=matrix[1][j]-matrix[3][j]*a;
     }
     rhs[1]=rhs[1]-rhs[3]*a;


     //[3][4]-->0
     a=matrix[2][3];
     for (int j=0; j<c; ++j)
     {
       matrix[2][j]=matrix[2][j]+matrix[3][j]*a*-1;
     }
     rhs[2]=rhs[2]+rhs[3]*a*-1;
   }
  else if(r==3)
  {
    //[1][1] --> 1
       a=matrix[0][0];
       if(a!=0)
       {
         for (int j = 0; j < c; ++j) {
                   matrix[0][j]=matrix[0][j]/a; 
             }
         rhs[0]=rhs[0]/a;
         }

     //[2][1] --> 0
       a=matrix[1][0];
       for (int j = 0; j < c; ++j) {
         matrix[1][j]=matrix[1][j]-matrix[0][j]*a;
       }
       rhs[1]=rhs[1]-rhs[0]*a;

     //[3][1] -->0
     a=matrix[2][0];
     for (int j = 0; j < c; ++j) {
       matrix[2][j]=matrix[2][j]-matrix[0][j]*a;
     }
     rhs[2]=rhs[2]-rhs[0]*a;

     int rowToSwap1 = 1;
     int rowToSwap2 = 2;

     if(matrix[1][1]==0)
     {
       swapRows(matrix, rowToSwap1, rowToSwap2, c);
       float temp=0;
       temp=rhs[1];
       rhs[1]=rhs[2];
       rhs[2]=temp;
     }

     //[2][2]-->1
     a=matrix[1][1];
     if(a!=0)
     {
       for (int j = 0; j < c; ++j) 
       {
         matrix[1][j]=matrix[1][j]/a;
       }
       rhs[1]=rhs[1]/a;
     }

     //[1][2]-->0
     a=matrix[0][1];
     for (int j = 0; j < c; ++j) {
       matrix[0][j]=matrix[0][j]-matrix[1][j]*a;
     }
     rhs[0]=rhs[0]-rhs[1]*a;

     //[3][2]-->0
     a=matrix[2][1];
     for (int j=0; j<c; ++j)
     {
       matrix[2][j]=matrix[2][j]+matrix[1][j]*a*-1;
     }
     rhs[2]=rhs[2]+rhs[1]*a*-1;

     //[3][3]-->1
     a=matrix[2][2];
     if(a!=0)
     {
       for (int j=0; j<c; ++j)
       {
         matrix[2][j]=matrix[2][j]/a;
       }
       rhs[2]=rhs[2]/a;
     }

     //[1][3]-->0
     a=matrix[0][2];
     for (int j=0; j<c; ++j)
     {
       matrix[0][j]=matrix[0][j]+matrix[2][j]*a*-1;
     }
     rhs[0]=rhs[0]+rhs[2]*a*-1;

     //[2][3]-->0
     a=matrix[1][2];
     for (int j=0; j<c; ++j)
     {
       matrix[1][j]=matrix[1][j]-matrix[2][j]*a;
     }
     rhs[1]=rhs[1]-rhs[2]*a;

  }
  else if(r==2)
  {
    //[1][1] --> 1
       a=matrix[0][0];
       if(a!=0)
       {
         for (int j = 0; j < c; ++j) {
                   matrix[0][j]=matrix[0][j]/a; 
             }
         rhs[0]=rhs[0]/a;
         }

     //[2][1] --> 0
       a=matrix[1][0];
       for (int j = 0; j < c; ++j) {
         matrix[1][j]=matrix[1][j]-matrix[0][j]*a;
       }
       rhs[1]=rhs[1]-rhs[0]*a;

     //[2][2]-->1
     a=matrix[1][1];
     if(a!=0)
     {
       for (int j = 0; j < c; ++j) 
       {
         matrix[1][j]=matrix[1][j]/a;
       }
       rhs[1]=rhs[1]/a;
     }



     //[1][2]-->0
     a=matrix[0][1];
     for (int j = 0; j < c; ++j) {
       matrix[0][j]=matrix[0][j]-matrix[1][j]*a;
     }
     rhs[0]=rhs[0]-rhs[1]*a;
  }

     cout<<endl;

       cout<<"After Gauss elimination: "<<endl<<endl;
       outputMatrix(matrix, r, c);
       cout << "------------------------------------";
       cout<<endl;
       cout<<endl;


  int CountZeroRow=0; 
  int LineWithZeros=0;
  for(int i=0; i<r; i++)
  {
    CountZeroRow=0;
    for(int j=0; j<r; j++)
    {
      if (matrix[i][j]==0) 
      {
        CountZeroRow+=1;
      } 
      if (CountZeroRow==r)
      {
        LineWithZeros=i;
        break;
      }
    }
  }
  
    if (LineWithZeros!=0 && rhs[LineWithZeros]==0)
    {
      cout<<"This system has infinitely many solutions."<<endl;
      return 0; 
    }

    if (LineWithZeros!=0 && rhs[LineWithZeros]!=0)
    {
      cout<<"This system has no solutions."<<endl;
      return 0; 
    }

  
    cout<<"Solution: "<<endl;
     for(int i=0; i<r; i++)
     {
       cout<<"x"<<i+1<<" = "<<rhs[i]<<endl;
     }
     cout << "------------------------------------";
    return 0;
  }