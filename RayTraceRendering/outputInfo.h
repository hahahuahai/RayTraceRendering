#pragma once
#include <string>
#include <iostream>

//输出信息到控制台
class outputInfo
{
public:
	outputInfo();
	~outputInfo();

	inline static void output(const std::string info){ std::cout << info<< std::endl; }
};

