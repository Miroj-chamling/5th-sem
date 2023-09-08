#include <iostream>
#include <queue>

// Define a struct to represent a customer in the queue
struct Customer {
    int id;
    // Add any other customer attributes you need
};

int main() {
    std::queue<Customer> queue; // Create a queue of customers

    // Simulate adding customers to the queue
    for (int i = 1; i <= 5; ++i) {
        Customer customer;
        customer.id = i;
        // Add other attributes or data as needed
        queue.push(customer);
        std::cout << "Customer " << customer.id << " joined the queue." << std::endl;
    }

    // Simulate processing customers in the queue
    while (!queue.empty()) {
        Customer currentCustomer = queue.front(); // Get the next customer in line
        queue.pop(); // Remove the customer from the queue
        std::cout << "Processing Customer " << currentCustomer.id << std::endl;
        // Perform any required processing or modeling here
    }

    return 0;
}
