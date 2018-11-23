
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

int main()
{
loop:
    encryption E;
    char c;
    int num_letters = 0;
    string word = " ";
    int i = 0;
    int choice = 0;
    string messege = " ";
    

    cout << "1. Encypt" << endl << "2. Decrypt" <<endl;
    cin >> choice;
    
    if(choice == 1)
    {
        cout << "Encyption type 1 or 2: ";
        cin>> num_letters;
        cout << "type period to end";
        cout << endl;
    
        cout << endl;
    
        while(word != ".")
        {
            cin >> word;
            if(word == ".")
                break;

            messege += E.encode(word, num_letters);
            messege += " ";
        
            i++;
    
        }
    
       
    }
    else
    {
        cout << "What type of encyption did you recive? ";
        cin >> num_letters;
        cout << endl;
        
        cout << "Please enter what you want to decrypt" << endl;
        while(word != ".")
        {
            cin >> word;
            
            if(word == ".")
                break;
            
            messege += E.decode(word, num_letters);
            messege += " ";
        }
    }
    
    cout << endl;
    cout << messege << endl <<endl;
    
    cout << "Do you want to Encrypt or Decrypt another messege? y/n " ;
    cin >> c;
    
    if(c == 'y')
        goto loop;
 
    
    return 0;
}

