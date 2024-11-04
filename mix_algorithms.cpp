#include<iostream>
#include <stdio.h>
#include<string>
using namespace std;

string caeserEncrypt(const string &text, int shift){
    string result;
    for (char ch : text){
        if(isalpha(ch)){
            char base = islower(ch)?'a':'A';
            result+=(ch-base+shift)%26+base;
        } else{
            result+=ch;
        }
    }
    return result;
    
}
string RLE(const string &text){
    string encoded;
    int count=1;
    for(size_t i=1; i<=text.size();++i){
        if(i<text.size()&&text[i]==text[i-1]){
            ++count;
            
        }else{
            encoded+=text[i-1];
            if(count>1){
                encoded+=to_string(count);
            }
            count=1;
        }
    }
    return encoded;
}
int main()
{
   string input;
   int shift;
    
cout<<"Enter text: ";
getline(cin,input);

cout<<"Enter shift: ";
cin>>shift;

string encryptedText=RLE(caeserEncrypt(input,shift));

cout<<"Encrypted text: "<<encryptedText;



}