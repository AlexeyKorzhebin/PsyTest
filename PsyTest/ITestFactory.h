#pragma once
#include "Test.h"

struct ITestFactory
{
    virtual std::shared_ptr<TestModel> Create(std::wstring param) = 0;
};

