#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <sstream>

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
    std::string words_lower;
    std::string s = deletePunktuation(sentence);
    int count = 0;
    int current_count = 0;


    for(int i = 0; i < s.size(); i++){
        words_lower += std::tolower(s[i]);
    }

    std::stringstream ssword(words_lower);
    while(ssword >> word){
        words.push_back(word);
    }


    for(int i=0; i < words.size(); i++){
        current_count = -1;
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
    std::cout << wordFrequenzy("Hej med dig, jeg er sgu ret med. sej men med dig og") << std::endl;
}