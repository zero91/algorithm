// Problem: 
//
// You are given a string, s, and a list of words, words, that are all of the same length.
// Find all starting indices of substring(s) in s that is a concatenation of each word
// in words exactly once and without any intervening characters.
//
// For example, given:
// s: "barfoothefoobarman"
// words: ["foo", "bar"]
//
// You should return the indices: [0,9].
// (order does not matter).
//
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if (words.size() == 0) return ans;

        unordered_map<string, int> freq;
        for (auto it = words.begin(); it != words.end(); ++it) {
            ++freq[*it];
        }

        size_t word_size = words[0].size();
        unordered_map<string, int> cnt;
        for (size_t i = 0; i < word_size; ++i) {
            cnt.clear();
            int words_num = 0;
            for (size_t j = i, left = j; j + word_size <= s.size(); j += word_size) {
                string sub = s.substr(j, word_size);
                if (freq.find(sub) != freq.end()) {
                    ++cnt[sub];
                    ++words_num;
                    while (freq[sub] < cnt[sub]) {
                        --cnt[s.substr(left, word_size)];
                        --words_num;
                        left += word_size;
                    }

                    if (words_num == words.size()) {
                        ans.push_back(left);
                    }
                } else {
                    cnt.clear();
                    words_num = 0;
                    left = j + word_size;
                }
            }
        }
        return ans;
    }
};

class Solution_OLD {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<std::string, int> freq;

        int word_size = 0;
        int tot_word_size = 0;
        for (auto it = words.begin(); it != words.end(); ++it) {
            freq[*it] += 1;
            word_size = it->size();
            tot_word_size += word_size;
        }

        unordered_map<std::string, int> cnt;
        string sub;
        size_t j = 0;
        for (size_t i = 0; i + tot_word_size <= s.size(); ++i) {
            cnt.clear();
            for (j = 0; j < words.size(); ++j) {
                sub = s.substr(i + j * word_size, word_size);
                if (freq.find(sub) == freq.end()) {
                    break;
                }
                ++cnt[sub];
                if (cnt[sub] > freq[sub]) break;
            }
            if (j >= words.size()) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};

int main() {
    //string s = "barfoothefoobarman";
    string s = "wordgoodgoodgoodbestword";

    vector<string> words;
    words.push_back("word");
    words.push_back("good");
    words.push_back("best");
    words.push_back("good");

    //words.push_back("foo");
    //words.push_back("bar");

    Solution sol;
    vector<int> ans = sol.findSubstring(s, words);
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << endl;
    }
    return 0;
}
