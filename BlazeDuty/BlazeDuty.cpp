// BlazeDuty.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <list>
#include <random>
#include <queue>

std::vector<int> primes = {2, 3, 5, 7, 11, 13, 15, 17, 19, 23, 29};
std::random_device rd;
std::mt19937 eng(rd());
std::uniform_int_distribution<> distr(0, primes.size() - 1);

class Task
{
private:
    int id;
    std::string name;
    float priority;
    bool done;

public:
    Task() : id(0), name(""), priority(0.0), done(false) {}
    ~Task() = default;

    bool create_task(std::string new_name, float new_priority)
    {
        int index = rand() % primes.size();//this how i can make id's more secure
        id = pow(2,index) - 1; //this is mersenn theory to prove that 2 at power p-1 is prime, while p is prime
        name = new_name;
        priority = new_priority;
        return true;
    }

    int getID() { return id; }
    std::string getName() { return name; }
    float getPriority() { return priority; }
    bool isDone() const { return done; }



    void taskDone(bool val) { done = true; }

};

int main()
{
    std::string version = "v0.0.1";
    std::list<Task> tasks;
    std::list<Task>::iterator it;
    std::string input_name;
    int input_id;
    float input_imp;
    float input_time;

    srand(time(NULL));//default seed = brand new seed for the random int every time we open the program

    tasks.clear();

    //Task test;
    //test.create_task("trb sa termin cacatul asta", 0.8);
    //tasks.push_back(test);

    

    while (1)
    {
        char input_option;
        system("cls");
        std::cout << "Welcome to BlazeDuty " << version << " !" << std::endl;
        std::cout << "-----------------------------------------------" << std::endl;
        std::cout << "Here are the uncompleted tasks. We will recommend for you to finish them in this order: " << std::endl;
            for (it = tasks.begin(); it != tasks.end(); it++)
            {
                std::string completed = it->isDone() ? "Done" : "Not Done";

                std::cout << it->getID() << " | " << it->getName() << " | " << it->getPriority() << it->isDone() << " | " << completed << " | " << std::endl;
            }

            if (tasks.empty())
            {
                std::cout << "No tasks yet. Enjoy your netflix show!" << std::endl;
            }

            std::cout << "[a]dd a new task" << std::endl;
            std::cout << "[c]omplete task" << std::endl;
            std::cout << "[e]xit program" << std::endl;

            std::cout << "choice: ";

            std::cin >> input_option;
            if (input_option == 'e')
            {
                std::cout << "Good work for the day!" << std::endl;
                break;
            }
            else if (input_option == 'a')
            {
                std::cout << "Add a new task: ";
                std::cin >> input_name;
                std::cout << std::endl << "You should know how important this task is for you. From 1 to 10, 1 means most important and 10 means important." << std::endl;
                std::cout << std::endl << "How [i]mportant do you think the task is?: ";
                std::cin >> input_imp;
                std::cout << std::endl << "Tell me the estimated [t]ime, in hours: ";
                std::cin >> input_time;
                float rez_prirority; // priority means imp*time, if the rez is lower->priority is higher
                rez_prirority = input_imp * input_time;
                Task new_task;
                new_task.create_task(input_name, rez_prirority);
                tasks.push_back(new_task);

            }
            else if (input_option == 'c')
            {
                std::cout << "Complete the first task" << std::endl;
                std::cin >> input_id;
                for (it = tasks.begin(); it != tasks.end(); it++)
                {
                    if (input_id == it->getID())
                    {
                        it->taskDone(true);
                        break;
                    }
                }
            }
    }
}
