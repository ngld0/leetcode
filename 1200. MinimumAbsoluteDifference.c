

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* num, const void* num1);

int** minimumAbsDifference(int* arr, int arrSize, int* returnSize, int** returnColumnSizes){    
    qsort(arr, arrSize, sizeof(int),cmp);    
    int mdif = arr[1]-arr[0], count = 0;    
    int** res = malloc(sizeof(int*) * arrSize);        
    int *columnSizes = (int*)malloc(sizeof(int) * arrSize);    
    for(int i = 0 ; i <arrSize -1;i++ ){        
        int tem = arr[i+1] - arr[i];        
        if(mdif >= tem){
            if(mdif > tem){ 

                res = malloc(sizeof(int*) * arrSize); 
                count = 0;
            }            
            mdif = tem;              
            res[count]=malloc(sizeof(int) *2);
            res[count][0]=arr[i];
            res[count][1]=arr[i+1];
            columnSizes[count++] =2;  
        }
    }
    *returnSize = count;
    *returnColumnSizes = columnSizes;
    return res;
}

int cmp(const void* num, const void* num1){
    
    return *(int*) num - *(int*)num1;
    
}
/***
Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements. 

Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

a, b are from arr
a < b
b - a equals to the minimum absolute difference of any two elements in arr
 

Example 1:

Input: arr = [4,2,1,3]
Output: [[1,2],[2,3],[3,4]]
Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
Example 2:

Input: arr = [1,3,6,10,15]
Output: [[1,3]]
Example 3:

Input: arr = [3,8,-10,23,19,-4,-14,27]
Output: [[-14,-10],[19,23],[23,27]]
 

Constraints:

2 <= arr.length <= 10^5
-10^6 <= arr[i] <= 10^6
***/
