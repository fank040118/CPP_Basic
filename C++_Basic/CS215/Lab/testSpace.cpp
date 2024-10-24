#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void searchVec(vector<vector<double>> grades, double search_term, int &row, int& col){
    bool status = 0;
    for(int i = 0; i < grades.size(); i++){
        for(int j = 0; j < grades[i].size(); j++){
            if(grades[i][j] == search_term){
                row = i;
                col = j;
                status = 1;
                status = true;
                break;
            }
        }
        if(status)
            break;
    }
    if (status = 0){
        row = -1;
        col = -1;
    }
}

int main()
{
    int search_term;
    cout << "enter the gread you searching for: " << endl;
    cin >> search_term;
    vector<vector<double>> grades= {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,5,14,15}
    };
    int row = 0;
    int col = 0;
    searchVec(grades, search_term, row, col);
    cout << row+1 << " " << col+1;
    return 0;
}