#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to store a task
struct Task {
    string description;
    bool completed;
};

// Function to display the menu
void showMenu() {
    cout << "\n===== TO-DO LIST MENU =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

// Function to add a new task
void addTask(vector<Task>& tasks) {
    Task newTask;
    cin.ignore(); // clear input buffer
    cout << "Enter the task description: ";
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "✅ Task added successfully!" << endl;
}

// Function to view all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks available!" << endl;
        return;
    }

    cout << "\n===== YOUR TASKS =====" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
    }
}

// Function to mark a task as completed
void markCompleted(vector<Task>& tasks) {
    int index;
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout << "Enter the task number to mark as completed: ";
    cin >> index;

    if (index < 1 || index > (int)tasks.size()) {
        cout << "Invalid task number!" << endl;
    } else {
        tasks[index - 1].completed = true;
        cout << "✅ Task marked as completed!" << endl;
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    int index;
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout << "Enter the task number to remove: ";
    cin >> index;

    if (index < 1 || index > (int)tasks.size()) {
        cout << "Invalid task number!" << endl;
    } else {
        tasks.erase(tasks.begin() + (index - 1));
        cout << "🗑️ Task removed successfully!" << endl;
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    cout << "===============================" << endl;
    cout << "   📝 SIMPLE TO-DO LIST APP" << endl;
    cout << "===============================" << endl;

    while (true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "👋 Exiting... Have a productive day!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
