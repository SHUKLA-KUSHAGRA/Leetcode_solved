bool isPalindrome(int x){
    long int rev=0,temp=x,rem;
    while(temp!=0)
    {
        rem=temp%10;
        rev=rev*10+rem;
        temp=temp/10;
    }
    if(rev==x && x>=0)
        return true;
    else
        return false;
}
