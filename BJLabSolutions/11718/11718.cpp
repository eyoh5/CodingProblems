#include <iostream>
#include <string>

int main(){

	std:: string out;

    while(1){
        std::string in;
        std::getline(std::cin, in);
        if(std::cin.eof()) break;
    	
	out += in +"\n";
    
    }
    
    std::cout<<out;

    return 0;
    
}
