#include <iostream>
#include <stdlib.h>
#include <memory>

class IOperCalc
{
public:
	IOperCalc() :num1(0),num2(0)
	{

	}
	~IOperCalc() 
	{
		std::cout << "~IOperCalc()" << std::endl;
	}

	void setNum1(double num) 
	{
		this->num1 = num;
	}

	void setNum2(double num)
	{
		this->num2 = num;
	}

	double getNum1() const {
		return this->num1;
	}

	double getNum2() const {
		return this->num2;
	}

	virtual double getResult() 
	{
		return this->num1 * 2 + this->num2 * 2;
	}
private:
	double num1, num2;
};


class OperCalcAdd :public IOperCalc
{
public:
	double getResult()override
	{
		return getNum1() + getNum2();
	}
};

class OperCalcSub :public IOperCalc
{
public:
	double getResult()override
	{
		return getNum1() - getNum2();
	}
};

class OperCalcMul :public IOperCalc
{
public:
	double getResult()override
	{
		return getNum1() * getNum2();
	}
};

class OperCalcDiv :public IOperCalc
{
public:
	double getResult()override
	{
		return getNum1() / getNum2();
	}
};

class OperCalcFactory
{
public:
	static IOperCalc* createOperCalc(char oper) {

		IOperCalc *ipc = nullptr;
		switch (oper)
		{
		case '+':
			ipc = new OperCalcAdd();
			break;
		case '-':
			ipc = new OperCalcSub();
			break;
		case '*':
			ipc = new OperCalcMul();
			break;
		case '/':
			ipc = new OperCalcDiv();
			break;
		default:
			ipc = new IOperCalc();
			break;
		}
		return ipc;
	}
};

void test1() 
{
	double num1, num2;
	char oper;
	std::cout << "please input the num1:";
	std::cin >> num1;
	std::cout << "please input the operate:";
	std::cin >> oper;
	std::cout << "please input the num2:";
	std::cin >> num2;
	std::shared_ptr<IOperCalc> ipc = std::shared_ptr<IOperCalc>(OperCalcFactory::createOperCalc(oper));
	ipc->setNum1(num1);
	ipc->setNum2(num2);
	std::cout << "test1() output:" << ipc->getResult()<<std::endl;
}


int main() 
{
	test1();
	
	system("pause");
	return 0;
}