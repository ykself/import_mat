#include "iostream"
#include "import_mat.h"
#include "mat.h"
#include <string.h> /* For strcmp() */

MATFile* pmatfile_w = nullptr;
mxArray* pMxArray_w = nullptr;

uint16 col=0, row = 0;		//colΪ�У�rowΪ��

const char* file = "mattest.mat";
//��ʼ��
void mat_init(uint16 x,uint16 col_local, uint16 row_local)
{
	row = row_local;
	col = col_local;
	pmatfile_w = matOpen(file, "w");		//���ļ���д������
	//if (!pmatfile_w)		//û�����������ļ�
		//TODO: ��û�����������ļ�ʱ�����Ĵ���
	/*if(!(x%row))
		col = x / row ;
	else if(x%row)
		col = x / row + 1;
	*/
}
/*
mxArray *pa2 = mxCreateDoubleMatrix(3,3,mxREAL);		//��һ����Ϊ��������������ڶ���Ϊ�������������mxREAL��ʾΪʵ������
memcpy((void *)(mxGetPr(pa2)), (void *)data, sizeof(data));	//��data�����е����ݿ�����pa2��
int status = matPutVariableAsGlobal(pmat, "GlobalDouble", pa2);	//д���ļ�
*/

//��������,����Ϊ���飬���һ��ʼΪԪ����Ҫ��Ū������
void import_data_array(double* data, uint16 num)
{
		pMxArray_w = mxCreateDoubleMatrix(col, row, mxREAL);		//��һ����Ϊ��������������ڶ���Ϊ�������������mxREAL��ʾΪʵ������
		memcpy((void*)(mxGetPr(pMxArray_w)), (void*)data, sizeof(double)*num);	//��data�����е����ݿ�����pa2��
		//if (!pMxArray_w)
			//TODO: ��ָ�벢δ����ָ������ʱ�����Ĵ���
		int status = matPutVariableAsGlobal(pmatfile_w, "GlobalDouble", pMxArray_w);	//д���ļ�
}

//�ر��ļ����ͷ��ڴ�
void mat_exit()
{
	matClose(pmatfile_w);								//�ر��ļ�
}
