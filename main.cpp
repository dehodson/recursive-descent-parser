//Drew Hodson
//Section: 1:00 PM

#include <iostream>
#include <cstdlib>

char token; //lookahead token;

void E();
void C();
void A();


void throw_error(char bad_token){
	std::cout << "\nERROR: " << bad_token << " expected.\n";
	exit(1);
}

void throw_error(){
	std::cout <<"\nERROR: unrecognizable symbol in input\n";
	exit(1);
}

void getoken(){
	std::cin.get(token);
	//std::cout << token;
	while(token ==' ' || token=='\r' || token=='\n'){
		std::cin.get(token); 
		//std::cout << token;
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
		throw_error('$');
		exit(1);
	}
	else std::cout <<"\nThe input is syntactically correct!\n";
	return 0;
} //end main()

//the functions for the parser appear below
void E(){
	C();

	getoken();

	if(token == ','){
		C();
	}
	else if(token == ')' || token == '}' || token == '$');
	else{
		throw_error();
	}
}

void C(){
	A();

	getoken();

	if(token == ',' || token == '}' || token == ')' || token == '$');
	else{
		A();
	}
}

void A(){
	getoken();

	if(token>='a' && token <= 'z');
	else if(token == '('){
		E();

		getoken();

		if(token != ')'){
			throw_error(')');
		}
	}
	else if(token == '{'){
		E();

		getoken();

		if(token != '}'){
			throw_error('}');
		}
	}else{
		throw_error();
	}
}