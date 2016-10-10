// DLLMatlab.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include "mclmcr.h"
#include "matrix.h"
#include "mclcppclass.h"
#include "myAdd.h"
using namespace std;

int main()
{

	if (!myAddInitialize())    //初始化，在libmysvd.h中
	{
		cout << "Could not initialize libmysvd!" << endl;
		exit(0);
	}
	double data[2] = { 1.0, 2.0 };
	double date[2] = { 1.0, 1.0 };
	mwArray mwA(1, 2, mxDOUBLE_CLASS);
	mwArray mwB(1, 2, mxDOUBLE_CLASS);
	mwA.SetData(data, 2);
	mwB.SetData(date, 2);
	mwArray mwC(1, 2, mxDOUBLE_CLASS);
	myAdd(1,mwC,mwA,mwB);
	cout << mwC.Get(1,1) << endl;
	cout << mwC.Get(1, 2) << endl;


	myAddTerminate();

	cin.get();
	return 0;
}
