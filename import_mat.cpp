#include "iostream"
#include "import_mat.h"
#include "mat.h"
#include <string.h> /* For strcmp() */

MATFile* pmatfile_w = nullptr;
mxArray* pMxArray_w = nullptr;

uint16 col=0, row = 0;		//col为行，row为列

const char* file = "mattest.mat";
//初始化
void mat_init(uint16 x,uint16 col_local, uint16 row_local)
{
	row = row_local;
	col = col_local;
	pmatfile_w = matOpen(file, "w");		//打开文件并写入数据
	//if (!pmatfile_w)		//没有正常生成文件
		//TODO: 当没有正常生成文件时所作的处理
	/*if(!(x%row))
		col = x / row ;
	else if(x%row)
		col = x / row + 1;
	*/
}
/*
mxArray *pa2 = mxCreateDoubleMatrix(3,3,mxREAL);		//第一个数为待申请的行数，第二个为待申请的列数，mxREAL表示为实数数组
memcpy((void *)(mxGetPr(pa2)), (void *)data, sizeof(data));	//将data数组中的数据拷贝到pa2中
int status = matPutVariableAsGlobal(pmat, "GlobalDouble", pa2);	//写入文件
*/

//导入数据,数据为数组，入股一开始为元素需要先弄成数组
void import_data_array(double* data, uint16 num)
{
		pMxArray_w = mxCreateDoubleMatrix(col, row, mxREAL);		//第一个数为待申请的行数，第二个为待申请的列数，mxREAL表示为实数数组
		memcpy((void*)(mxGetPr(pMxArray_w)), (void*)data, sizeof(double)*num);	//将data数组中的数据拷贝到pa2中
		//if (!pMxArray_w)
			//TODO: 当指针并未正常指向数据时所做的处理
		int status = matPutVariableAsGlobal(pmatfile_w, "GlobalDouble", pMxArray_w);	//写入文件
}

//关闭文件，释放内存
void mat_exit()
{
	matClose(pmatfile_w);								//关闭文件
}
