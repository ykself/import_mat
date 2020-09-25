#include "iostream"
#include "import_mat.h"
#include "mat.h"

using namespace std;

const int LENGTH_NUM = 10000;		//�����ܳ���
const int COL = 10;					//�õ���.mat�ļ�����������
const int ROW = 1000;				//�õ���.mat�ļ�����������

extern uint16 col, row;		//colΪ�У�rowΪ��

extern MATFile* pmatfile_w;
extern mxArray* pMxArray_w;

MATFile* pmatfile_r = NULL;
mxArray* pMxArray_r = NULL;

int main()
{


	int M, N;

	//��ȡ.mat�ļ�
	double* RB;
	
	pmatfile_r = matOpen("matfile5.mat", "r");	//��ֻ��
	if (!pmatfile_r)		//û�ж����˳�����
		return -1;
	pMxArray_r = matGetVariable(pmatfile_r, "R");
	if (!pMxArray_r)		//û�и�Ԫ���˳�����
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