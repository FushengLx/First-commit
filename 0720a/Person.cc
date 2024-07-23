#include"Person.hh"

#include<iostream>

#include<memory>

Person::Person():m_age(0),m_name("default"),m_citizen_id("000000000000000"), m_is_valid(false){
  
};


Person::Person(uint32_t age, std::string name, std::string citizen_id):
  m_age(age),m_name(name),m_citizen_id(citizen_id),m_is_valid(true)
{

  if(m_citizen_id.size() != 18){
    m_is_valid=false;
  }
  uint16_t temp_citizen_bir=0;
  uint16_t temp_count=1000;
  for(uint8_t a=6 ; a<10 ; ++a){
    int s=m_citizen_id[a]-'0';
    temp_citizen_bir +=s*temp_count;
    temp_count /= 10;
  }
  if((2024-temp_citizen_bir)!=m_age){
    m_is_valid=false;
  }
};



void Person::PrintInformation(){

  std::cout<<"==========Person information:============"<<std::endl;
  std::cout<<"name:       "<<m_name<<std::endl;
  std::cout<<"age:        "<<m_age<<std::endl;
  std::cout<<"citizen_id: "<<m_citizen_id<<std::endl;
  if(!m_is_valid){
    std::cout<<"Warning!  Fake Citizen_ID"<<std::endl;
  }
  std::cout<<"=========================================="<<std::endl;
}


void Person::HappyBirthday(){
  m_age++;
}

std::string Person::GetName(){
  return m_name;
}

uint32_t Person::GetAge(){
  return m_age;

}

uint32_t Person::GetAge(uint32_t year){

  uint32_t age_of_year = m_age+(year-2024);
  return age_of_year;
}

bool Person::IfBorn(uint32_t year){
  uint32_t year_of_born = 2024-m_age;
  
  if(year>=year_of_born){
    return true;
  }
  return false;
}

void Person::ChangeName(std::string name){
  m_name = name;
}

void Person::SetCitizenId(std::string citizen_id){

  m_citizen_id = citizen_id;
  //TODO: check if citizen_id is valid;
  //m_is_valid = true;
  //TODO: set age according to id
}




Student::Student(std::string name, uint32_t age, std::string citizen_id, uint64_t school_id,
		 uint64_t bank_id, uint16_t grade, std::string major, bool isDoc):
  Person(age, name, citizen_id), m_school_id(school_id), m_bank_id(bank_id), m_grade(grade),
  m_major(major), m_is_doc(isDoc){
  
  //TODO: check
  
}



void Student::PrintInformation(){

  std::cout<<"==========Student information:============"<<std::endl;
  std::cout<<"name:       "<<GetName()<<std::endl;
  std::cout<<"grade:      "<<m_grade<<std::endl;
  std::cout<<"school_id:  "<<m_school_id<<std::endl;
  std::cout<<"=========================================="<<std::endl;

  Person::PrintInformation();
}


Teacher::Teacher(std::string name, uint32_t age, std::string citizen_id, uint64_t work_id):
  Person(age,name,citizen_id), m_work_id(work_id){
  
}


void Teacher::CreateMasterStudent(std::string name, uint32_t age, std::string citizen_id,
				uint64_t school_id,
				uint64_t bank_id, uint16_t grade, std::string major){

  Student* p_aStudent = new Student(name, age, citizen_id, school_id, bank_id, grade, major, false);

  m_student_master_vec.push_back(p_aStudent);
}
void Teacher::CreateAfgraturateStudent(std::string name, uint32_t age, std::string citizen_id,
                   uint64_t school_id,uint64_t bank_id, uint16_t grade, std::string major){


  Student* p1_aStudent = new Student(name, age, citizen_id, school_id, bank_id, grade, major, false);
  
  m_student_afgraturate_vec.push_back(p1_aStudent);
}
void Teacher::AddStudent(const Student &si){
  
  std::shared_ptr<Student> p2_aStudent=std::make_shared<Student>(si);

  m_student_vec.push_back(p2_aStudent);
  
}
void Teacher::ShowStudent(){
  if(m_student_master_vec.empty()){
    std::cout<<"The master is empty"<<std::endl;
  }
  else{
    for(auto i:m_student_master_vec){
      (*i).PrintInformation();
    }
  }
  if(m_student_afgraturate_vec.empty()){
    std::cout<<"The aftergra is empty"<<std::endl; 
  }
  else{
    for(auto i:m_student_afgraturate_vec){
      (*i).PrintInformation();
    }
  }
  for(auto i:m_student_vec){
    i->PrintInformation();
  }
}

Teacher::~Teacher(){

  for(std::vector<Student*>::iterator it=m_student_master_vec.begin();
      it!=m_student_master_vec.end(); it++){
    delete *it;
  }
  for(auto it1:m_student_afgraturate_vec){
    delete it1;
  }
}
