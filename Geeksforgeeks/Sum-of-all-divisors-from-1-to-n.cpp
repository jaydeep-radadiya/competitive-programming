// tc : O(N)
// sc : O(1)
class Solution {
public:
    long long sumOfDivisors(int N){
        long long sum = 0;
        for(int i=1;i<=N;i++){
            sum += i*(N/i);
        }
        return sum;
    }
};

/*
lets take N = 5
sum = f(1)+f(2)+f(3)+f(4)+f(5)
    = (1)+(1+2)+(1+3)+(1+2+4)+(1+5)
    = 1*5+2*2+3*1+4*1+5*1
sum = 1*(N/1)+2*(N/2)+3*(N/3)+4*(N/4)+5*(N/5)
*/