//程序功能：找出一个整型数组中的元素的最大值。
//类中用于存放十个整数的数据成员的整型数组int  array[10];是私有的。
//类中公共成员函数set_value()功能是从键盘输入10个整数；
//公共成员函数max_value()功能是找到10个整数中的最大值；
//公共成员函数show_value()功能是输出最大值。
#include <iostream>
using namespace std;
class value {
private:
	int array[10];
	int max;
public:
	void set_value();
	void max_value(); 
	void show_value();
};
void value::set_value()
{	
	int i;
	cout << "请输入10个整数：";
	for(i=0;i<=9;i++)
		cin >> array[i];
}
void value::max_value()
{
	int i,j,temp,max;
	for(i=0;i<=8;i++)
		for(j=0;j<=8;j++)
			if(array[j]>array[j+1]) 
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
	max=array[9];
}
void value::show_value()
{
	cout << "max=" << max << endl;
}

int main()
{
	value value1;
	value1.set_value();
	value1.max_value();
	value1.show_value();
	system("pause");
	return 0;
}

