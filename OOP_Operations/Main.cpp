#include "OOP_Operations.h"
#include "Header.h"

int main()
{
    std::vector<Person> people;
    Person p1("Tuan", "123", "abc", new Address());
    p1.updateInfo("Thinh", "456", "def");
    people.push_back(p1);

    Student p2("Tuan", "123", "abc", new Address("Nguyen Van Cu", "Ho Chi Minh", "Viet Nam", "100000"));
    people.push_back(p2);

    Person p3("Tuan", "123", "abc", new Address("Mau Than", "Can Tho", "Viet Nam", "800000"));
    p3.updateInfo("Thanh", "111", "kfc");
    people.push_back(p3);

    std::cout << "------------- DATABASE -----------" << std::endl;
    for (Person person : people)
    {
        std::cout << "\nJob: " << person.getJob() << std::endl;
        person.printInfo();
        person.addresses->printAddress();
        std::cout << "\n----------------------------------" << std::endl;
    }

    //updateAddress
    //people[0].addresses->updateAddress("Nguyen Van Cu", "Ho Chi Minh", "Viet Nam", "100000");
    people[1].addresses->updateAddress("Mau Than", "Can Tho", "Viet Nam", "800000");
    people[2].addresses->updateAddress("Vo Van Kiet", "Ha Noi", "Viet Nam", "200000");

    cout << "\n--------- Update Address ---------" << endl;

    for (Person person : people)
    {
        std::cout << "\nJob: " << person.getJob() << std::endl;
        person.printInfo();
        person.addresses->printAddress();
        std::cout << "\n----------------------------------" << std::endl;
    }

    return 0;
}