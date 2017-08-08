#include <stack>

class MyQueue {
public:
	std::stack<int> stack_in;
	std::stack<int> stack_out;
	/** Initialize your data structure here. */
	MyQueue() {
	}

	/** Push element x to the back of queue. */
	void push(int x) {
		stack_in.push(x);
	}

	/** Removes the element from in front of queue and returns that element. */
	int pop() {
		if (stack_out.empty()) {
			while (!stack_in.empty()) {
				stack_out.push(stack_in.top());
				stack_in.pop();
			}
			int temp = stack_out.top();
			stack_out.pop();
			return temp;
		}
		else {
			int temp = stack_out.top();
			stack_out.pop();
			return temp;
		}
	}

	/** Get the front element. */
	int peek() {
		if (stack_out.empty()) {
			while (!stack_in.empty()) {
				stack_out.push(stack_in.top());
				stack_in.pop();
			}
			return stack_out.top();
		}
		else {
			return stack_out.top();
		}
	}

	/** Returns whether the queue is empty. */
	bool empty() {
		return stack_in.empty() &&stack_out.empty();
	}
};

/**
* Your MyQueue object will be instantiated and called as such:
* MyQueue obj = new MyQueue();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.peek();
* bool param_4 = obj.empty();
*/