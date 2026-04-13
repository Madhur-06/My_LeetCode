/*
Problem: 204. Count Primes
Link: https://leetcode.com/problems/count-primes/
Difficulty: Medium


Approach:
1. Initialize a boolean array to mark all numbers as prime initially.
2. Traverse each number and if it is prime, increment count.
3. Mark all multiples of the current prime as non-prime.
4. Return the total count of prime numbers less than n.


Time Complexity: O(n log log n)
Space Complexity: O(n)
*/

class Solution {
public:
    int countPrimes(int n) {

        // Step 1: Handle edge case
        if(n == 0) return 0 ;

        vector<bool>isPrime(n , true);
        int count = 0 ;

        isPrime[0] = false ;
        isPrime[1] = false ;

        // Step 2 & 3: Traverse and mark multiples
        for(int i = 0 ; i < n ; i++){
            if(isPrime[i]){ 
                count++;
                int k = 2 ;
                int j = i * k ;
                while(j < n){
                    isPrime[j] = false ;
                    j = j + i ;
                }
            }
        }

        // Step 4: Return count
        return count ;
    }
};
