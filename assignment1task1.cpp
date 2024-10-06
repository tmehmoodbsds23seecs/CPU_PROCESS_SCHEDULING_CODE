//Tahir Mehmood
//458593
#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string processid;
    int executiontime;
    int remainingtime;
    Node *next;

    Node(string id, int exec_time)
    {
        processid = id;
        executiontime = exec_time;
        remainingtime = exec_time;
        next = nullptr;
    }
};

class Processing
{
private:
    Node *head;
    int time;

public:
    Processing(int quanta)
    {
        head = nullptr;
        time = quanta;
    }

    // Add a new process to the circular linked list
    void add(string id, int exec_time)
    {
        Node *new_process = new Node(id, exec_time);
        if (!head)
        {
            head = new_process;
            head->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = new_process;
            new_process->next = head;
        }
    }

    void remove(Node *&process)
    {
        if (process == head && process->next == head)
        { // Only one node left
            delete process;
            head = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next != process)
        {
            temp = temp->next;
        }
        temp->next = process->next;
        if (process == head)
        {
            head = process->next;
        }
        delete process;
        process = temp->next;
    }

    void runLoop()
    {
        if (!head)
        {
            cout << "No processes left to run." << endl;
            return;
        }

        Node *current = head;
        do
        {
            if (current->remainingtime > 0)
            {
                int time_assigned = min(time, current->remainingtime);
                current->remainingtime -= time_assigned;

                cout << current->processid << " (Remaining: " << current->remainingtime << ") ";
                if (current->remainingtime == 0)
                {
                    cout << "Completes" << endl;
                    Node *temp = current;
                    current = current->next;
                    remove(temp);
                }
                else
                {
                    current = current->next;
                }
            }
            else
            {
                current = current->next;
            }
        } while (current != head);

        cout << endl;
    }

    // Check if there are any remaining processes
    bool hasProcesses()
    {
        return head != nullptr;
    }

    // Display the state of the processes
    void display()
    {
        if (!head)
        {
            cout << "No processes in the list." << endl;
            return;
        }

        Node *temp = head;
        do
        {
            cout << temp->processid << " (Remaining: " << temp->remainingtime << ") ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main()
{

    Processing object(3);

    // Add initial processes 
    object.add("P1", 10);
    object.add("P2", 5);
    object.add("P3", 8);

    cout << "Initial Processes: ";
    object.display();

    // Run first cycle
    cout << "Cycle 1: ";
    object.runLoop();

    // Run second cycle
    cout << "Cycle 2: ";
    object.runLoop();

    // Simulate a new process arriving after cycle 2
    cout << "New process arrives: P4 (Remaining: 9)" << endl;
    object.add("P4", 9);

    // Run third cycle
    cout << "Cycle 3: ";
    object.runLoop();

    // Continue running cycles until all processes are completed
    int cycle = 4;
    while (object.hasProcesses())
    {
        cout << "Cycle " << cycle << ": ";
        object.runLoop();
        cycle++;
    }

    return 0;
}