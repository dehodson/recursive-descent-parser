//Drew Hodson
//Section: 1:00 PM

#include <iostream>
#include <cstdlib>

char token; //lookahead token;

void E();
void C();
void A();

void getoken(){
	std::cin.get(token);
	std::cout << token;
	while(token ==' ' || token=='\r' || token=='\n'){
		std::cin.get(token); 
		std::cout << token;
	}
 	if (
		token>='a' && token <= 'z' ||
		token=='{'||token=='}'     ||
		token=='('||token==')'     ||
		token==','||token=='$' ) ; //okay
	else{ 
		std::cout <<"\nERROR: unrecognizable symbol in input\n";
		exit(1);
	}
}



int main()
{
	getoken();
	//E();
	if(token != '$'){
		std::cout << "\nERROR: $ expected\n";
		exit(1);
	}
	else std::cout <<"\nThe input is syntactically correct!\n";
	return 0;
} //end main()

//the functions for the parser appear below