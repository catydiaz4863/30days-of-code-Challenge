//
//  encrypt.h
//  Encoded_messege
//
//  Created by Catalina Diaz on 11/22/18.
//  Copyright © 2018 Catalina Diaz. All rights reserved.
//
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class encryption
{
public:
    encryption()
    {
        
    }
    
    void odd(string &word)
    {
        for(int i = 0; i < word.length()-1; i++)
        {
            if(i != word.length() -3)
            {
                swap(word[i],word[i+1]);
                i++;
                
            }
        }
    }
    
    void even(string &word)
    {
        for(int i = 0; i < word.length()-1; i++)
        {
            if(i != word.length() -2)
            {
                swap(word[i],word[i+1]);
                i++;
                
            }
        }
    }
    void change_letter(string &word, char letter, int index)
    {
        string first = "abcdefghijklm";
        string second = "zyxwvutsrqpon";
        
        
        for(int i = 0; i < 13; i++)
        {
            if(first[i] == letter)
            {
                // cout << "swapping: " << first[i] << " " << second[i] << endl;
                word[index] = second[i];
                return;
            }
            if(second[i] == letter)
            {
                // cout << "swapping: " << second[i] << " " << first[i] << endl;
                word[index] = first[i];
                return;
            }
        }
    }
    string encode(string word, int det)
    {
        //first swap the words
        //WE SWAP EVERYTHING BUT THE LAST LETTER depending on the determinant
        if(det % 2 != 0)
            odd(word);
        else
            even(word);
        
        //change the letters a = z, b = y, c = x ...
        for(int i = 0; i < word.length(); i++)
            change_letter(word, word[i], i);
        
        
        return word;
    }
    
    string decode(string word, int det)
    {
        for(int i = 0 ; i < word.length(); i++)
            change_letter(word, word[i], i);
        
        if(det % 2 != 0)
            odd(word);
        else
            even(word);
        
        return word;
    }
};
