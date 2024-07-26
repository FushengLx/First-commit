#include<fstream>
#include"Person.hh"
#include<sstream>
#include<iostream>

int main(int argc , char *argv[]){
  
  Teacher t_ly("ly", 37, "111111111111111110",123456789);
  
  if(argc==2){  
    std::ifstream file(argv[1]);

    if(!file.is_open()){
      std::cerr <<"This file can't open"<<std::endl;
    }

    else{
    uint16_t num16,count=0;
    uint32_t num32;
    uint64_t num64_1,num64_2;
    std::string s_1,s_2,s_3;
    bool num2;
    std::string line;
    while(std::getline(file,line)){

      if(count!=0){
        std::istringstream iss(line);
        iss>>s_1>>num32>>s_2>>num64_1>>num64_2>>num16>>s_3>>num2;
        Student s(s_1,num32,s_2,num64_1,num64_2,num16,s_3,num2);
        t_ly.AddStudent(s);
      }
      count++;
    }
    t_ly.ShowStudent();
    }
 }
   else{
     std::cout<<"You error"<<std::endl;
     return 1;
   }
 return 0;
}
