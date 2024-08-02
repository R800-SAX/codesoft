#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Task {
      string description;
      bool completed;
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description){
    tasks.push_back({description, false});
    cout<<"Task added"<< description<<endl;
    }

    void viewTasks() const{
    if (tasks.empty()){
        cout<<"No tasks available"<<endl;
        return;
    }
    cout<<"Tasks"<< endl;
    for (size_t i = 0; i < tasks.size(); i++){
        cout<<i+1<<". "<<tasks[i].description;
        if(tasks[i].completed){
            cout<<"Completed";
        }
        cout<<endl;
    }
    }
    void markTaskAsCompleted(size_t index){
    if (index<1 || index>tasks.size()){
        cout<<"Invalid task number"<<endl;
        return;
        }
        tasks[index-1].completed = true;
        cout<<"Task marked as completed"<<tasks[index-1].description<<endl;
    }
void removeTask(size_t index){
 if (index<1|| index > tasks.size()){
    cout<<"Invalid task number"<<endl;
    return;
 }
 cout<<"Task removed"<<tasks[index-1].description<<endl;\
 tasks.erase(tasks.begin() + index-1);

}
};

void displayMenu(){
cout<<"\nTo Do List Manager"<<endl;
cout<<"1. Add Task"<<endl;
cout<<"2. View Task"<<endl;
cout<<"3. Mark Task As Completed"<<endl;
cout<<"4. Remove Task"<<endl;
cout<<"5. Exit"<<endl;
cout<<"Enter Your Choice: ";
}

int main(){
ToDoList todoList;
int choice;
size_t taskIndex;
string taskDescription;

while (true){
    displayMenu();
    cin>>choice;
    cin.ignore();

    switch (choice){
case 1:
    cout<<"Enter task description: ";
    getline(cin,  taskDescription);
    todoList.addTask(taskDescription);
    break;

case 2:
    todoList.viewTasks();
    break;

case 3:
    todoList.viewTasks();
    cout<<"Enter task number to mark as completed:";
    cin>>taskIndex;
    cin.ignore();
    todoList.markTaskAsCompleted(taskIndex);
    break;

case 4:
    todoList.viewTasks();
    cout<<"Enter task number to remove: ";
    cin>>taskIndex;
    cin.ignore();
    todoList.removeTask(taskIndex);
    break;

case 5:
    cout<<"Exiting the program"<<endl;
    return 0;
default:
    cout<<"Invalid Choice. Try again"<<endl;
    }
  }
}
