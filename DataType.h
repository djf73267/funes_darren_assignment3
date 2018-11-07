#ifndef DATATYPE_H
#define DATATYPE_H

class DataType
{
 public:
  DataType();
  void print();
  void initialize(int number);
  int getValue() const;
  ~DataType()throw(); 
 private:
  int value;
};

#endif
