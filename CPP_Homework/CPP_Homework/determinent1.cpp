  #include <iostream>  

using namespace std;

double det(int n, double *aa)
{
	if (n == 1)
		return aa[0];
	double *bb = new double[(n - 1)*(n - 1)];//����n-1�׵Ĵ�������ʽ��bb    
	int mov = 0;//�ж����Ƿ��ƶ�   
	double sum = 0.0;//sumΪ����ʽ��ֵ  
	for (int arow = 0; arow < n; arow++) // a�������Ѿ���a(nn)��ֵ��b(n-1)  
	{
		for (int brow = 0; brow < n - 1; brow++)//��aa���һ�и�Ԫ�صĴ�������ʽ�浽bb  
		{
			mov = arow > brow ? 0 : 1; //bb��С��arow���У�ͬ�и�ֵ�����ڵĴ�������ڵļ�һ  
			for (int j = 0; j < n - 1; j++)  //��aa�ĵڶ��и�ֵ����n��  
			{
				bb[brow*(n - 1) + j] = aa[(brow + mov)*n + j + 1];
			}
		}
		int flag = (arow % 2 == 0 ? 1 : -1);//��Ϊ����Ϊ0������������ż��ʱ�򣬴�������ʽΪ1.  
		sum += flag * aa[arow*n] * det(n - 1, bb);//aa��һ�и�Ԫ�������������ʽ���ĺͼ�Ϊ����ʽ
	}
	delete[]bb;
	return sum;
}
int main()
{
	int n = 0; //����
	cout<<"�������:";
	cin >> n; /*�������*/
	double *aa = new double[n*n];
	cout<<"�������:\n";
	for (int i = 0; i < n*n; i++)
		cin >> aa[i];
	cout<<"\n����ʽ��%f\n"<< det(n, aa);
	delete[]aa;
}
