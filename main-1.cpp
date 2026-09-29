#include <iostream>
#include <fstream>
#include "BST.h"
#include "DoublyLinkedList.h"
#include "DataStructures.h"
#include "Graph.h"

int main() {
    BST tree;
    DoublyLinkedList<int> list;
    Stack<int> stack;
    Queue<int> queue;
    Graph graph;

    std::string filename = "starter_data.txt";

   
    std::ifstream infile(filename);
    if (!infile) {
        std::cout << filename << " not found. Creating file with starter data...\n";
        std::ofstream outfile(filename);
        outfile << "5 12 7 20 3 15 8 22 10 17";
        outfile.close();
        infile.open(filename); 
    }

    int val;
    while (infile >> val) tree.insert(val);
    infile.close();
    std::cout << "BST created from " << filename << "\n";

    int choice;
    do {
        std::cout << "\n===== Data Structure Explorer Menu =====\n";
        std::cout << "1. BST Operations\n";
        std::cout << "2. Export BST to DLL, Stack, Queue\n";
        std::cout << "3. Build Graph from DLL and BFS\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int bstChoice;
                std::cout << "\n--- BST Menu ---\n";
                std::cout << "1. Insert\n2. Delete\n3. In-order\n4. Pre-order\n5. Post-order\nChoice: ";
                std::cin >> bstChoice;

                if (bstChoice == 1) {
                    std::cout << "Enter value to insert: "; std::cin >> val;
                    tree.insert(val);
                    std::cout << val << " inserted into BST.\n";
                } else if (bstChoice == 2) {
                    std::cout << "Enter value to delete: "; std::cin >> val;
                    tree.remove(val);
                    std::cout << val << " removed from BST (if it existed).\n";
                } else if (bstChoice == 3) tree.inOrder();
                else if (bstChoice == 4) tree.preOrder();
                else if (bstChoice == 5) tree.postOrder();
                else std::cout << "Invalid choice.\n";
                break;
            }

            case 2: {
                list = DoublyLinkedList<int>(); 
                stack = Stack<int>();            
                queue = Queue<int>();            

                tree.exportToDLL(list);

                Node<int>* current = list.getHead();
                while (current) {
                    stack.push(current->data);
                    queue.enqueue(current->data);
                    current = current->next;
                }

                std::cout << "BST exported to DLL, Stack, and Queue.\n";
                std::cout << "Doubly Linked List (in-order): ";
                current = list.getHead();
                while (current) { std::cout << current->data << " "; current = current->next; }
                std::cout << std::endl;
                break;
            }

            case 3: {
                if (list.isEmpty()) {
                    std::cout << "Error: DLL is empty. Export BST first.\n";
                    break;
                }
                graph.buildFromDLL(list);
                graph.printAdjacency();
                std::cout << "Enter start node for BFS: ";
                std::cin >> val;
                graph.BFS(val);
                break;
            }

            case 4:
                std::cout << "Exiting program.\n";
                break;

            default:
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}





