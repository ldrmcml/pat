#include<iostream>
using namespace std;
int main(void){
	int n, i;
	// int范围[-2^31,2^31)，题目范围是[-2^31,2^31]，而且要避免a+b溢出 
	double a, b, c;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a>>b>>c;
		if(a+b>c)
			cout<<"Case #"<<i+1<<": true"<<endl;
		else
			cout<<"Case #"<<i+1<<": false"<<endl;
	}
	system("pause");
	return 0;
}
