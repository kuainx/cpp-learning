//�����ܣ��ҳ�һ�����������е�Ԫ�ص����ֵ��
//�������ڴ��ʮ�����������ݳ�Ա����������int  array[10];��˽�еġ�
//���й�����Ա����set_value()�����ǴӼ�������10��������
//������Ա����max_value()�������ҵ�10�������е����ֵ��
//������Ա����show_value()������������ֵ��
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
	cout << "������10��������";
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

