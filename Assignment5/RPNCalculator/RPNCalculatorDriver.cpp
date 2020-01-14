/****************************************************************/
/*                  RPN Calculator Driver File                  */
/****************************************************************/
/*      TODO: Implement driver as described in the writeup      */
/****************************************************************/

#include "RPNCalculator.hpp"
#include <iostream>
#include <iomanip>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: Determine whether some user input string is a
 *          valid floating point number
 * @param none
 * @return true if the string s is a number
 */
bool isNumber(string s)
{
    if(s.size() == 1 && s == "-") return false;
    else if(s.size() > 1 && s[0] == '-') s = s.substr(1);

    bool point = false;
    for(int i = 0; i < s.size(); i++)
    {
      if(!isdigit(s[i]) && s[i] != '.') return false;
      if(s[i]=='.' and !point) point = true;
      else if(s[i]=='.' and point) return false;
    }

    return true;
}

int main()
{
  RPNCalculator calc;

  cout << "Enter the operators and operands ('+', '*') in a postfix format" << endl;
  string input = "";

  while(input != "=")
  {
    cout << "#> ";
    getline(cin, input);
    if(isNumber(input)){
        calc.push(stof(input));
    }else if (input == "+" || input == "*"){
        calc.compute(input);
    }else;
  }

  if(calc.isEmpty()){
      cout << "No operands: Nothing to evaluate" << endl;
      return 0;
  }else{
      float temp = calc.getStackHead()->number;
      calc.pop();
      if(!calc.isEmpty()){
          cout << "Invalid expression" << endl;
          return 0;
      }else{
          cout << setprecision(4) << temp << endl;
          return 0;
      }
  }
}
