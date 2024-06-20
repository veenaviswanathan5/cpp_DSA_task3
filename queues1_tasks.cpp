//Using queues create a task scheduler. Display the number of tasks entered by the user and then display the next one in the queue.

#include <iostream>
#include <queue>
#include <string>

void displayMenu() {
    std::cout << "\nTask Scheduler Menu:" << std::endl;
    std::cout << "1. Add Task" << std::endl;
    std::cout << "2. Display Number of Tasks" << std::endl;
    std::cout << "3. Display and Remove Next Task" << std::endl;
    std::cout << "4. Display All Tasks" << std::endl;
    std::cout << "5. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

void displayAllTasks(const std::queue<std::string>& taskQueue)
{
    std::cout << "Tasks in the queue:" << std::endl;
    std::queue<std::string> tempQueue = taskQueue; //temp queue used so the original queue remains constant

    while (!tempQueue.empty()) {
        std::cout << tempQueue.front() << std::endl; //printing each element in queue
        tempQueue.pop();
    }
}

int main()
{
    std::queue<std::string> taskQueue; // queue is declared with string elements
    int choice;
    std::string task;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter a task: ";
                std::cin.ignore(); // To clear the newline character from the input buffer
                std::getline(std::cin, task);
                taskQueue.push(task);
                std::cout << "Task added: " << task << std::endl;
                break;

            case 2:
                std::cout << "Number of tasks in the queue: " << taskQueue.size() << std::endl;
                break;

            case 3:
                if (!taskQueue.empty()) {
                    std::cout << "Next task: " << taskQueue.front() << std::endl; //the task to be removed
                    taskQueue.pop();
                } else {
                    std::cout << "No tasks in the queue." << std::endl;
                }
                break;

            case 4:
                if (!taskQueue.empty()) {
                    displayAllTasks(taskQueue);
                } else {
                    std::cout << "No tasks in the queue." << std::endl;
                }
                break;

            case 5:
                std::cout << "Exiting Task Scheduler." << std::endl;
                return 0;

            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
    return 0;
}
