#include<iostream>
using namespace std;
typedef int DataType;struct Stack {
	int top;
	int maxSize;
	DataType* elements;
};
//初始化一个空的栈
Stack* initStack(int size) {
	Stack* s = new Stack;
	s->maxSize = size;
	s->elements = new DataType[size];
	s->top = -1;
	return s;
}
//判断栈是否为空
bool isEmpty(Stack* s) {
	return s->top == -1;
}
//判断栈是否为满
bool isFull(Stack* s) {
	return s->top == s->maxSize - 1;
}
//入栈
bool push(Stack* s, DataType x) {
	if (isFull(s)) {
		cout << "Stack is full!" << endl;
		return false;
	}
	s->top++;
	s->elements[s->top] = x;
	return true;
}
//出栈
bool pop(Stack* s, DataType& x) {
	if (isEmpty(s)) {
		return false;
	}
	x = s->elements[s->top];
	s->top--;
	return true;
}
//获取栈顶元素
bool getTop(Stack* s, DataType& x) {
	if (isEmpty(s)) {
		return false;
	}
	x = s->elements[s->top];
	return true;
}
void destroyStack(Stack* s) {
	if (s != nullptr) {
		delete[] s->elements;
		delete s;
	}
}
void decimalToBinary(int number, int base) {
	if (base < 2 || base >9) {
		cout << "错误：进制超出范围(2<=base<=9)" << endl;
		return;
	}
	Stack* s = initStack(100);
	int remainder;
	while (number > 0) {
		remainder = number % base;
		push(s, remainder);
		number /= base;
	}
	cout << "转换结果为：";
	if (isEmpty(s)) {
		cout << "0";
	}
	else {
		while (!isEmpty(s)) {
			pop(s, remainder);
			cout << remainder;
		}
	}
	cout << endl;
	destroyStack(s);
}
int main() {
	cout << "测试任务一:顺序栈基本操作" << endl;
	Stack* s = initStack(5);
	cout << "栈是否为空（1为空，0不为空）: " << isEmpty(s) << endl;
	push(s, 10);
	push(s, 20);
	push(s, 30);
	DataType topVal;
	getTop(s, topVal);
	cout << "当前栈顶元素: " << topVal << endl;
	DataType popVal;
	pop(s, popVal);
	cout << "出栈元素: " << popVal << endl;
	getTop(s, topVal);
	cout << "出栈后新栈顶元素: " << topVal << endl;
	destroyStack(s);
	cout << "测试任务二:十进制转二进制" << endl;
	int num, base;
	cout << "请输入一个十进制整数: ";
	cin >> num;
	cout << "请输入目标进制(2-9): ";
	cin >> base;
	decimalToBinary(num, base);
	return 0;
}