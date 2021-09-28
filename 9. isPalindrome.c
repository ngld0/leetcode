bool isPalindrome(int x){
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    int reX = 0;
    while (x > reX) {
        reX = reX * 10 + x % 10;
        x /= 10;
    }
    return x == reX || x == reX / 10;
}
