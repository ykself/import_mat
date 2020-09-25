#include "iostream"
#include "import_mat.h"
#include "mat.h"

using namespace std;

const int LENGTH_NUM = 10000;		//数据总长度
const int COL = 10;					//得到的.mat文件的数据行数
const int ROW = 1000;				//得到的.mat文件的数据列数

extern uint16 col, row;		//col为行，row为列

extern MATFile* pmatfile_w;
extern mxArray* pMxArray_w;

MATFile* pmatfile_r = NULL;
mxArray* pMxArray_r = NULL;

int main()
{


	int M, N;

	//读取.mat文件
	double* RB;
	
	pmatfile_r = matOpen("matfile5.mat", "r");	//打开只读
	if (!pmatfile_r)		//没有读到退出程序
		return -1;
	pMxArray_r = matGetVariable(pmatfile_r, "R");
	if (!pMxArray_r)		//没有该元素退出程序
		return -2;
	RB = (double*)mxGetData(pMxArray_r);
	M = mxGetM(pMxArray_r);
	N = mxGetN(pMxArray_r);
	if (M < 1 || N < 1)
		return -3;

	cout << "M = " << M << "//" << "N = " << N<<endl;
	
	mat_init(LENGTH_NUM, COL, ROW);

	import_data_array(RB, LENGTH_NUM);
	mat_exit();

	matClose(pmatfile_r);


	return  0;



}