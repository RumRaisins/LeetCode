#include <queue>

class MyStack {
public:
	std::queue<int> queue_in;
	std::queue<int> queue_out;

	/** Initialize your data structure here. */
	MyStack() {
		

	}

	/** Push element x onto stack. */
	void push(int x) {
		if (empty()) {
			queue_in.push(x);
		}
		else if(queue_in.empty() && !queue_out.empty()) {
			queue_in.push(x);
			while (!queue_out.empty()) {
				queue_in.push(queue_out.front());
				queue_out.pop();
			}
		}
		else if (!queue_in.empty() && queue_out.empty()) {
			queue_out.push(x);
			while (!queue_in.empty()) {
				queue_out.push(queue_in.front());
				queue_in.pop();
			}
		}
	}

	/** Removes the element on top of the stack and returns that element. */
	int pop() {
		if (queue_out.empty()) {
			int temp = queue_in.front();
			queue_in.pop();
			return temp;
		}
		if (queue_in.empty()) {
			int temp = queue_out.front();
			queue_out.pop();
			return temp;
		}
	}

	/** Get the top element. */
	int top() {
		if (queue_out.empty()) {
			return queue_in.front();
		}
		else {
			return queue_out.front();
		}
	}

	/** Returns whether the stack is empty. */
	bool empty() {
		return queue_in.empty() && queue_out.empty();
	}
};

/**
* Your MyStack object will be instantiated and called as such:
* MyStack obj = new MyStack();
* obj.push(x);
* int param_2 = obj.pop();
* int param_3 = obj.top();
* bool param_4 = obj.empty();
*/