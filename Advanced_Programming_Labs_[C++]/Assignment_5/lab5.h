#ifndef LAB5
#define LAB5

#include <string>
#include <cctype>
#include <algorithm>


bool vowel(char s){

    if (s == 'A' || s == 'a' || s == 'E' || s == 'e' || s == 'I' || s == 'i' || s == 'O' || s == 'o' || s == 'U' || s == 'u') {
        return true;
    }

    return false;
}

int countVowels(std::string s){

    int count = 0;
    int i = 0;

    while (s[i]){

        count += int(vowel(s[i]));
        i++;

    }    
    
    return count;
}

std::pair<std::string, std::string> SplitString(std::string s){

    int size = s.size();
    int half = size / 2;
    std::string one = "";
    std::string two = "";

    for (int k = 0; k < half; k++){
        one = one + s[k];
        two = s[(size-1) - k] + two;
    }

    return std::make_pair(one,two);
}

bool isStable(std::string s){

    std::pair<std::string, std::string> Split = SplitString(s);
    return countVowels(Split.first) == countVowels(Split.second);

}

bool hasDoubleLetters(std::string s){

    int y = 0;

    while (s[y+1]){

        if (s[y] == s[y+1]){

            return true;
        }

        y++;
    }

    return false;
}


std::string interleave(std::string word1, std::string word2){

    int z = 0;

    std::string result = "";

    while (word1[z] || word2[z]){

        if (z < word1.size()){

            result = result + word1[z];
        }

        if (z < word2.size()){

            result = result + word2[z];
        }

        z++;

    }

    return result;
}


std::string lcp(std::string s1, std::string s2){

    int a = 0;
    
    std::string result = "";
    
    while (s1[a] && s2[a]){

        if (s1[a] == s2[a]){

            result = result + s1[a];

        }

        else{

            return result;
        }

        a++;

    }
    
}


std::string extractLastName(std::string full_name, std::string email){
    
    int b = 1;

    std::string lastName = "";

    while (email[b] != '@' && !((email[b] == '0' || email[b] == '1' || email[b] == '2' || email[b] == '3' || email[b] == '4' || email[b] == '5' || email[b] == '6' || email[b] == '7' || email[b] == '8' || email[b] == '9'))){

        lastName = lastName + email[b];

        b++;
    }

    b = 0;
    while (true){

        std::string possibleName = full_name.substr(full_name.length() - (lastName.length()+b));

        std::string possibleName2 {possibleName};

        possibleName.erase(remove_if(possibleName.begin(), possibleName.end(), isspace), possibleName.end());

        if (possibleName.length() == lastName.length()){

            return possibleName2;
        }

        b++;
    }
}

#endif
