#include <iostream>
using namespace std;
int main()
{
	char a[100],*p=a,c;
	int i=0,x;
	cout<<"�������ַ������ַ����к��пո�"<<endl;
	while ((c=getchar())!='\n')
	{
		a[i] = c;
		i++;
	}
	int countnum(char *);
	x=countnum(a);
	cout<<"�ַ�������"<<x<<"����ĸ"<<endl;
	system("pause");
	return 0;
}
int countnum(char *p)
{
	int i,count=0;
	while (*p != '\0')
	{
	if((*p>='a'&&*p<='z')||(*p>='A'&&*p<='Z'))
			count++;
	p++;
	}
	return count;
}

