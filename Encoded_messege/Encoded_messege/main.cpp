//
//  main.cpp
//  Encoded_messege
//
//  Created by Catalina Diaz on 11/22/18.
//  Copyright © 2018 Catalina Diaz. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include "encrypt.h"

using namespace std;


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
