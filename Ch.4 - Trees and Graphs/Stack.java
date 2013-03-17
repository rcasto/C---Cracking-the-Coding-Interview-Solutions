public class Stack<T> {

	private class Node {
		T data;
		Node next;

		Node(T data) {
			this.data = data;
			this.next = null;
		}
	}

	Node head;
	int numItems;

	public Stack() {
		this.head = null;
		this.numItems = 0;
	}

	public boolean push(T data) {
		this.numItems++;
		if (head == null) {
			this.head = new Node(data);
			return true;
		}
		Node node = this.head;
		this.head = new Node(data);
		this.head.next = node;
		return true;
	}

	public T pop() {
		if (this.head == null) {
			throw new Error("Cannot pop from empty stack");
		}
		T data = this.head.data;
		this.head = this.head.next;
		return data;
	}

	public int size() {
		return this.numItems;
	}

	public String toString() {
		StringBuilder builder = new StringBuilder();
		Node node = this.head;
		while (node != null) {
			builder.append(node.data);
			if (node.next != null) {
				builder.append(" -> ");
			}
			node = node.next;
		}
		return builder.toString();
	}

	/*
		Debugging/Testing
	*/
	public static void main(String args[]) {
		Stack<String> stack = new Stack<>();
		stack.push("test1");
		stack.push("test2");
		stack.push("test3");
		System.out.println(stack.toString());
	}
}