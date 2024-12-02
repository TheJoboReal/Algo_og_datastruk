#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <sstream>

// OPG 1

std::string deletePunktuation(std::string s){
    std::string newString;
    for(int i = 0; i < s.size(); i++){
        if(std::isalpha(s[i]) || std::isspace(s[i])){
            newString += s[i];
        }
    }
    return newString;
};


std::string wordFrequenzy(std::string sentence){
    std::vector<std::string> words;
    std::vector<std::tuple<std::string, int>> wordcount;
    std::string word;
    std::string words_lower;
    std::string s = deletePunktuation(sentence);


    for(int i = 0; i < sentence.size(); i++){
        words_lower += std::tolower(sentence[i]);
    }

    std::stringstream ssword(words_lower);
    while(ssword >> word){
        words.push_back(word);
    }

    for(int i=0; i < words.size(); i++){
        int count = 0;
        for(int j=0; j < words.size(); j++){
            if(words[i] == words[j]){
                count++;
            }
            wordcount.emplace_back(words[i], count);
        }
    }

    return words[1];

};

int main(){
    wordFrequenzy("Hej med dig, jeg er sgu ret sej men med dig og.");
}