#include<iostream>
using namespace std;
int main(void){
	int n, i;
	// int��Χ[-2^31,2^31)����Ŀ��Χ��[-2^31,2^31]������Ҫ����a+b��� 
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
