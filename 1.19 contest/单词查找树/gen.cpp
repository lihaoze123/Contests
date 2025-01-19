#include <bits/stdc++.h>
#include "testlib.h"

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int maxlen = opt<int>("maxlen");
    int type = opt<int>("type");
    
    std::set<std::string> words;
    
    if (type == 1) {
        while (words.size() < n) {
            int len = rnd.next(1, maxlen);
            std::string word;
            for (int i = 0; i < len; i++) {
                word += rnd.next('A', 'Z');
            }
            words.insert(word);
        }
    } else if (type == 2) {
        int baselen = rnd.next(maxlen / 2, maxlen);
        std::vector<int> positions;
        for (int i = 0; i < baselen; i++) {
            positions.push_back(i);
        }
        
        std::string base;
        for (int i = 0; i < baselen; i++) {
            base += rnd.next('A', 'Z');
        }
        words.insert(base);
        
        while (words.size() < n && !positions.empty()) {
            int posIdx = rnd.next(0, (int)positions.size() - 1);
            int pos = positions[posIdx];
            
            char oldChar = base[pos];
            std::vector<char> chars;
            for (char c = 'A'; c <= 'Z'; c++) {
                if (c != oldChar) chars.push_back(c);
            }
            
            if (chars.empty()) {
                positions.erase(positions.begin() + posIdx);
                continue;
            }
            
            char newChar = chars[rnd.next(0, (int)chars.size() - 1)];
            std::string word = base;
            word[pos] = newChar;
            
            if (words.insert(word).second) {
                if (words.size() >= n) break;
            } else {
                positions.erase(positions.begin() + posIdx);
            }
        }
        
        while (words.size() < n) {
            int len = rnd.next(1, maxlen);
            std::string word;
            for (int i = 0; i < len; i++) {
                word += rnd.next('A', 'Z');
            }
            words.insert(word);
        }
    }
    
    for (const auto& word : words) {
        println(word);
    }
} 