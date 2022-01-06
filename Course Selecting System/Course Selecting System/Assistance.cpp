#include "Assistance.h"

// 通用异常类的实现部分

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
// 操作结果：从输入流inStream中跳过空格及制表符获取一字符
{
	char ch;								// 临时变量
	while ((ch = (inStream).peek()) != EOF	// 文件结束符(peek()函数从输入流中接受1
											// 字符,流的当前位置不变)
		&& ((ch = (inStream).get()) == ' '	// 空格(get()函数从输入流中接受1字符,流
											// 的当前位置向后移1个位置)
			|| ch == '\t'));					// 制表符

	return ch;								// 返回字符
}

Error::Error(const char* mes)
// 操作结果：由mes构构通用异常对象
{
	strcpy_s(message, mes);				// 复制异常信息
}

void Error::Show()const
// 操作结果：显示异常信息
{
	cout << message << endl;			// 显示异常信息	
}