#include "Assistance.h"

// ͨ���쳣���ʵ�ֲ���

int Getfnum(const char* filename)
{
	FILE* fp;
	char c;
	int  n = 0, L = 0;
	fp = fopen(filename, "r");
	while (1) {
		c = getc(fp);
		if (c == EOF) { L++; break; }
		if (c == '\n') { L++;  n = 0; };
	}
	fclose(fp);
	return L;
}

char GetChar(istream& inStream)
// �����������������inStream�������ո��Ʊ����ȡһ�ַ�
{
	char ch;								// ��ʱ����
	while ((ch = (inStream).peek()) != EOF	// �ļ�������(peek()�������������н���1
											// �ַ�,���ĵ�ǰλ�ò���)
		&& ((ch = (inStream).get()) == ' '	// �ո�(get()�������������н���1�ַ�,��
											// �ĵ�ǰλ�������1��λ��)
			|| ch == '\t'));					// �Ʊ��

	return ch;								// �����ַ�
}

Error::Error(const char* mes)
// �����������mes����ͨ���쳣����
{
	strcpy_s(message, mes);				// �����쳣��Ϣ
}

void Error::Show()const
// �����������ʾ�쳣��Ϣ
{
	cout << message << endl;			// ��ʾ�쳣��Ϣ	
}