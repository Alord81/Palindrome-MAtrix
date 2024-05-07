#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int RandomeNumber(short From, short To)
{
    return rand() % (To - From + 1) + From;
}

void FullArrayWithOrderdNumber(short arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            arr[i][j] = RandomeNumber(0, 9);
        }
    }
}

void PrintArrayInMatrix(short arr[3][3], short rows, short cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%0*d\t", 2, arr[i][j]);
        }
        cout << endl;
    }
}

//My Answer::~
/*bool IsPalindromeMatrix(short Matrix[3][3], short Row, short Col)
{
    short TheCols = Col - 1;
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col; j++)
        {
            if (Matrix[i][j] != Matrix[i][TheCols--])
            {
                return false;
            }
        }
        TheCols = Col - 1;
    }

    return true;
}*/


bool IsPalindromeMatrix(short Matrix[3][3], short Row, short Col)
{
    for (short i = 0; i < Row; i++)
    {
        for (short j = 0; j < Col / 2; j++) // Cols / 2 : Because I don't need to loop all elements on Rows, only I can compare the first element with the last element.
        {
            if (Matrix[i][j] != Matrix[i][Col - 1 - j])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{

    srand((unsigned)time(NULL));
    /*short Matrix[3][3] = {
        {1,2,1},
        {5,5,5},
        {7,3,7}
    };*/
    short Matrix[3][3];
    short cols = 3, rows = 3;

    FullArrayWithOrderdNumber(Matrix, rows, cols);
    cout << "Matrix1:\n";
    PrintArrayInMatrix(Matrix, rows, cols);


    if (IsPalindromeMatrix(Matrix, rows, cols))
    {
        cout << "\nYes: Matrix is Palindrome\n";
    }
    else
    {

        cout << "\nNo: Matrix is Not Palindrome\n";
    }
        
    return 0;
}