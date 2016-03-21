#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool checkOperator(string token , char first){
	if( first == '*'){cout<<first<<"       "<<"MULT"<<endl; }
	else if ( first == '+'){cout<<first<<"       "<<"PLUS"<<endl; }
	else if ( first == '-'){cout<<first<<"       "<<"MINUS"<<endl; }
	else if ( first == '='){cout<<first<<"       "<<"Assign"<<endl; }
	else if ( first == ';'){cout<<first<<"       "<<"SEMI_COLON"<<endl; }
	else return false;
	return true;
}

void checkToken(string token , char first){
	if( token == "int"){
	cout<<token<<"  "<<"INT_NUM"<<endl; 
	 }
	else if( token == "float"){
	cout<<token<<"  "<<"FLOAT_NUM"<<endl;
	 }

}


int main()
{	

  string line;
  string token;
  char first;
  char next;
  ifstream myfile ("code.cpp");
  int lineNumber = 0;
  
   cout<<"line Number ___ Token ___ Type "<<endl;
  
    while(getline (myfile,line)){
    	lineNumber++;
    	while(line.size()>0){
    	    	if(line[0] == ' '){ line.erase(0, 1); }
		first = line[0];  // take first character of string
    	next = line[1];   // take next character of string

 cout<<"    "<<lineNumber<<"        |    ";



//==========Letter==========//
if ((first > 64 && first < 91) || (first > 96 && first < 123)){
    token = token + first;
    while( (next > 64 && next < 91) || (next > 96 && next < 123)){
    	line.erase(0 , 1); // erase string from 0 to 1 //to remove the first character	
		first = line[0];  // take first character of string
    	next = line[1];   // take next character of string
        token = token + first;
	}
			if( token == "int"){cout<<token<<"     "<<"INT_NUM"<<endl; }
	       else if( token == "float"){cout<<token<<"       "<<"FLOAT_NUM"<<endl;}
		else{cout<<token<<"       "<<"letter"<<endl;}
		token.clear();

   }
//==========Letter==========//
//==========Digit==========//
if (first > 47 && first < 58 ){
    token = token + first;
    while( next > 47 && next < 58 ){
    	line.erase(0 , 1); // erase string from 0 to 1 //to remove the first character	
		first = line[0];  // take first character of string
    	next = line[1];   // take next character of string
        token = token + first;
	}
		
		cout<<token<<"       "<<"Digit"<<endl;
		token.clear();

   }
//==========Digit==========//

//==========Opeartor==========//
 if(checkOperator( token ,  first) == true ){
 	    line.erase(0 , 1); // erase string from 0 to 1 //to remove the first character	
 		first = line[0];  // take first character of string
    	next = line[1];   // take next character of string
 }
//==========Opeartor==========//
 
   line.erase(0 , 1); // erase string from 0 to 1 //to remove the first character	
}		

    }		
    


	
	
	return 0;
}
