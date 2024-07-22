//TC and SC of bitwise operations are O(1)

//XOR : no. of 1’s is odd : 1
//      no. of 1’s is even : 0
    
//num>>k which is equal to num/pow(2,k)
//num<<k which is equal to num*pow(2,k)
    
//INT_MAX = pow(2,31)-1 , INT_MIN = -pow(2,31)
//Overflow condition : (pow(2,31)-1) << 1

//Computer stores negative integers by doing 2’s compliment
//For -6 computer stores 2’s compliment of 6
    
//NOT (~) operator :
//First flip the no.
//If it is neg do 2’s compliment else do nothing
//  Ex. ~(5)
//  0000…101
//  Flip this
//  1111… 010
//  It is neg, convert to 2’s compliment
//  1000…110 which is 6
//
//  Ex. ~(-6)
//  0000…110 is 6
//  1111… 001
//  1111…010 is stored as -6 in computer
//  Flip this
//  0000…101 which is 5

