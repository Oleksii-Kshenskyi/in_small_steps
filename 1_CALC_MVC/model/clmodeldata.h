#ifndef CLMODELDATA_H
#define CLMODELDATA_H

class CLModelData
{
  public:
    CLModelData();

    void setFirst(double newFirst);
    double getFirst();
    void setSecond(double newSecond);
    double getSecond();
    void setResult(double newResult);
    double getResult();

  private:
    double first;
    double second;
    double result;
};

#endif // CLMODELDATA_H
