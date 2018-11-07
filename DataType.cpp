
#include "DataType.h"
#include <string>
#include <iostream>
DataType::DataType()
{

}
void DataType::initialize(int number)
{
  value=number;
}
int DataType::getValue() const
{
  return value;
}
void DataType::print()
{
  std::cout<<value<<" ";
}
DataType::~DataType() throw()
{

  
}
