#pragma once
#include "ITestFactory.h"
#include <string>
#include "Test.h"
#include <memory>
class FileTestFactory :
    public ITestFactory
{
    std::shared_ptr<TestModel> Load(std::wistream& is);
public:
    virtual std::shared_ptr<TestModel> Create(std::wstring param);
};

