#include "testlib.h"
#include <bits/stdc++.h>

std::string generateWord(int minLen, int maxLen) {
    int len = rnd.next(minLen, maxLen);
    std::string result;
    for (int i = 0; i < len; i++) {
        result += rnd.next('a', 'z');
    }
    return result;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    
    int n = opt<int>("n");
    int q = opt<int>("q");
    int minLen = opt<int>("minLen");
    int maxLen = opt<int>("maxLen");
    int type = opt<int>("type");
    
    std::cout << n << "\n";
    
    std::set<std::string> words;
    while (words.size() < n) {
        if (type == 1) {
            words.insert(generateWord(minLen, maxLen));
        } else if (type == 2) {
            std::string prefix = generateWord(1, 3);
            words.insert(prefix + generateWord(minLen - prefix.length(), maxLen - prefix.length()));
        }
    }
    
    for (const auto& word : words) {
        std::cout << word << "\n";
    }
    
    std::cout << q << "\n";
    for (int i = 0; i < q; i++) {
        if (type == 1 || rnd.next(0, 1)) {
            std::cout << generateWord(1, maxLen) << "\n";
        } else {
            auto it = words.begin();
            std::advance(it, rnd.next(0, (int)words.size() - 1));
            std::string word = *it;
            int prefixLen = rnd.next(1, (int)word.length());
            std::cout << word.substr(0, prefixLen) << "\n";
        }
    }
} 