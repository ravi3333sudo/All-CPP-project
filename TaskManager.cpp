#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


struct Task {
    int id;
    string description;
    bool isCompleted;
};


vector<Task> loadTasks(const string &filename) {
    vector<Task> tasks;
    ifstream file(filename);
    if (file.is_open()) {
        Task task;
        while (file >> task.id) {
            file.ignore(); 
            getline(file, task.description);
            file >> task.isCompleted;
            file.ignore(); 
            tasks.push_back(task);
        }
        file.close();
    }
    return tasks;
}


void saveTasks(const vector<Task> &tasks, const string &filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto &task : tasks) {
            file << task.id << endl
                 << task.description << endl
                 << task.isCompleted << endl;
        }
        file.close();
    }
}

void displayTasks(const vector<Task> &tasks) {
    cout << "\n--- Task List ---" << endl;
    for (const auto &task : tasks) {
        cout << "ID: " << task.id
             << " | Description: " << task.description
             << " | Status: " << (task.isCompleted ? "Completed" : "Pending") << endl;
    }
    cout << "-----------------" << endl;
}


void addTask(vector<Task> &tasks) {
    Task task;
    task.id = tasks.empty() ? 1 : tasks.back().id + 1;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, task.description);
    task.isCompleted = false;
    tasks.push_back(task);
    cout << "Task added successfully!\n";
}

void markTaskCompleted(vector<Task> &tasks) {
    int id;
    cout << "Enter the task ID to mark as completed: ";
    cin >> id;
    for (auto &task : tasks) {
        if (task.id == id) {
            task.isCompleted = true;
            cout << "Task marked as completed!\n";
            return;
        }
    }
    cout << "Task not found!\n";
}

// Function to delete a task
void deleteTask(vector<Task> &tasks) {
    int id;
    cout << "Enter the task ID to delete: ";
    cin >> id;
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            cout << "Task deleted successfully!\n";
            return;
        }
    }
    cout << "Task not found!\n";
}

// Main function
int main() {
    const string filename = "tasks.txt";
    vector<Task> tasks = loadTasks(filename);

    int choice;
    do {
        cout << "\n--- Task Manager ---" << endl;
        cout << "1. View Tasks" << endl;
        cout << "2. Add Task" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Delete Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayTasks(tasks);
                break;
            case 2:
                addTask(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                deleteTask(tasks);
                break;
            case 5:
                saveTasks(tasks, filename);
                cout << "Exiting... Tasks saved to file.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
