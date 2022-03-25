// FCAI – Programming 1 – 2022 - Assignment 2
// Program Name: caesar _cipher_20210141.cpp
// Program Description: it is a cipher and dicipher app
// Last Modification Date: 25/03/2022
// Author1 and ID and Group: remon atef mahrows daniel, 20210141, group a
// Purpose: ciphering words
#include <iostream>
#include<ios>    
#include<limits>
using namespace std;
void cipher(int shift, string k){
    string x;
    cout << "enter the text u want to " << k << ":\n";  
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(cin, x); //geting the word
    cout << "the " << k << " result is: ";
    char arr[x.length()];
    if(shift > 26 || shift < -26){ // if user enterd a numper bigger than 26 or less than -26 i take the mod
        shift %= 26;
    }
    for(int i = 0; i < x.length(); i++){
        int big_l, small_l;
        if(x[i] != ' '){
            if(65 <= (int)x[i] && (int)x[i] <= 90){ // here i decide if the letter is uppercase or lowwercase
                big_l = 90;
                small_l = 65;
            }
            else if(97 <= (int)x[i] && (int)x[i] <= 122){
                big_l = 122;
                small_l = 97;
            }
            if((int)(x[i] + shift) > big_l && shift > 0){
                cout << (char)(small_l+(shift-(big_l-(int)x[i])-1)); // if i entered a number that make the letter pass Z
            }
            else if(shift < 0 && (int)(x[i]) + shift < small_l){ // if shifts is negative and the letter passed A                    
                cout << (char)(big_l-(small_l-(x[i]+shift+1)));
            }
            else{
                cout << (char)(x[i]+shift);
            }
        }
        else{
            cout << ' ';
        }
    }
    cout << endl;
}
int main(){
    while(true){
    cout << "hello in cipher app\n"
         << "press \"1\" to cipher\n"
         << "press \"2\" to decipher\n"
         << "press \"3\" to exit\n"
         << ">>>> ";
        int order;
        cin >> order;
        while(order != 1 && order != 2 && order != 3){
            cout << "enter \"1\" or \"2\" or \"3\":\n";
            cin >> order;
        }
        if(order == 1){
            int shifts;
            cout << "enter the number of shifts u want:\n";
            cin >> shifts;
            cipher(shifts, "cipher");
        }
        else if(order == 2){
            int key;
            cout << "enter the number of shifts that was done on the text:\n";
            cin >> key;
            key *= -1;
            cipher(key, "decipher");
        }
        else{
            break;
        }
    }
}