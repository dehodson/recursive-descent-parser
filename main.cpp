//Drew Hodson
//Section: 1:00 PM

#include <iostream>
#include <cstdlib>
#include <string.h>

char token; //lookahead token;

void E();
void C();
void A();


void throw_error(std::string message){
	std::cout << "\nERROR: " << message << " expected.\n";
	exit(1);
}

void throw_error(){
	std::cout <<"\nERROR: unrecognizable symbol in input\n";
	exit(1);
}

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
		token==','||token=='$' );
	else{ 
		throw_error();
	}
}

int main()
{
	getoken();
	E();

	if(token != '$'){
		throw_error("$");
		exit(1);
	}
	else std::cout <<"\nThe input is syntactically correct!\n";
	return 0;
} //end main()

//the functions for the parser appear below
void E(){
	C();

	while(token == ','){
		getoken();

		C();
	}
	if(token == ')' || token == '}' || token == '$');
	else{
		throw_error("), }, or $");
	}
}

void C(){
	A();

	while(token >= 'a' && token <= 'z' || token == '(' || token == '{'){
		A();
	}
}

void A(){
	if(token >= 'a' && token <= 'z'){
		getoken();
	}
	else if(token == '('){
		getoken();

		E();

		getoken();
	}
	else if(token == '{'){
		getoken();

		E();

		getoken();
	}else{
		throw_error("id, (, or {");
	}
}