char slowestKey(int* releaseTimes, int releaseTimesSize, char * keysPressed){
    
    int max = releaseTimes[0];
    
    char res = keysPressed[0];
    
    int temp =0;
    
    for (int i = 0 ;i < releaseTimesSize -1;i++){
        temp = releaseTimes[i+1] - releaseTimes[i];
        if(temp > max || (temp == max && keysPressed[i+1] > res)){
            max = temp;
            res = keysPressed[i+1];
        }
    }
    return res;
}
