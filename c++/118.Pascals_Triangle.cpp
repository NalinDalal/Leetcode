// https : // leetcode.com/problems/pascals-triangle/

#include <bits/stdc++.h>

using namespace std;

//////////  FIND THE SPECIFIC ELEMENT AT A SPECIFIC POSITION IN THE TRIANGLE BASED ON ROWS AND COLUMNS

///////////5C3
///// 5*4*3
//// -------    = 10
///// 3*2*1

///////////5C2
///// 5*4
//// -------    = 10
///// 2*1

///////////////////////////  n-ROW , r-COLUMN
void generateAtPosition___NcR(int n, int r)
{
    //  ROW ---- n,   COLUMN ---- r
    long long ans = 1;
    for(int i=1;i<=r;i++)
    {
        ans = ans*(n-i);
        // cout << "Ans:  " << ans << "  (n-i): "<<(n-i)<<endl;
        ans = ans/i;
        // cout << "Ans:  " << ans << "  /r: " << (r) << endl;
    }
    cout << "Element at the postion: \nRow: " << n << " \nColumn: " << r << " \nIs:  " << ans << endl;
}


void printVector(vector<vector<int>>& result)
{
    for(int i=0;i<result.size();i++)
    {
        for(int j=0; j<result[i].size();j++)
        {
            cout<<result[i][j]<<"  ";
        }
        cout<<endl;
    }
}



//////////    GENERATE THE ENTIRE ROW IN A PASCAL's TRIANGLE

vector<int> generateRow(int n)
{
    vector<int> result;
    long long ans=1;
    result.push_back(ans);
    for(int i=1; i<n; i++)
    {
        ans = ans*(n-i);
        ans = ans/i;
        result.push_back(ans);
        // cout<<ans <<"  ";
    }
    // cout<<endl;
    return result;
}

int main()
{
    

    ///////////  Generate a specific position

    // int row = 5, col = 0;
    // generateAtPosition___NcR(row,col);

    int n = 4;

    //////////////   GENERATING THE ENTIRE TRIANGLE's ROW
    vector<int> temp;
    temp = generateRow(n);
    for(int i=0; i<temp.size(); i++)
    {
        cout<<temp[i]<<"  ";
    }

    // //////////////   GENERATING THE ENTIRE PASCAL's TRIANGLE
    // vector<vector<int>> result;
    // for(int i=1; i<=n; i++)
    // {
    //     // cout<<"i: "<<i<<endl;
    //     result.push_back(generateRow(i));
    // }

    // printVector(result);
}