#include<bits/stdc++.h>
using namespace std;

//After pushing word in queue erase that element from set
//(because while finding shortest way we dont need that element again)
//hence we don't vis array 
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        queue<pair<string,int>> q;
        q.push({beginWord,0});
        set<string> s(wordList.begin(),wordList.end());
 
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();

            if(word==endWord){
                return steps+1;
            }

            for(int i=0;i<word.size();i++){
                string original=word;
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(s.find(word)!=s.end()){
                        q.push({word,steps+1});
                        s.erase(word);
                    }
                }
                word=original;
            }
        }
        return 0;
    }
};