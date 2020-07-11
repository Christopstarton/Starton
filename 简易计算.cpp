#include <iostream>
#include<string>
using std::string;
using std::cin;
char sign;
float Calculate(void); 
float MulDiv(void);
float Blacket(void);
bool Validity(char s){
	if(s=='+'||s=='-'||s=='*'||s=='/'||s=='('||(s>= '0'&&s<='9'))
		return true;
	else{
		std::cout<<"Error!"<<std::endl;
		exit(-1);
		return false;
	}
		
}
int main(){
	float result=0;
	std::cout<<"Enter your expression:"<<std::endl;
	cin.get(sign);
	result = Calculate();
	std::cout<<result<<std::endl;
	return 0;
} 
float Calculate(){
	float r1;
	if(Validity(sign))
		r1=MulDiv();
	while(sign=='+'||sign=='-'){
		if(sign=='+'){
			cin.get(sign);
			r1 = r1 + MulDiv();
		}	
		else if(sign=='-'){
			cin.get(sign);
			r1 = r1 - MulDiv();
		}	
	}
	return r1;
}
float MulDiv(){
	float a,r2;
	if(Validity(sign))	
		r2 = Blacket();
	
	while(sign=='*'||sign=='/'){
		if(sign=='*'){
			cin.get(sign);
			r2 = r2 * Blacket();
		}	
		else if(sign=='/'){
			cin.get(sign);
			a = Blacket();
			if(a!=0)
				r2 = r2 / a;
			else{
				std::cout<<"The divisor cannot be 0!"<<std::endl;
				exit(-1);
			}
		}	
	}
	return r2;
}
float Blacket(){
	float r3;
	if(Validity(sign)){
		if(sign=='('){
			cin.get(sign);
			r3= Calculate();
			if(sign==')')
				sign = getchar();
			else{
				std::cout<<"Error!"<<std::endl;
				exit(-1);
			}
		}
		else if(sign>= '0'&&sign<='9'){
			cin.putback(sign); 
			cin>>r3;
			cin.get(sign);
		}
	}
	return r3;
}
