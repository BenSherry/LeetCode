#include <set>
#include "setZeroes.hpp"


namespace setZeroes
{
    void Solution::setZeroes(std::vector<std::vector<int>>& matrix)
    {
        /********************************************
         * 1 2 3 4 matrix[0]
         * 5 6 7 8 matrix[1]
         * 9 10 11 12 matrix[2]
         * *******************************************/
        std::set<int> row;
        std::set<int> column; 
        int rows = matrix.size(); // 3
        int columns = matrix[0].size(); // 4
        for(auto i = 0;i < rows;i++)
        {
            for(auto j = 0; j < columns; j++)
            {
                if (matrix[i][j] == 0)
                {
                    row.insert(i);
                    column.insert(j);
                }
            }
        }
        
        for (auto it = row.begin(); it != row.end(); it++)
        {
            for (auto j = 0; j < columns; j++)
            {
                matrix[*it][j] = 0;
            }
        }

        for (auto it = column.begin(); it != column.end(); it++)
        {
            for (auto j = 0; j < rows; j++)
            {
                matrix[j][*it] = 0;
            }
        }
    }
}