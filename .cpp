//
//  main.cpp
//  Matrix Chain Multiplication
//
//  Created by Zijian Xie on 2016/11/3.
//  Copyright © 2016年 Jason Xie. All rights reserved.
//

#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class MatrixChainMultiplication{
public:
    int findCost(vector<int>& arr){
        vector<vector<int>> tmp(arr.size(),vector<int>(arr.size(),0));
        int q = 0;
        for(int len = 2; len < arr.size(); ++len){
            for(int i = 0; i + len < arr.size(); ++i){
                int j = i + len;
                tmp[i][j] = INT_MAX;
                for(int k = i + 1; k < j; ++k){
                    q = tmp[i][k] + tmp[k][j] + arr[i] * arr[k] * arr[j];
                    if( q < tmp[i][j]) tmp[i][j] = q;
                }
            }
        }
        return tmp[0][arr.size() - 1];
    }
};


int main(){
    MatrixChainMultiplication mcm = *new MatrixChainMultiplication();
    vector<int> arr = {4,2,3,5,3};
    int cost = mcm.findCost(arr);
    return cost;
}
