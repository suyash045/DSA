#include<bits/stdc++.h>
using namespace std;

//Store levels in map
//Ex. beginWord = "hit", endWord = "cog"
//wordList = ["hot","dot","dog","lot","log","cog"]
//        levels  
//  hit     1
//  hot     2 
//dot lot   3 
//dog log   4
//  cog     5
//Then backtrack from endWord using dfs
class Solution {
public:
    void dfs(string word,vector<string> seq,vector<vector<string>> &ans,unordered_map<string,int> &mpp,string &beginWord,vector<string>& wordList){
        if(word==beginWord){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            return;
        }


        for(int i=0;i<word.size();i++){
            string original=word;
            for(char ch='a';ch<='z';ch++){
                word[i]=ch;
                if(mpp.count(word)>0 && mpp[word]+1==mpp[original]){
                    seq.push_back(word);
                    dfs(word,seq,ans,mpp,beginWord,wordList);
                    seq.pop_back();
                }
            }
            word=original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> mpp;
        unordered_set<string> s(wordList.begin(),wordList.end());
        s.erase(beginWord);
 
        queue<pair<string,int>> q;
        q.push({beginWord,1});

        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();

            mpp[word]=steps;

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

        vector<vector<string>> ans;
        if(mpp.find(endWord)!=mpp.end()){
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord,seq,ans,mpp,beginWord,wordList);
        }

        return ans;
    }
};