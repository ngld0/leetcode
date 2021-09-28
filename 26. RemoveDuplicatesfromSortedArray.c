int removeDuplicates(int* nums, int numsSize){
    
    if(!numsSize) return 0;
    int pivot=0,i=1;
    while(i<numsSize){
        if(nums[pivot]!=nums[i]) nums[++pivot]=nums[i];
        i++;
        
    }
    return pivot +1;
}
