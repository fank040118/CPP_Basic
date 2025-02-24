/* 
 * File:   PowerString.cpp
 * Purpose: provide the definition of the PowerString class
 *
 * Author: Anthony Wang
 *
 */
#include <iostream>
#include <stack>
#include "PowerString.h"

// initialize str with ini_str passing as a parameter
PowerString::PowerString(string ini_str)
{
    str = ini_str;
}

// return the current value of the private data member: str
string PowerString::getString() const
{
    return str;
}

// set the value of str to be the passed in parameter input_str
void PowerString::setString(string input_str)
{
    str = input_str;
}

// return a reverse string
// using a loop to implement
// Note that the private data member named str, has not been changed
string PowerString::rev_loop() const
{
    string result;
    for (int i=str.length()-1; i>=0; i--)
        result = result + str[i];
    return result;
}

// return a reverse string
// using recursion to implement
// Note that the private data member named str, has not been changed
string PowerString::rev_recursion() const
{
    // base case, if size of str == 1 or less, then return the str
    // since it can't be reversed anymore
    if(str.size() <= 1){
        return str;
    }
    
    // create a new PowerString variable that don't contain the last Char
    PowerString newStr(str.substr(0, str.size()-1));
    // last char of str + last char of str-1 + last char of str-2 ......
    return str.substr(str.size()-1) + newStr.rev_recursion();
}

// return a reverse string
// using a stack to implement
// Note that the private data member named str, has not been changed
string PowerString::rev_stack() const
{
    // create a stack, push all char of str into stack
    stack<char> strStack;
    for(int i = 0; i < str.size(); ++i){
        strStack.push(str[i]);
    }
    // create new string, push all char of stack into string
    // then pop the top char of stack
    string newString;
    while(!strStack.empty()){
        newString.push_back(strStack.top());
        strStack.pop();
    }
    return newString;
}

// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// calling member function to  implement
// Note that the private data member named str, has not been changed
bool PowerString::isPalindrome() const
{
    if (str == this->rev_loop())
        return true;
    else
        return false;
}

// return true if str is a palindrome
// otherwise return false
// A palindrome is defined as a sequence of characters which reads the same backward as forward
// using recursion to implement
// Note that the private data member named str, has not been changed
bool PowerString::isPalindrome_recursion() const
{
    // base case
    if (str.length() <= 1)
        return true;
    else // recursive case
    {
        PowerString shorter(str.substr(1, str.length()-2));
        bool firstPair = str[0] == str[str.length()-1];
        return (firstPair && shorter.isPalindrome_recursion());
    }    
}

// generate a palindrome with even number of characters
// by concatenate the original str with the reverse of str
// Note that the private data member named str, has not been changed
string PowerString::evenPalindrome() const
{
    // use rev_loop() to get the reverse string
    return str + rev_loop();
}

// generate a palindrome with odd number of characters using recursion
// it is formed by the original str followed by the reverse of the str cutting away the last character from str
// e.g. if str is "abc", it returns "abcba"
// Note that the private data member named str, has not been changed
string PowerString::oddPalindrome() const
{
    // use rev_recursion() to get the reverse string
    // add str(without last char) and rev_recursion() together
    return(str.substr(0, str.size()-1) + rev_recursion());

    // if you mean write a recursion in this function, here is one, idk is it require to not use 
    // use a member function:
    /*_______________________________________________________________
    // base case, if size of str == 1 or less, then return the str
    // since it can't be reversed anymore
    if(str.size() <= 1){
        return str;
    }
    // create a new PowerString variable that don't contain the last Char
    PowerString newStr(str.substr(0, str.size()-1));
    // last char of str + last char of str-1 + last char of str-2 ......
    return str.substr(0, str.size()-1) + str.substr(str.size()-1) + newStr.rev_recursion();
    */
}

// displays str followed by a new line marker
// to the standard output
void PowerString::print() const
{
    // cout str
    cout << str << endl;
}
