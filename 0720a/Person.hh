#include<string>
#include<vector>
#include<memory>
class Person{
public:
  Person();
  Person(uint32_t age, std::string name, std::string citizen_id);

  // Person(std::string name, std::string citizen_id);

  
  void PrintInformation();
  void HappyBirthday();

  std::string GetName();

  void ChangeName(std::string name);
  void SetCitizenId(std::string citizen_id);
  
  uint32_t GetAge();
  uint32_t GetAge(uint32_t year);
  bool IfBorn(uint32_t year);
  
private:
  uint32_t m_age; 
  std::string m_name;
  std::string m_citizen_id;
  bool m_is_valid;
};


class Student: public Person{
public:

  Student(std::string name, uint32_t age, std::string citizen_id, uint64_t shool_id,
	  uint64_t bank_id, uint16_t grade, std::string major, bool isDoc
	  );

  void PrintInformation();

    
private:

  uint64_t m_school_id;
  uint64_t m_bank_id;
  uint16_t m_grade;
  std::string m_major;
  bool m_is_doc;

};


class Teacher: public Person{
public:
  //friend void Student::PrintInformation();
  Teacher(std::string name, uint32_t age, std::string citizen_id, uint64_t work_id);

  ~Teacher();

  
  void CreateMasterStudent(std::string name, uint32_t age, std::string citizen_id, uint64_t m_shool_id,
			   uint64_t bank_id, uint16_t grade, std::string major);

  void CreateAfgraturateStudent(std::string name, uint32_t age, std::string citizen_id, 
		   uint64_t m_shool_id,uint64_t bank_id, uint16_t grade, std::string major);

  void AddStudent(const Student& si);
  
  void ShowStudent();
private:
  uint64_t m_work_id;
  std::vector<Student*> m_student_master_vec;
  std::vector<Student*> m_student_afgraturate_vec;
  std::vector<std::shared_ptr<Student>> m_student_vec;

};


