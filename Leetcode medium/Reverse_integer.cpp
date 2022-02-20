int reverse(int x)
{
    long int rev=0,temp=x,rem;
    while(temp!=0)
    {
        rem=temp%10;
        rev=rev*10+rem;
        temp=temp/10;
    }
    return (rev<INT_MIN || rev>INT_MAX) ? 0 : rev;
}
