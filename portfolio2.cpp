#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <sstream>
#include <bits/stdc++.h>

// OPG 1

std::string deletePunktuation(std::string s, int index = 0){
    if(index == s.size()){      // Base case
        return "";        // Return empty string
    }
    char currentChar = s[index];    // Get current character
    if(std::isalpha(currentChar) || std::isspace(currentChar)){     // If current character is a letter
        return currentChar + deletePunktuation(s, index + 1);       // Return current character and call function again
    } else {
        return deletePunktuation(s, index + 1);
    }
}

std::string wordFrequenzy(std::string sentence){
    std::vector<std::string> words;
    std::string word;
    std::string the_word;
    std::string s = deletePunktuation(sentence);
    std::transform(s.begin(), s.end(), s.begin(),::tolower);
    int count = 0;
    int current_count = 0;


    std::stringstream ssword(s);
    while(ssword >> word){
        words.push_back(word);
    }


    for(int i=0; i < words.size(); i++){
        current_count = 0;
        for(int j=0; j < words.size(); j++){
            if(words[j] == words[i]){
                current_count ++;
            }
        }
        if(current_count > count){
            count = current_count;
            the_word = words[i];
        }
    }
    return the_word;
};

int main(){
    std::cout << wordFrequenzy("Hej med dig, jeg er sgu hej hej hej ret med. sej men med dig og") << std::endl;
}

// Opg 2

