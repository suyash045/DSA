#include<iostream>
using namespace std;

//
pair<int, int> get(int a, int b){
    a=a^b;
    b=a^b; //b=(a^b)^b=a
    a=a^b; //a=(a^b)^a=b
    return {a,b};
}