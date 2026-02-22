
/**
   @file MarquisNevadaAssignment5_P8_2.cpp
   @author Nevada Marquis
   @date 2026-02-21
   @version 1.0

   Big C++ P8.2: Spell checker.
   Reads a dictionary file into a vector of words, then reads a target file and
   prints any words not found in the dictionary.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Author: Nevada Marquis
string to_lowercase(string s)
{
    for (int i = 0; i < static_cast<int>(s.size()); i++)
    {
        s[i] = static_cast<char>(tolower(static_cast<unsigned char>(s[i])));
    }
    return s;
}

// Author: Nevada Marquis
string trim_punctuation(string token)
{
    int start = 0;
    int end = static_cast<int>(token.size()) - 1;

    while (start <= end && ispunct(static_cast<unsigned char>(token[start])))
    {
        start++;
    }

    while (end >= start && ispunct(static_cast<unsigned char>(token[end])))
    {
        end--;
    }

    if (start > end)
    {
        return "";
    }

    return token.substr(start, end - start + 1);
}

// Author: Nevada Marquis
bool contains_word(const vector<string>&words, const string & target)
{
    for (int i = 0; i < static_cast<int>(words.size()); i++)
    {
        if (words[i] == target)
        {
            return true;
        }
    }
    return false;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        cout << "Usage: spellcheck <dictionary_file> <file_to_check>" << endl;
        return 1;
    }

    string dictionary_filename = argv[1];
    string check_filename = argv[2];

    ifstream dictionary_file(dictionary_filename.c_str());
    if (!dictionary_file)
    {
        cout << "Error: Could not open dictionary file: " << dictionary_filename << endl;
        return 1;
    }

    vector<string> words;
    string dict_word;

    while (dictionary_file >> dict_word)
    {
        dict_word = to_lowercase(dict_word);
        words.push_back(dict_word);
    }

    dictionary_file.close();

    ifstream check_file(check_filename.c_str());
    if (!check_file)
    {
        cout << "Error: Could not open file to check: " << check_filename << endl;
        return 1;
    }

    string token;

    while (check_file >> token)
    {
        token = trim_punctuation(token);
        token = to_lowercase(token);

        if (token != "" && !contains_word(words, token))
        {
            cout << token << endl;
        }
    }

    check_file.close();

    return 0;
}