class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int total_sum = 0;
        for(auto num:nums){
            int count = 0;
            int sum = 0;

            for(int i = 1; i*i<= num;i++){
                if(num%i == 0){
                    int first = i;
                    int second = num/i;

                    if(first == second){
                        count = count + 1;
                        sum = sum + first;
                    }
                    else{
                        count = count + 2;
                        sum = sum + (first + second);
                    }
                }
                if(count > 4){
                    break;
                }
            }
            if(count == 4){
                total_sum += sum;
            }
        }
        return total_sum;
    }
};