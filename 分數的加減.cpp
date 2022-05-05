#include <iostream>
#include <cmath>
using namespace std;
class Rational{
	private:
		int whole;
		int numer;
		int denom;
	public:
		Rational()=default;
		Rational(int w,int n,int d=1):whole(w),numer(n),denom(d){};
		void printRational();
		Rational operator +(Rational);
		Rational operator -(Rational);
		friend istream & operator >>(istream& in,Rational& obj);
		friend ostream & operator <<(ostream& out,Rational& obj);
};
int gcd(int a,int b){
	int i=1;
	int min = a<b?a:b;
	for(int j=1;j<=min;j++){
		if(a%j==0 && b%j==0){
			i = j;
		}
	}
	return i;
}
void Rational::printRational(){
	cout<<whole<<" "<<numer<<"/"<<denom<<endl;
}
Rational Rational::operator +(Rational obj){
	Rational temp;
	int i = gcd(denom,obj.denom);
	temp.denom = denom*obj.denom/i;
	temp.numer = (denom*obj.numer + numer*obj.denom)/i;
	temp.whole = whole + obj.whole;
	return temp;
} 
Rational Rational::operator -(Rational obj){
	Rational temp;
	int i = gcd(denom,obj.denom);
	temp.denom = denom*obj.denom/i;
	temp.numer = (numer*obj.denom - denom*obj.numer)/i;
	temp.whole = whole - obj.whole;
	if(temp.numer < 0){
		temp.whole-=1;
		temp.numer+=temp.denom;
	}
	return temp;
}  
istream & operator >>(istream& in,Rational& obj){
	in>>obj.whole>>obj.numer>>obj.denom;
	return in;
}
ostream & operator <<(ostream& out,Rational& obj){
	int i=gcd(obj.numer,obj.denom);
	if(obj.numer>obj.denom){
		obj.whole+=obj.numer/obj.denom;
		obj.numer %= obj.denom;
	}
	out<<obj.whole<<" "<<obj.numer/i<<"/"<<obj.denom/i<<endl;
	return out;
}

int main(){
	Rational r1,r2,r3;
	cin>>r1>>r2;
	cout<<r1<<r2;
	r3 = r1 - r2;
	cout<<r3;
	return 0;
}
