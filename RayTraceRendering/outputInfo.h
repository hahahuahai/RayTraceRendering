#pragma once
#include <string>
#include <iostream>

//�����Ϣ������̨
class outputInfo
{
public:
	outputInfo();
	~outputInfo();

	inline static void output(const std::string info){ std::cout << info<< std::endl; }
};

