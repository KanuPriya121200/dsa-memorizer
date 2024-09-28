#include <iostream>
#include <cstring>
using namespace std;
// Base class for all personnel
class Person {
protected:
    char name[50];
    char type[60];
    char email[50];
    char phone[20];
    char room[30];
    
public:
    Person(const char* n, const char* t, const char* e, const char* p, const char* r) {
        strcpy(name, n);
        strcpy(type, t);
        strcpy(email, e);
        strcpy(phone, p);
        strcpy(room, r);
    }

    virtual ~Person() {}  // Add a virtual destructor
    
    virtual void displayInfo() const {
        std::cout << "Name: " << name << "\n"
                  << "Type:" << type << "\n"
                  << "Email: " << email << "\n"
                  << "Phone: " << phone << "\n"
                  << "Room: " << room << std::endl;
    }

    const char* getName() const {
        return name;
    }
};

// Derived class for the registrar
class Registrar : public Person {
public:
    Registrar(const char* n, const char* t, const char* e, const char* p, const char* r)
        : Person(n, t, e, p, r) {}
    
    void displayInfo() const {
        std::cout << "Position: Registrar\n";
        Person::displayInfo();
    }
};

// Derived class for Dean positions
class Dean : public Person {
public:
    Dean(const char* n, const char*t, const char* e, const char* p, const char* r)
        : Person(n, t, e, p, r) {}
    
    void displayInfo() const {
        std::cout << "Position: Dean\n";
        Person::displayInfo();
    }
};

// Derived class for Associate Dean positions
class AssociateDean : public Person {
public:
    AssociateDean(const char* n, const char *t, const char* e, const char* p, const char* r)
        : Person(n, t, e, p, r) {}
    
    void displayInfo() const {
        std::cout << "Position: Associate Dean\n";
        Person::displayInfo();
    }
};

// Derived class for Administrative Officer positions
class AdminOfficer : public Person {
public:
    AdminOfficer(const char* n, const char *t, const char* e, const char* p, const char* r)
        : Person(n, t, e, p, r) {}
    
    void displayInfo() const {
        std::cout << "Position: Administrative Officer\n";
        Person::displayInfo();
    }
};

// Main function to handle searching and displaying information
int main() {
    // Manually creating the personnel objects
    Person* people[9];
    people[0] = new Registrar("Dr. Deepika Bhaskar", "Head of entire administrative structure", "deepika@iiitd.ac.in", "+91-11-26907419", "B-204 (Academic Block)");
    people[1] = new Dean("Vivek Ashok Bohara","Dean of IRD", "dird@iiitd.ac.in", "+91-11-26907454", "Room No. XYZ");
    people[2] = new Dean("Sumit J Darak","Dean of Academic Affairs", "doaa@iiitd.ac.in", "+91-11-26907427", "Room No. ABC");
    people[3] = new Dean("Shobha Sundar Ram","Dean of Student Affairs", "dosa@iiitd.ac.in", "+91-11-26907460", "Room No. PQR");
    people[4] = new AssociateDean("Debarka Sengupta", "Associate Dean IRD", "adird@iiitd.ac.in", "+91-11-26907446", "Room No. EFG");
    people[5] = new AdminOfficer("Ajay Kumar", "Admin Officer of Store and Purchase", "ajay@iiitd.ac.in", "011 26907 561", "Room No. A-103(2) (Academic Block)");
    people[6] = new AdminOfficer("Anshu Dureja","Deputy Admin Officer(Academics)", "anshu@iiitd.ac.in", "011 26907 507", "Room No. B-208 (Academic Block))");
    people[7] = new AdminOfficer("Dr. Ravi Bhasin", "Admin Officer(Student Affairs)", "ravi@iiitd.ac.in", "011 26907 504", "Room No. A-207-1 (Academic Block)");
    people[8] = new AdminOfficer("Rajendra Singh","Library Officer(SG)", "rajendra@iiitd.ac.in", "011 26907 510","Library Block");
      
  
    char searchName[50];
    std::cout << "Enter the name of the person to search: ";
    std::cin.getline(searchName, 50);

    bool found = false;
    for (int i = 0; i < 9; ++i) {
        if (strcmp(people[i]->getName(), searchName) == 0) {
            people[i]->displayInfo();
            found = true;
            break;
        }
    }

    if (!found) {
        std::cout << "Person not found." << std::endl;
    }

    // Clean up
    for (int i = 0; i < 9; ++i) {
        delete people[i];
    }

    return 0;
}