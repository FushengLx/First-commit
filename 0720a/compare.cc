#include<iostream>
#include<string>

int main()
{
  std::string m_citizen_nu;
  uint16_t age=0;
  std::cin >> age>>m_citizen_nu;
  int citizen_birth=0;
  int b=1000;
  for(int a=6;a<10;++a)
  {
    int s=m_citizen_nu[a]-'0';
    citizen_birth +=s*b;
    b/=10;
  }
  if((2024-citizen_birth)!=age)
  {
    std::cout << "error"<<std::endl;
  }
  else
  {
    std::cout << "right"<<std::endl;
  }
}
