#include <stdio.h>
#include <math.h>

int main(void)
{
	printf( "���p�O�p�`�̎Ζʂ̒��������߂܂��B\n" );

	float side0 = 0.0f;
	float side1 = 0.0f;
	int result = 0;

	printf("�Εӂł͂Ȃ��ӂ̒���1����͂��Ă��������B\n");
	result = scanf( "%f", &side0 );
	if (!result)	return 0;	// �������l���擾�ł��Ȃ������̂ŋ����I��

	printf("�Εӂł͂Ȃ��ӂ̒���2����͂��Ă��������B\n");
	result = scanf( "%f", &side1 );
	if (!result)	return 0;	// �������l���擾�ł��Ȃ������̂ŋ����I��

	// sqrtf()	�����������߂�֐�
	printf("�Εӂ̒��� = %f\n", sqrtf(side0 * side0 + side1 * side1));

	return 0;
}
