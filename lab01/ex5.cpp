#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/wait.h> // Include this for wait

void createProccessRecursive(pid_t parent, char currentNode, int cheight, int depth, int degree);

int main(int argc, char *argv[])
{
    // // Check if the correct number of arguments is provided
    // if (argc != 3)
    // {
    //     fprintf(stderr, "Usage: %s <h> <n>\n", argv[0]);
    //     return 1;
    // }

    // // Convert the command-line arguments to integers
    // int h = atoi(argv[1]);
    // int n = atoi(argv[2]);
    int h = 1;
    int n = 2;
    // std::cin >> h;
    // std::cin >> n;

    // Print the values of h and n
    printf("h = %d\n", h);
    printf("n = %d\n", n);

    pid_t mainProccess = getpid();
    std::cout << "main pid: " << mainProccess << std::endl;

    char mainNode = 'A';
    createProccessRecursive(mainProccess, mainNode, 1, h, n);

    return 0;
}

void createProccessRecursive(pid_t parent, char node, int cdepth, int depth, int degree)
{
    // Base case: stop recursion if node exceeds 'Z'
    if (depth < cdepth)
    {
        return;
    }
    char currentNode = node + 1;
    // Create a new node character
    pid_t currentPid = getpid();

    for (int i = 0; i < depth; ++i)
    {
        std::cout << "  ";
    }
    std::cout << "Node: " << currentNode << ", PID: " << currentPid << ", Parent PID: " << parent << std::endl;
    // std::cout << "Parent node: " << node << std::endl
    //           << "Parent pid: " << parent << std::endl
    //           << "Node: " << currentNode << std::endl
    //           << "pid: " << currentPid << std::endl;
    for (int i = 0; i < degree; i++)
    {
        pid_t newP = fork();
        if (newP == 0)
        {
            // This is the child process
            createProccessRecursive(currentPid, currentNode, cdepth + 1, depth, degree);
        }
    }

    // Wait for child processes to finish
    wait(nullptr);
    wait(nullptr);
}
